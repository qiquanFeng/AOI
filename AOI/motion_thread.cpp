#include "motion_thread.h"
#include "aoi.h"
#include "AOI.h"
#define UPDATESTATUS(status) emit sig_setStatus(status);if(m_bES) return
using namespace rapidjson;

Motion_thread::Motion_thread(QObject *parent)
	: QThread(nullptr), m_CardNum(0), m_bES(false), m_bReceived(false), m_HTTP_Interface(new HTTP_Interface),\
	mutex1(new QMutex), m_parent(parent), m_bAutoMode(false), m_bSuspended(false), m_bResetMode(false)
{
	configFilePath[0] = QString("DMC3400.ini");
	configFilePath[1] = QString("DMC3800.ini");
	connect(this, SIGNAL(sig_logOutput(QString, QColor)), parent, SLOT(slot_outputLog(QString, QColor)));
	connect(this, SIGNAL(sig_statusChange(int,int, bool,int)), parent, SLOT(slot_IOChangeInfo(int, int,bool,int)));
	connect(this, &Motion_thread::sig_axisChange,(AOI*)parent,&AOI::sig_axisChange);
	connect(this, SIGNAL(sig_updateImage(QString)), parent, SLOT(slot_updateImage(QString)),Qt::DirectConnection);
	connect(this, SIGNAL(sig_setStatus(int)), parent, SLOT(slot_setStatus(int)));

	connect(this, &Motion_thread::sig_updateResult, (AOI*)parent, &AOI::sig_updateResult);

	connect(this, SIGNAL(sig_testResult(int,int,int)), parent, SLOT(slot_setCameraResult(int,int,int)));
	motion_Init();
}

Motion_thread::~Motion_thread()
{

}
void Motion_thread::run() {
	while (1&& m_CardNum==2) {

		DWORD ss=dmc_axis_io_status(1, 2);
		short inStatus[2][16];
		short outStatus[2][16];

		for (int card = 0; card < 2; card++)
		{
			for (int axis = 0; axis < 16;axis++) {
				inStatus[card][axis]=dmc_read_inbit(card,axis);
				outStatus[card][axis] = dmc_read_outbit(card, axis);
				emit sig_statusChange(axis, card, true, inStatus[card][axis]);
				emit sig_statusChange(axis, card, false, outStatus[card][axis]);
			}
		}
		
		for (int card = 0; card < 2; card++) {
			for (int axis = 0; axis < 3; axis++) {
				long pos=dmc_get_position(card,axis);

				emit sig_axisChange(card,axis,pos);
			}
		}

		if (inStatus[1][11]) {
			if (!m_bResetMode) {
				m_bES = true;
				dmc_stop(0, 0, 1);
				dmc_stop(0, 1, 1);
				dmc_stop(0, 2, 1);
				dmc_stop(1, 0, 1);
				dmc_stop(1, 1, 1);
				dmc_stop(1, 2, 1);
				emit sig_setStatus(stop3);
			}
		}

		if (!inStatus[1][8]) {
			m_bPannelCheck = true;
		}

		if (inStatus[0][5]) {
			m_bES = true;
			emit sig_setStatus(stop2);
			dmc_stop(0, 0, 1);
			dmc_stop(0, 1, 1);
			dmc_stop(0, 2, 1);
			dmc_stop(1, 0, 1);
			dmc_stop(1, 1, 1);
			dmc_stop(1, 2, 1);
		}
		msleep(100);
	}
}

void Motion_thread::slot_sendChangeIO(int iIoNumber, int iCard) {
	int i = iIoNumber;
	i = iCard;
	short status = dmc_read_outbit(iCard, iIoNumber);
	dmc_write_outbit(iCard, iIoNumber, !status);
}
void Motion_thread::slot_resetAxis() {
	srt_config config = ((AOI*)m_parent)->m_config;
	emit sig_logOutput(tr("reset..."));
	short status=0;
	while (!status) {
		if (!dmc_read_inbit(1, 4) || !dmc_read_inbit(1, 8)) {
			status = 0;
			if (!dmc_read_inbit(1, 8)) {
				emit sig_setStatus(abnormalPannel_unLoad);
			}
			else {
				emit sig_setStatus(abnormalPannel_Load);
			}
			
			return ;
		}
		else{
			status = 1;
		}
	}
	
	slot_writeOutIO(0, 3, 0, true);
	slot_writeOutIO(0, 1, 0, true);
	slot_writeOutIO(1, 5, 1, true);
	slot_writeOutIO(1, 6, 1, true);
	slot_writeOutIO(1, 7, 1, true);
	slot_writeOutIO(0, 2, 1, true);
	slot_writeOutIO(1, 4, 1, true);
	
	axis_move(1, 2, config.lORG_Speed_LoadX, 0, 0, 1,true,true);
	axis_move(0, 0, config.lORG_Speed_TestX, 1, 0, 1, true, true);
	axis_move(0, 1, config.lORG_Speed_TestY, 0, 0, 1, false, true);
	axis_move(0, 2, config.lORG_Speed_TestX2, 0, 0, 1, false, true);

	axis_move(1, 1, config.lORG_Speed_unLoadZ, 0, 0, 1, false, true);
	axis_move(1, 0, config.lORG_Speed_LoadZ, 1, 0, 1, false, true);

	slot_writeOutIO(0, 0, 1, true);

	status=0;

	while(!status&& !m_bES){
		int iresult = 1;
		for (int card = 0; card < 2; card++) {
			for (int axis = 0; axis < 3; axis++)
			{
				WORD status = dmc_axis_io_status(card, axis);
				if (card == 1 && axis == 2) {
					if ((dmc_axis_io_status(card, axis) & 0x10)) { iresult = 0; }

				}
				else {
					if (!(dmc_axis_io_status(card, axis) & 0x10)) { iresult = 0; }
				}
				
			}
		}
		status = iresult;
	}

	do {
		status = 1;
		if (dmc_check_done(1, 0) == 0 || dmc_check_done(1, 1) == 0) {
			status = 0;
		}
	} while (!status);

	if (!status) {
		m_bSuspended = false;
		return;
	}

	for (int card = 0; card < 2; card++) {
		for (int axis = 0; axis < 3; axis++)
		{
			dmc_set_position(card, axis, 0);
		}
	}

	if (!m_bES) {
		emit sig_logOutput(tr("reset success!"), QColor(0, 255, 0));
		emit sig_setStatus(success);
	}
	else {
		emit sig_logOutput(tr("Emergency Stop!"), QColor(255, 0, 0));
		emit sig_setStatus(stop);
	}
		
	m_bES = false;
	m_bSuspended = false;
	m_bResetMode = false;
}
int Motion_thread::slot_writeOutIO(WORD card, WORD bitNo, WORD status,bool bReset) {
	if (!bReset) {
		while (m_bSuspended) {
			msleep(200);
		}

		if (m_bES) { return -1; }
	}

	dmc_write_outbit(card, bitNo, status);
	return 0;
}
int Motion_thread::motion_Init() {
	emit sig_logOutput(QString::fromLocal8Bit("���ڳ�ʼ��"));
	m_CardNum = dmc_board_init();
	if (m_CardNum == 0)
	{
		emit sig_logOutput(QString::fromLocal8Bit("û���ҵ����ƿ�"));
		return -1;
	}
	if (m_CardNum != 2)
	{
		emit sig_logOutput(QString::fromLocal8Bit("���ƿ������쳣"));
		return -1;
	}

	for (int card = 0; card < m_CardNum; card++)
	{
		if (int errorCode = dmc_download_configfile(card, configFilePath[card].toLatin1().data()))
		{
			emit sig_logOutput(QString::fromLocal8Bit("���ƿ���%1�����ļ�����ʧ�ܣ�������룺%2").arg(card).arg(errorCode));
			return -1;
		}
		for (int axis = 0; axis < 8; axis++)
			if (dmc_write_sevon_pin(card, axis, 0))
			{
				emit sig_logOutput(QString::fromLocal8Bit("��%1��%2���ŷ�ʹ�ܶ˿��������ʧ��").arg(card).arg(axis));
				return -1;
			}
	}
	

	//**           �����ʼ��  ****************************

	QString strSend("{\"init\":\"1\"}");
	emit sig_logOutput(tr("sent init post"));
	m_HTTP_Interface->sendPost(strSend.toLatin1(), QUrl("http://127.0.0.1:6789/init"), 6789);
	

	
	th1 = new Motion_thread1(this);
	connect(m_HTTP_Interface->m_pManager, SIGNAL(finished(QNetworkReply *)), th1, SLOT(onReply(QNetworkReply *)));

	strSend=QString("{\"detec_en\":\"0\"}");
	m_HTTP_Interface->sendPost(strSend.toUtf8(), QUrl("http://127.0.0.1:6789/settings"), 6789);

	return m_CardNum;
}
void Motion_thread::slot_load() {
	srt_config config = ((AOI*)m_parent)->m_config;
	UPDATESTATUS(running);

	slot_writeOutIO(0, 0, 1, true);
	slot_writeOutIO(0, 1, 0, true);
	slot_writeOutIO(1, 5, 1, true);
	slot_writeOutIO(1, 6, 1, true);
	slot_writeOutIO(1, 7, 1, true);
	slot_writeOutIO(0, 2, 1, true);
	slot_writeOutIO(1, 4, 1, true);

	axis_move(0, 1, config.lLoadSpeed_Y, 1, config.lLoadPos_Y, 0, false);
	axis_move(0, 0, config.lORG_Speed_TestX, 1, 0, 1, false);
	axis_move(0, 2, config.lORG_Speed_TestX2, 0, 0, 1, false);
	axis_move(1, 1, config.lunLoadSpeed_Z, 1, config.lunLoadPos_Z, 0, false);
	axis_move(1, 2, config.lORG_Speed_LoadX, 0, 0, 1, true);
	axis_move(1, 0, config.lLoadSpeed_Z, 1, config.lLoadPos_Z, 0, true);

	m_bAutoMode = true;

	UPDATESTATUS(lotNumber);
	UPDATESTATUS(lotNumber);
}
void Motion_thread::slot_unload() {
	emit sig_logOutput("start unload...");
	dmc_write_outbit(0, 1, 0);
	dmc_write_outbit(0, 2, 1);
	dmc_write_outbit(0, 0, 1);

	axis_move(0, 2, 2000, 0, 0, 1, false);
	axis_move(0, 1, 20000, 1, 88600, 0, false);
	axis_move(0, 0, 40000, 1, -340000);
	msleep(300);
	dmc_write_outbit(0, 0, 0);
	axis_move(0, 2, 20000, 1, -8000, 0, true);
	dmc_write_outbit(0, 0, 1);
	axis_move(0, 2, 2000, 0, 0, 1, true);
	dmc_write_outbit(0, 0, 0);
	axis_move(0, 2, 1000, 1, -10500, 0, true);
}
void Motion_thread::slot_test() {
	int iresult = 0;
	emit sig_logOutput("start test... ");
	short status = 0;
	emit sig_logOutput(tr("check box exists..."),QColor());
	do {
		msleep(10);
		status = dmc_read_inbit(1, 9);
	} while (!status);

	emit sig_logOutput(tr("check box success!"));
	axis_move(1, 2, 20000, 1, -140000);

	dmc_write_outbit(0, 1, 0);
	dmc_write_outbit(0, 2, 1);

	status=dmc_read_inbit(1, 8);
	if (!status) {
		axis_move(1, 2, 20000, 0, 0, 1,false);
	}
	else {
		axis_move(1, 2, 20000, 0, 0, 1);
		axis_move(1, 0, 20000, 0, -60000);
		axis_move(1, 2, 20000, 1, -90000);
		axis_move(1, 2, 20000, 0, 0, 1, false);
	}

	dmc_write_outbit(0, 0, 0);
	axis_move(0, 2, 2000, 1, -9000);
	dmc_write_outbit(0, 0, 1);
	axis_move(0, 2, 2000, 0, 0, 1);
	dmc_write_outbit(0, 0, 0);

	axis_move(0, 2, 1000, 0, -5000,0,false);
	do {
		status = dmc_read_inbit(0, 2);
		if (dmc_check_done(0, 2)) {
			emit sig_logOutput(QString::fromLocal8Bit("�ذ����ϼ��ʧ�ܣ�"));
			iresult = -1;
			break;
		}
	} while (status);
	
	dmc_stop(0, 2, 1);
	msleep(500);
	dmc_write_outbit(0, 1, 1);
	dmc_write_outbit(0, 2, 0);
	dmc_write_outbit(0, 0, 1);

	if (iresult) {
		axis_move(0, 1, 20000, 1, 88600, 0, false);
		axis_move(0, 0, 20000, 1, 0, 1, true);
		axis_move(0, 2, 1000, 0, 0, 1, true);
		return;
	}
	//slot_MatrixMove(3, 11, 12.5, 19.5);
	
}
void Motion_thread::slot_auto(QStringList listBox) {
	srt_config config = ((AOI*)m_parent)->m_config;
	int loopCount = 0;

	UPDATESTATUS(running);
	emit sig_setLot(loopCount);

	int loadIndex = 0;
	int unloadIndex = 0;
	while (m_bAutoMode&&loopCount< listBox.size()) {
		if (m_bES)
			break;
		emit sig_setLot(loopCount);

		short status = 0;
		m_iPannelID = loadIndex + 1;
		emit sig_updateResult(true, m_iPannelID, 0, 0, "", "");
		emit sig_testResult(0xff, 0xff, 0);

		axis_move(0, 0, config.lORG_Speed_TestX, 1, 0, 1, true);
		axis_move(0, 2, config.lORG_Speed_TestX2, 0, 0, 1, true);

		//********** ���� �Ϻ� *********************************
		while (!status) {
			if (!dmc_read_inbit(1, 4) || !dmc_read_inbit(1, 8)) {
				status = 0;
				emit sig_setStatus(abnormalPannel_unLoad);
			}
			else {
				status = 1;
			}
		}


		if (loadIndex &&!(loadIndex % config.iBoxRows)) {
			loadIndex = 0;
			unloadIndex = 0;
			++loopCount;

			axis_move(1, 0, config.lLoadSpeed_Z, 1, config.lLoadPos_Z - \
				((config.iBoxRows-1)*(config.iBoxPadding / 2 * 10000)+ (config.iBoxMargin * 10000)),0,false);
			axis_move(1, 1, config.lunLoadSpeed_Z, 1, config.lunLoadPos_Z + \
				((config.iBoxRows - 1)*(config.iBoxPadding / 2 * 10000) + (config.iBoxMargin * 10000)),0, false);
			do {
				status = 1;
				if (dmc_check_done(1, 0)==0|| dmc_check_done(1, 1)==0) {
					status = 0;
				}
			} while (!status);

			slot_writeOutIO(1, 4, 0);
			slot_writeOutIO(1, 6, 0);

			axis_move(1, 0, config.lORG_Speed_LoadZ, 1, 0, 1, false);
			axis_move(1, 1, config.lORG_Speed_unLoadZ, 0, 0, 1, false);
			do {
				status = 1;
				if (dmc_check_done(1, 0) == 0 || dmc_check_done(1, 1) == 0) {
					status = 0;
				}
			} while (!status);


			slot_writeOutIO(1, 5, 0);
			slot_writeOutIO(1, 7, 0);
			msleep(3000);

			UPDATESTATUS(running);
			do{
				status=dmc_read_inbit(1, 12);
				if (!status) UPDATESTATUS(abnormalBoxBase_Load);
				msleep(200);
			} while (!status);
			UPDATESTATUS(running);

			do {
				status = dmc_read_inbit(1, 0);
				if (!status) UPDATESTATUS(abnormalBoxBase_unLoad);
				msleep(200);
			} while (!status);
			UPDATESTATUS(running);

			slot_writeOutIO(1, 5, 1);
			slot_writeOutIO(1, 7, 1);

			axis_move(1, 0, config.lLoadSpeed_Z, 1, config.lLoadPos_Z, 0, false);
			axis_move(1, 1, config.lunLoadSpeed_Z, 1, config.lunLoadPos_Z, 0, false);
			do {
				status = 1;
				if (dmc_check_done(1, 0) == 0 || dmc_check_done(1, 1) == 0) {
					status = 0;
				}
			} while (!status);


			slot_writeOutIO(1, 4, 1);
			slot_writeOutIO(1, 6, 1);
			continue;
		}
		else {
			axis_move(1, 0, config.lLoadSpeed_Z, 1, config.lLoadPos_Z - loadIndex*(config.iBoxPadding / 2 * 10000), 0, false);
			axis_move(1, 1, config.lunLoadSpeed_Z, 1, config.lunLoadPos_Z + unloadIndex *(config.iBoxPadding / 2 * 10000), 0, false);
			do {
				status = 1;
				if (dmc_check_done(1, 0) == 0 || dmc_check_done(1, 1) == 0) {
					status = 0;
				}
			} while (!status);
		}

		loadIndex++;
		unloadIndex++;
		


		//********** ����Ϻ� *************************************
		
		UPDATESTATUS(running);
		do {
			msleep(100);
			status = dmc_read_inbit(1, 9);
			if (!status) UPDATESTATUS(abnormalBox_Load);
		} while (!status);

		UPDATESTATUS(running);
		do {
			msleep(100);
			status = dmc_read_inbit(1, 5);
			if (!status) UPDATESTATUS(abnormalBox_unLoad);
		} while (!status);
		UPDATESTATUS(running);

		m_bPannelCheck = false;
		axis_move(1, 2, config.lLoadSpeed_X, 1, config.lLoadPos_X, 0, true);

		if (m_bPannelCheck)
			axis_move(1, 2, config.lORG_Speed_LoadX, 0, 0, 1, false);
		else
			axis_move(1, 2, config.lORG_Speed_LoadX, 0, 0, 1, true);
		
		// ************************** ���� ***************************************
		if (m_bPannelCheck) {
			m_bPannelCheck = false;
			axis_move(1, 2, config.lORG_Speed_LoadX, 0, 0, 1, false);
			slot_writeOutIO(0, 0, 0);
			axis_move(0, 2, config.lTestClawSpeed, 1, -9000);
			slot_writeOutIO(0, 0, 1);
			msleep(500);
			axis_move(0, 2, config.lORG_Speed_TestX2, 0, 0, 1);
			slot_writeOutIO(0, 0, 0);
			axis_move(0, 2, 1000, 0, -5000, 0, false);

			do {
				status = dmc_read_inbit(0, 2);
				if (dmc_check_done(0, 2)) {
					emit sig_logOutput(QString::fromLocal8Bit("�ذ����ϼ��ʧ�ܣ�"));
					UPDATESTATUS(abnormalPannel_Load);
					return;
				}
			} while (!status);

			dmc_stop(0, 2, 1);
			msleep(500);
			slot_writeOutIO(0, 1, 1);
			msleep(500);
			slot_writeOutIO(0, 2, 0);
			slot_writeOutIO(0, 0, 1);

			if (((AOI*)m_parent)->m_actCamPos->isChecked()){
				emit sig_logOutput(QString::fromLocal8Bit("���˶��������λ�ã������˳��Զ�ģʽ��"));
				return;
			}
			
			

			axis_move(0, 0, config.lORG_Speed_TestX, 1, config.lTestFirstPos_X, 0, false);
			axis_move(0, 1, config.lORG_Speed_TestY, 1, config.lTestFirstPos_Y, 0, false);

			do {
				status = 1;
				if (dmc_check_done(0, 0) == 0 || dmc_check_done(0, 1) == 0) {
					status = 0;
				}
			} while (!status);

			m_markPosition.clear();
			emit sig_testResult(0x00, 0xffff, true);
			if (slot_MatrixMove(config.iPlateRows, config.iPlatCols, \
				int((double)config.iPlatRowPadding / (config.iPlateRows - 1) / 10 * 10000 + 0.5), int((double)config.iPlatColPadding / (config.iPlatCols - 1) / 10 * 10000 + 0.5), listBox.at(loopCount), loadIndex)) return;
			
			//***************************************  ��� *******************************************************
			if(config.bEnablePen)
				slot_MarkPen(m_markPosition, int((double)config.iPlatRowPadding / (config.iPlateRows - 1) / 10 * 10000 + 0.5), int((double)config.iPlatColPadding / (config.iPlatCols - 1) / 10 * 10000 + 0.5));
			
			msleep(1000);
			//**************************************** ���� ********************************************************
			UPDATESTATUS(running);
			do {
				status = dmc_read_inbit(1, 5);
				if (!status) UPDATESTATUS(abnormalPannel_unLoad);
			} while (!status);
			UPDATESTATUS(running);

			slot_writeOutIO(0, 1, 0);
			slot_writeOutIO(0, 2, 1);
			slot_writeOutIO(0, 0, 1);

			axis_move(0, 2, config.lORG_Speed_TestX2, 0, 0, 1, true);
			axis_move(0, 1, config.lunLoadSpeed_Y, 1, config.lunLoadPos_Y, 0, true);
			axis_move(0, 0, config.lunLoadSpeed_X, 1, config.lunLoadPos_X);
			msleep(300);
			slot_writeOutIO(0, 0, 0);
			axis_move(0, 2, config.lORG_Speed_TestX2, 1, -8000, 0, true);
			slot_writeOutIO(0, 0, 1);
			msleep(500);
			axis_move(0, 2, config.lORG_Speed_TestX2, 0, 0, 1, true);
			slot_writeOutIO(0, 0, 0);
			axis_move(0, 2, config.lORG_Speed_TestX2, 1, -10500, 0, true);

			int inx = 0;
			do {
				status = dmc_read_inbit(1, 4);
				if (!status && !inx) {
					emit sig_logOutput(QString::fromLocal8Bit("�����ذ��쳣��"), QColor(255, 255, 0));
					UPDATESTATUS(abnormalPannel_unLoad);
				}
				if (inx > 200) {//��ʱ1����
					emit sig_logOutput(QString::fromLocal8Bit("�����ذ��쳣��ʱ������ֹͣ��"), QColor(255, 255, 0));
					UPDATESTATUS(abnormalPannel_unLoad);
					m_bES = true;
					return;
				}
				msleep(50);
			} while (!status);

			slot_writeOutIO(0, 0, 1);
			axis_move(0, 2, config.lORG_Speed_TestX2, 0, 0, 1, true);
			axis_move(0, 0, config.lORG_Speed_TestX, 1, 0, 1, true);
		}
	}
	emit sig_setLot(-1);
	UPDATESTATUS(success);
	UPDATESTATUS(nextLoop);
}
void Motion_thread::slot_Suspended() {
	
}
int Motion_thread::slot_MatrixMove(int row, int col, double rowMargin, double colMargin,QString boxID,int pannelID) {
	srt_config config = ((AOI*)m_parent)->m_config;
	double rowStep = rowMargin;
	double colStep = colMargin;

	m_iSampleID = col;
	
	long axis_X = dmc_get_position(0, 0);
	long axis_Y = dmc_get_position(0, 1);

	for (int c = 0; c < col; c++) {
		m_iSampleID-=1;
		for (int r = 0; r < row; r++)
		{
			if (c % 2) {
				if(axis_move(0, 1, config.lTestSpeed, 1, (axis_Y+ rowStep*(row-1)) - rowStep*r)) return -1;
				if(r)
					m_iSampleID -= col;
			}
			else {
				if(axis_move(0, 1, config.lTestSpeed, 1, axis_Y + rowStep*r,0, true, false, 0)) return -1;
				if (r)
					m_iSampleID += col;
			}
			if(axis_move(0, 0, config.lTestSpeed, 1, axis_X - colStep*c,0,true,false,0)) return -1;

			//**    ��ʼ���  ****
			if (m_bES)
				return -1;

			mutex1->lock();
			m_bReceived = false;
			slot_predict(boxID, pannelID, m_iSampleID+1);
			mutex1->unlock();
			m_startTime = QTime::currentTime();
			m_startTime.restart();
			while (m_startTime.elapsed()<10000&&m_bReceived==false)
				QApplication::processEvents();
			
		}
	}
	return 0;
}
int Motion_thread::slot_MarkPen(std::vector<long> position, double rowMargin, double colMargin) {
	srt_config config = ((AOI*)m_parent)->m_config;
	for (int i = 0; i < position.size(); i++) {
		if (m_bES)
			return -1;
		long row = std::floor(position.at(i) / config.iPlatCols);
		long col = config.iPlatCols-1-(position.at(i) % config.iPlatCols);
		long status=0;

		axis_move(0, 0, config.lTestSpeed, 1, config.iPenPos_X - col*colMargin+config.iPenOffset, 0, false);
		axis_move(0, 1, config.lTestSpeed, 1, config.iPenPos_Y + row*rowMargin, 0, false);

		do {
			status = 1;
			if (dmc_check_done(0, 0) == 0 || dmc_check_done(0, 1) == 0) {
				status = 0;
			}
		} while (!status);

		if (m_bES)
			return -1;
		slot_writeOutIO(0, 3, 1);
		msleep(1000);
		slot_writeOutIO(0, 3, 0);
	}

	return 0;
}
void Motion_thread::slot_predict(QString boxID, int pannelID, int sampleID) {
	//QString strSend("{\"action\":\"1\"}");
	//currow = row;					//�����Ͻ�Ϊ1,1������к�
	//curcol = colCMOS - col + 1;		//�����Ͻ�Ϊ1,1������к�
	//sample_id = curcol + colCMOS*(row - 1);//�����Ҵ��ϵ��¼���
	QString strTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");//��������ָ��ʱ��
	QString s = boxID+pannelID+sampleID+strTime;//boxid+pannelid+sampleid+time�ϲ���������MD5
	QByteArray b = HTTP_Interface::getMD5(s.toLatin1());
	QString md5 = HTTP_Interface::UnicodeToString(b);



	QString strSend(tr("{\"box_id\":\"%1\",\"pannel_id\":\"%2\",\"sample_id\":\"%3\",\"machine_id\":\"%4\",\"time\":\"%5\",\"operator\":\"%6\",\"shift_id\":\"%7\",\"md5\":\"%8\",\"config\":\"%9\"}")
		.arg(boxID)
		.arg(pannelID)
		.arg(sampleID)
		.arg(1)
		.arg(strTime)
		.arg(1)
		.arg(1)
		.arg(md5)
		.arg(1)
	);
	m_HTTP_Interface->sendPost(strSend.toUtf8(), QUrl("http://127.0.0.1:6789/predict"), 6789);
	emit sig_updateResult(true,0,0,0,"", md5);
}
void Motion_thread::slot_contour(bool bis) {
	QString strSend;
	if (bis) {
		strSend=QString("{\"detec_en\":\"1\"}");
	}
	else {
		strSend=QString("{\"detec_en\":\"0\"}");
	}

	m_HTTP_Interface->sendPost(strSend.toUtf8(), QUrl("http://127.0.0.1:6789/settings"), 6789);
}

QString Motion_thread::onReply(QNetworkReply *pReply) {
	if (pReply->error());

	QByteArray array = pReply->readAll();
	pReply->close();

	QString str = HTTP_Interface::UnicodeToString(array);

	if (str == NULL)
	{
		emit sig_logOutput("Server ERROR:NO REPLY");
		return str;
	}
	emit  sig_logOutput("Server recv:" + str, QColor(0, 255, 0));

	Document doc;
	doc.Parse(str.toLocal8Bit().data());

	//��ʼ����֧
	if (doc.HasMember("init_result"))
	{
		if (doc["init_result"] == "0")
		{
			emit  sig_logOutput(QString::fromLocal8Bit("������߼��ģ���ʼ������"));
		}
		else
		{
			m_bReceived = true;
		}
		return str;
	}

	//��������֧
	if (doc.HasMember("detec_en"))
	{
		if (doc["detec_en"] == "1")
			emit  sig_logOutput(QString::fromLocal8Bit("��������Ѵ�"));
		else if (doc["detec_en"] == "0")
			emit  sig_logOutput(QString::fromLocal8Bit("��������ѹر�"));
		//bReceived = true;
		return str;
	}

	//���շ�֧
	if (doc.HasMember("img_result"))
	{
		QString process_res = QString::fromLocal8Bit(doc["img_result"].GetString());
		QString process_time = QString::fromLocal8Bit(doc["img_proc_time"].GetString());
		QString img_path = QString::fromLocal8Bit(doc["img_path"].GetString());
		QString raw_image_path = QString::fromLocal8Bit(doc["img_raw_path"].GetString());
		QString pos_ok = QString::fromLocal8Bit(doc["img_pos_res"].GetString());
		emit  sig_logOutput(img_path, QColor(255, 0, 0));
		//emit sig_updateImage(img_path);

		int gridColor;//���������ɫflag
		if (process_res == "OK")
			gridColor = 1;
		else if (process_res == "NG")
			gridColor = 0;
		else if (process_res == "NO")
			gridColor = 2;

		//emit sigSendRes(pannel_id, currow, curcol, gridColor, process_time, md5, raw_image_path);

		m_bReceived = true;
		return str;
	}
	emit  sig_logOutput("Server ERROR");
	return str;
}
void Motion_thread1::slot_predict(QString boxID, int pannelID, int sampleID) {
	m_bReceived = false;
	//QString strSend("{\"action\":\"1\"}");
	//currow = row;					//�����Ͻ�Ϊ1,1������к�
	//curcol = colCMOS - col + 1;		//�����Ͻ�Ϊ1,1������к�
	//sample_id = curcol + colCMOS*(row - 1);//�����Ҵ��ϵ��¼���
	QString strTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");//��������ָ��ʱ��
	QString s = strTime;//boxid+pannelid+sampleid+time�ϲ���������MD5
	QByteArray b = HTTP_Interface::getMD5(s.toLatin1());
	QString md5 = HTTP_Interface::UnicodeToString(b);

	QString strSend(tr("{\"box_id\":\"%1\",\"pannel_id\":\"%2\",\"sample_id\":\"%3\",\"machine_id\":\"%4\",\"time\":\"%5\",\"operator\":\"%6\",\"shift_id\":\"%7\",\"md5\":\"%8\",\"config\":\"%9\"}")
		.arg(boxID)
		.arg(pannelID)
		.arg(sampleID)
		.arg(1)
		.arg(strTime)
		.arg(1)
		.arg(1)
		.arg(md5)
		.arg(1)
	);
	slot_sendPost(strSend.toUtf8(), QUrl("http://127.0.0.1:6789/predict"), 6789);

}
int Motion_thread::axis_move(int card, int axis, int speed, int absMode,int target, int orgMode, bool bAck,bool bReset,double tdec) {
	if (!bReset||!orgMode){
		while (m_bSuspended) {
			msleep(20);
		}
		mutex1->lock();
		if (m_bES) {
			emit sig_logOutput(QString::fromLocal8Bit("��ͣ״̬�У�"),QColor(255,0,0));
			mutex1->unlock();
			return -1;
		}
		mutex1->unlock();
	}
	if (bReset)
		m_bResetMode = true;

	if (tdec == 0) {
		dmc_set_profile(card, axis, (double)speed, speed, tdec, tdec, 0);
	}
	else {
		dmc_set_profile(card, axis, (double)speed*0.2, speed, tdec, tdec, 0);
	}
	
	if (orgMode) {
		dmc_set_homemode(card, axis, absMode, 1, 0, 0);
		dmc_home_move(card, axis);
	}
	else {
		dmc_pmove(card, axis, target, absMode);
	}

	short status;
	do {
		::Sleep(10);
		status = dmc_check_done(card, axis);
	} while (!status&&bAck);

	//m_bResetMode = false;

	if (!orgMode||!bAck)
		return 0;

	long pos = 1;
	do {
		dmc_set_position(card, axis, 0);
		msleep(100);
		pos=dmc_get_position(card, axis);
	} while (pos);

	return 0;
}

Motion_thread1::Motion_thread1(QObject *parent): m_pManager(new QNetworkAccessManager)
{
	m_parent = (Motion_thread*)parent;
	connect(this, &Motion_thread1::sig_logOutput, m_parent, &Motion_thread::sig_logOutput);
	connect(this, &Motion_thread1::sig_testResult, m_parent, &Motion_thread::sig_testResult);
	connect(this, &Motion_thread1::sig_updateResult, m_parent, &Motion_thread::sig_updateResult);
}
Motion_thread1::~Motion_thread1() {

}
void Motion_thread1::run() {
	m_pManager->moveToThread(this);
	connect(m_pManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onReply(QNetworkReply *)));
	emit sig_logOutput(tr("sent init post"));
	QString strSend("{\"init\":\"1\"}");
	slot_sendPost(strSend.toLatin1(), QUrl("http://127.0.0.1:6789/init"), 6789);
	exec();
	return;
}
QString Motion_thread1::onReply(QNetworkReply *pReply) {
	if (pReply->error());
	QByteArray array = pReply->readAll();
	pReply->close();

	QString str = HTTP_Interface::UnicodeToString(array);

	if (str == NULL)
	{
		emit sig_logOutput("Server ERROR:NO REPLY");
		return str;
	}
	emit  sig_logOutput("Server recv:" + str, QColor(0, 255, 0));

	Document doc;
	doc.Parse(str.toLocal8Bit().data());

	//��ʼ����֧
	if (doc.HasMember("init_result"))
	{
		if (doc["init_result"] == "0")
		{
			emit  m_parent->sig_logOutput(QString::fromLocal8Bit("������߼��ģ���ʼ������"));
		}
		else
		{
			m_bReceived = true;
		}
		return str;
	}

	//��������֧
	if (doc.HasMember("detec_en"))
	{
		if (doc["detec_en"] == "1")
			emit  sig_logOutput(QString::fromLocal8Bit("��������Ѵ�"));
		else if (doc["detec_en"] == "0")
			emit  sig_logOutput(QString::fromLocal8Bit("��������ѹر�"));
		//bReceived = true;
		return str;
	}

	//���շ�֧
	if (doc.HasMember("img_result"))
	{
		QString process_res = QString::fromLocal8Bit(doc["img_result"].GetString());
		QString process_time = QString::fromLocal8Bit(doc["img_proc_time"].GetString());
		QString img_path = QString::fromLocal8Bit(doc["img_path"].GetString());
		QString raw_image_path = QString::fromLocal8Bit(doc["img_raw_path"].GetString());
		QString pos_ok = QString::fromLocal8Bit(doc["img_pos_res"].GetString());
		emit  sig_logOutput(img_path, QColor(255, 0, 0));
		emit m_parent->sig_updateImage(img_path);

		int gridColor;//���������ɫflag
		if (process_res == "OK")
			gridColor = 1;
		else if (process_res == "NG")
			gridColor = 0;
		else if (process_res == "NO")
			gridColor = 2;

		emit sig_testResult(m_parent->m_iSampleID,0,gridColor);

		emit sig_updateResult(gridColor, m_parent->m_iPannelID, m_parent->m_iSampleID,\
			((Motion_thread*)m_parent)->m_startTime.elapsed(),\
			img_path, "");
		
		if(gridColor!=1)
			m_parent->m_markPosition.push_back(m_parent->m_iSampleID);

		//emit sigSendRes(pannel_id, currow, curcol, gridColor, process_time, md5, raw_image_path);
		m_bReceived = true;
		m_parent->mutex1->lock();
		m_parent->m_bReceived = m_bReceived;
		m_parent->mutex1->unlock();
		
		return str;
	}
	emit  sig_logOutput("Server ERROR");
	return str;
}
QNetworkAccessManager* Motion_thread1::slot_sendPost(QByteArray sendBuf,QUrl url,int port, QString contentType) {
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant(contentType));
	m_pManager->post(request, sendBuf);

	return m_pManager;
}