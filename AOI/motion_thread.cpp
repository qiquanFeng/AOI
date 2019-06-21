#include "motion_thread.h"
#include "aoi.h"
using namespace rapidjson;

Motion_thread::Motion_thread(QObject *parent)
	: QThread(nullptr), m_CardNum(0), m_bES(false), m_bReceived(false), m_HTTP_Interface(new HTTP_Interface),\
	mutex1(new QMutex), m_parent(parent), m_bAutoMode(false), m_bSuspended(false)
{
	configFilePath[0] = QString("DMC3400.ini");
	configFilePath[1] = QString("DMC3800.ini");
	connect(this, SIGNAL(sig_logOutput(QString, QColor)), parent, SLOT(slot_outputLog(QString, QColor)));
	connect(this, SIGNAL(sig_statusChange(int,int, bool,int)), parent, SLOT(slot_IOChangeInfo(int, int,bool,int)));
	connect(this, SIGNAL(sig_updateImage(QString)), parent, SLOT(slot_updateImage(QString)),Qt::DirectConnection);
	motion_Init();
}

Motion_thread::~Motion_thread()
{

}
void Motion_thread::run() {
	while (1&& m_CardNum==2) {
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
		
		if (inStatus[1][11]) {
			m_bES = true;
			dmc_stop(1, 2, 1);
		}
		msleep(300);
	}
}

void Motion_thread::slot_sendChangeIO(int iIoNumber, int iCard) {
	int i = iIoNumber;
	i = iCard;
	short status = dmc_read_outbit(iCard, iIoNumber);
	dmc_write_outbit(iCard, iIoNumber, !status);
}
void Motion_thread::slot_resetAxis() {
	emit sig_logOutput("reset...");
	dmc_write_outbit(0, 0, 1);
	dmc_write_outbit(0, 1, 0);
	dmc_write_outbit(1, 5, 1);
	dmc_write_outbit(1, 6, 1);
	dmc_write_outbit(1, 7, 1);
	dmc_write_outbit(0, 2, 1);
	

	axis_move(1, 2, 10000, 0, 0, 1);
	axis_move(1, 0, 80000, 1, 0, 1,false);
	axis_move(1, 1, 80000, 0, 0, 1, false);

	axis_move(0, 0, 10000, 1, 0, 1, false);
	axis_move(0, 1, 10000, 0, 0, 1, false);
	axis_move(0, 2, 1000, 0, 0, 1, false);
	

	m_bES = false;
	emit sig_logOutput(tr("reset success!"), QColor(0, 255, 0));
}
int Motion_thread::slot_writeOutIO(WORD card, WORD bitNo, WORD status) {
	while (m_bSuspended) {
		msleep(200);
	}

	if (m_bES) {
		return -1;
	}

	dmc_write_outbit(card, bitNo, status);
	return 0;
}
int Motion_thread::motion_Init() {
	emit sig_logOutput(QString::fromLocal8Bit("正在初始化"));
	m_CardNum = dmc_board_init();
	if (m_CardNum == 0)
	{
		emit sig_logOutput(QString::fromLocal8Bit("没有找到控制卡"));
		return -1;
	}
	if (m_CardNum != 2)
	{
		emit sig_logOutput(QString::fromLocal8Bit("控制卡数量异常"));
		return -1;
	}

	for (int card = 0; card < m_CardNum; card++)
	{
		if (int errorCode = dmc_download_configfile(card, configFilePath[card].toLatin1().data()))
		{
			emit sig_logOutput(QString::fromLocal8Bit("控制卡卡%1配置文件载入失败，错误代码：%2").arg(card).arg(errorCode));
			return -1;
		}
		for (int axis = 0; axis < 8; axis++)
			if (dmc_write_sevon_pin(card, axis, 0))
			{
				emit sig_logOutput(QString::fromLocal8Bit("卡%1轴%2的伺服使能端口输出设置失败").arg(card).arg(axis));
				return -1;
			}
	}
	

	//**           相机初始化  ****************************

	QString strSend("{\"init\":\"1\"}");
	emit sig_logOutput(tr("sent init post"));
	m_HTTP_Interface->sendPost(strSend.toLatin1(), QUrl("http://127.0.0.1:6789/init"), 6789);
	
	//connect(m_HTTP_Interface->m_pManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onReply(QNetworkReply *)));
	th1 = new Motion_thread1(this);
	connect(m_HTTP_Interface->m_pManager, SIGNAL(finished(QNetworkReply *)), th1, SLOT(onReply(QNetworkReply *)));
	return m_CardNum;
}
void Motion_thread::slot_load() {
	emit sig_logOutput("start load...");
	dmc_write_outbit(0, 0, 1);
	dmc_write_outbit(0, 1, 0);
	dmc_write_outbit(1, 5, 1);
	dmc_write_outbit(1, 6, 1);
	dmc_write_outbit(1, 7, 1);
	dmc_write_outbit(0, 2, 1);

	axis_move(1, 2, 10000, 0, 0, 1, true);
	axis_move(1, 0, 80000, 1, 1040000,0,false);
	axis_move(1, 1, 80000, 1, -1010000, 0, false);
	axis_move(0, 1, 20000, 1, 88600, 0, false);
	axis_move(0, 0, 20000, 1, 0,1,true);
	axis_move(0, 2, 1000, 0, 0, 1, true);
	emit sig_logOutput("end load");
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
			emit sig_logOutput(QString::fromLocal8Bit("载板上料检测失败！"));
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
	slot_MatrixMove(3, 11, 12.5, 19.5);
	
}
void Motion_thread::slot_auto() {
	srt_config config = ((AOI*)m_parent)->m_config;
	m_bAutoMode = true;

	emit sig_logOutput("axis reset...");
	slot_writeOutIO(0, 0, 1);
	slot_writeOutIO(0, 1, 0);
	slot_writeOutIO(1, 4, 1);
	slot_writeOutIO(1, 5, 1);
	slot_writeOutIO(1, 6, 1);
	slot_writeOutIO(1, 7, 1);
	slot_writeOutIO(0, 2, 1);

	axis_move(1, 2, config.lORG_Speed_LoadX, 0, 0, 1);
	axis_move(1, 1, config.lORG_Speed_unLoadZ, 0, 0, 1, false);
	axis_move(0, 0, config.lORG_Speed_TestX, 1, 0, 1, false);
	axis_move(0, 1, config.lORG_Speed_TestY, 0, 0, 1, true);
	axis_move(0, 2, config.lORG_Speed_TestX2, 0, 0, 1, false);
	axis_move(1, 0, config.lORG_Speed_LoadZ, 1, 0, 1, true);

	emit sig_logOutput("load ...");
	slot_writeOutIO(0, 0, 1);
	slot_writeOutIO(0, 1, 0);
	slot_writeOutIO(1, 5, 1);
	slot_writeOutIO(1, 6, 1);
	slot_writeOutIO(1, 7, 1);
	slot_writeOutIO(0, 2, 1);

	axis_move(0, 1, config.lLoadSpeed_Y, 1, config.lLoadPos_Y, 0, false);
	axis_move(0, 0, config.lORG_Speed_TestX, 1, 0, 1, false);
	axis_move(0, 2, config.lORG_Speed_TestX2, 0, 0, 1, false);
	axis_move(1, 1, config.lunLoadSpeed_Z, 1, config.lunLoadPos_Z, 0, false);
	axis_move(1, 2, config.lORG_Speed_LoadX, 0, 0, 1, true);
	axis_move(1, 0, config.lLoadSpeed_Z, 1, config.lLoadPos_Z, 0, true);
	
	

	int loadIndex = 0;
	int unloadIndex = 0;
	while (m_bAutoMode) {
		if (m_bES)
			break;
		//********** 检测料盒 *************************************
		short status = 0;
		emit sig_logOutput(tr("check box exists..."), QColor());
		do {
			msleep(10);
			status = dmc_read_inbit(1, 9);
		} while (!status);

		axis_move(0, 0, config.lORG_Speed_TestX, 1, 0, 1, true);
		axis_move(0, 2, config.lORG_Speed_TestX2, 0, 0, 1, true);

		if (loadIndex &&!(loadIndex % config.iBoxRows)) {
			loadIndex = 0;
			axis_move(1, 0, config.lLoadSpeed_Z, 1, config.lLoadPos_Z - \
				((config.iBoxRows-1)*(config.iBoxPadding / 2 * 10000)+ (config.iBoxMargin / 2 * 10000)));
			slot_writeOutIO(1, 4, 0);
			axis_move(1, 0, config.lORG_Speed_LoadZ, 1, 0, 1, true);
			slot_writeOutIO(1, 5, 0);
			msleep(2000);
			emit sig_logOutput(QString::fromLocal8Bit("检测上料盒是否已满"));
			do{
				status=dmc_read_inbit(1, 12);
				msleep(20);
			} while (!status);

			slot_writeOutIO(1, 5, 1);
			axis_move(1, 0, config.lLoadSpeed_Z, 1, config.lLoadPos_Z, 0, true);
			slot_writeOutIO(1, 4, 1);
			continue;
		}

		loadIndex++;

		emit sig_logOutput("test");
		axis_move(1, 2, config.lLoadSpeed_X, 1, config.lLoadPos_X, 0, true);

		if (dmc_read_inbit(1, 8) == 0)
			axis_move(1, 2, config.lORG_Speed_LoadX, 0, 0, 1, false);
		else
			axis_move(1, 2, config.lORG_Speed_LoadX, 0, 0, 1, true);
		//********** 夹料 *********************************
		if (dmc_read_inbit(1, 8) == 0) {
			axis_move(1, 2, 20000, 0, 0, 1, false);
			slot_writeOutIO(0, 0, 0);
			axis_move(0, 2, 2000, 1, -9000);
			slot_writeOutIO(0, 0, 1);
			axis_move(0, 2, 2000, 0, 0, 1);
			slot_writeOutIO(0, 0, 0);
			axis_move(0, 2, 1000, 0, -5000, 0, false);
			do {
				status = dmc_read_inbit(0, 2);
				if (dmc_check_done(0, 2)) {
					emit sig_logOutput(QString::fromLocal8Bit("载板上料检测失败！"));
					m_bES=true;
					return;
				}
			} while (status);
			dmc_stop(0, 2, 1);
			msleep(500);
			slot_writeOutIO(0, 1, 1);
			msleep(500);
			slot_writeOutIO(0, 2, 0);
			slot_writeOutIO(0, 0, 1);

			//slot_MatrixMove(config.iPlateRows, config.iPlatCols,\
				int((double)config.iPlatRowPadding/config.iPlateRows/10*10000+0.5), int((double)config.iPlatColPadding / config.iPlatCols / 10 * 10000+0.5));
			
			//**************************************** 下料 ********************************************************
			emit sig_logOutput(QString::fromLocal8Bit("检测下料盒"), QColor(255, 255, 0));
			do {
				status = dmc_read_inbit(1, 5);
			} while (!status);

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
			axis_move(0, 2, config.lORG_Speed_TestX2, 0, 0, 1, true);
			slot_writeOutIO(0, 0, 0);
			axis_move(0, 2, config.lORG_Speed_TestX2, 1, -10500, 0, true);

			int inx = 0;
			do {
				status = dmc_read_inbit(1, 4);
				if (!status && !inx) {
					emit sig_logOutput(QString::fromLocal8Bit("下料载板异常！"), QColor(255, 255, 0));
				}
				if (inx > 200) {//超时1分钟
					emit sig_logOutput(QString::fromLocal8Bit("下料载板异常超时，即将停止！"), QColor(255, 255, 0));
					m_bES = true;
					return;
				}
				msleep(50);
			} while (!status);

			slot_writeOutIO(0, 0, 1);
			axis_move(0, 2, config.lORG_Speed_TestX2, 0, 0, 1, true);
			axis_move(0, 0, config.lORG_Speed_TestX, 1, 0, 1, true);
			
			if (unloadIndex && !(unloadIndex % config.iBoxRows)) {
				unloadIndex = 0;
				axis_move(1, 1, config.lunLoadSpeed_Z, 1, config.lunLoadPos_Z + \
					((config.iBoxRows - 1)*(config.iBoxPadding / 2 * 10000) + (config.iBoxMargin / 2 * 10000)));
				slot_writeOutIO(1, 6, 0);
				axis_move(1, 1, config.lORG_Speed_unLoadZ, 0, 0, 1, true);
				slot_writeOutIO(1, 7, 0);
				msleep(2000);
				emit sig_logOutput(QString::fromLocal8Bit("检测下料盒是否已满"));
				do {
					status = dmc_read_inbit(1, 0);
					msleep(20);
				} while (!status);

				slot_writeOutIO(1, 7, 1);
				axis_move(1, 1, config.lunLoadSpeed_Z, 1, config.lunLoadPos_Z, 0, true);
				slot_writeOutIO(1, 6, 1);
				continue;
			}

			axis_move(1, 1, config.lunLoadSpeed_Z, 1, config.lunLoadPos_Z + unloadIndex*(config.iBoxPadding / 2 * 10000), 0);
			unloadIndex++;

		}

		axis_move(1, 0, config.lLoadSpeed_Z, 1, config.lLoadPos_Z-loadIndex*(config.iBoxPadding/2*10000), 0);
	}
}
void Motion_thread::slot_Suspended() {
	
}
void Motion_thread::slot_MatrixMove(int row, int col, double rowMargin, double colMargin) {
	srt_config config = ((AOI*)m_parent)->m_config;
	double rowStep = rowMargin;
	double colStep = colMargin;

	for (int c = 0; c < col; c++) {
		for (int r = 0; r < row; r++)
		{
			if (c % (row-1)) {
				axis_move(0, 1, config.lTestSpeed, 0, -rowStep);
			}
			else {
				axis_move(0, 1, config.lTestSpeed, 0, rowStep);
			}
			//**    开始检测  ****
			mutex1->lock();
			m_bReceived = false;
			slot_predict();
			mutex1->unlock();
			QTime reachTime = QTime::currentTime().addMSecs(10000);
			while (QTime::currentTime() < reachTime&&m_bReceived==false)
				QApplication::processEvents();
			
		}
		axis_move(0, 0, 20000, 0, -colStep);
		//**    开始检测  ****
		mutex1->lock();
		m_bReceived = false;
		slot_predict();
		mutex1->unlock();
		QTime reachTime = QTime::currentTime().addMSecs(10000);
		while (QTime::currentTime() < reachTime&&m_bReceived == false)
			QApplication::processEvents();
	}
}
void Motion_thread::slot_predict() {
	//QString strSend("{\"action\":\"1\"}");
	//currow = row;					//以左上角为1,1坐标的行号
	//curcol = colCMOS - col + 1;		//以左上角为1,1坐标的列号
	//sample_id = curcol + colCMOS*(row - 1);//从左到右从上到下计数
	QString strTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");//发送拍照指令时间
	QString s = strTime;//boxid+pannelid+sampleid+time合并用以生成MD5
	QByteArray b = HTTP_Interface::getMD5(s.toLatin1());
	QString md5 = HTTP_Interface::UnicodeToString(b);

	QString strSend(tr("{\"box_id\":\"%1\",\"pannel_id\":\"%2\",\"sample_id\":\"%3\",\"machine_id\":\"%4\",\"time\":\"%5\",\"operator\":\"%6\",\"shift_id\":\"%7\",\"md5\":\"%8\",\"config\":\"%9\"}")
		.arg(1)
		.arg(1)
		.arg(1)
		.arg(1)
		.arg(strTime)
		.arg(1)
		.arg(1)
		.arg(md5)
		.arg(1)
	);
	m_HTTP_Interface->sendPost(strSend.toUtf8(), QUrl("http://127.0.0.1:6789/predict"), 6789);

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

	//初始化分支
	if (doc.HasMember("init_result"))
	{
		if (doc["init_result"] == "0")
		{
			emit  sig_logOutput(QString::fromLocal8Bit("相机或者检测模块初始化错误"));
		}
		else
		{
			m_bReceived = true;
		}
		return str;
	}

	//轮廓检测分支
	if (doc.HasMember("detec_en"))
	{
		if (doc["detec_en"] == "1")
			emit  sig_logOutput(QString::fromLocal8Bit("轮廓检测已打开"));
		else if (doc["detec_en"] == "0")
			emit  sig_logOutput(QString::fromLocal8Bit("轮廓检测已关闭"));
		//bReceived = true;
		return str;
	}

	//拍照分支
	if (doc.HasMember("img_result"))
	{
		QString process_res = QString::fromLocal8Bit(doc["img_result"].GetString());
		QString process_time = QString::fromLocal8Bit(doc["img_proc_time"].GetString());
		QString img_path = QString::fromLocal8Bit(doc["img_path"].GetString());
		QString raw_image_path = QString::fromLocal8Bit(doc["img_raw_path"].GetString());
		QString pos_ok = QString::fromLocal8Bit(doc["img_pos_res"].GetString());
		emit  sig_logOutput(img_path, QColor(255, 0, 0));
		//emit sig_updateImage(img_path);

		int gridColor;//界面格子颜色flag
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
void Motion_thread1::slot_predict() {
	m_bReceived = false;
	//QString strSend("{\"action\":\"1\"}");
	//currow = row;					//以左上角为1,1坐标的行号
	//curcol = colCMOS - col + 1;		//以左上角为1,1坐标的列号
	//sample_id = curcol + colCMOS*(row - 1);//从左到右从上到下计数
	QString strTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");//发送拍照指令时间
	QString s = strTime;//boxid+pannelid+sampleid+time合并用以生成MD5
	QByteArray b = HTTP_Interface::getMD5(s.toLatin1());
	QString md5 = HTTP_Interface::UnicodeToString(b);

	QString strSend(tr("{\"box_id\":\"%1\",\"pannel_id\":\"%2\",\"sample_id\":\"%3\",\"machine_id\":\"%4\",\"time\":\"%5\",\"operator\":\"%6\",\"shift_id\":\"%7\",\"md5\":\"%8\",\"config\":\"%9\"}")
		.arg(1)
		.arg(1)
		.arg(1)
		.arg(1)
		.arg(strTime)
		.arg(1)
		.arg(1)
		.arg(md5)
		.arg(1)
	);
	slot_sendPost(strSend.toUtf8(), QUrl("http://127.0.0.1:6789/predict"), 6789);

}
int Motion_thread::axis_move(int card, int axis, int speed, int absMode,int target, int orgMode, bool bAck) {
	if (m_bES) {
		emit sig_logOutput(QString::fromLocal8Bit("急停状态中！"),QColor(255,0,0));
		return -1;
	}

	dmc_set_profile(card,axis, (double)speed*0.2, speed, 0.1, 0.1, 0);
	if (orgMode) {
		dmc_set_homemode(card, axis, absMode, 1, 0, 0);
		dmc_home_move(card, axis);
	}
	else {
		dmc_pmove(card, axis,target, absMode);
	}

	short status;
	do{
		::Sleep(10);
		status=dmc_check_done(card, axis);
		
	} while (!status&&bAck);
	
	
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

	//初始化分支
	if (doc.HasMember("init_result"))
	{
		if (doc["init_result"] == "0")
		{
			emit  m_parent->sig_logOutput(QString::fromLocal8Bit("相机或者检测模块初始化错误"));
		}
		else
		{
			m_bReceived = true;
		}
		return str;
	}

	//轮廓检测分支
	if (doc.HasMember("detec_en"))
	{
		if (doc["detec_en"] == "1")
			emit  sig_logOutput(QString::fromLocal8Bit("轮廓检测已打开"));
		else if (doc["detec_en"] == "0")
			emit  sig_logOutput(QString::fromLocal8Bit("轮廓检测已关闭"));
		//bReceived = true;
		return str;
	}

	//拍照分支
	if (doc.HasMember("img_result"))
	{
		QString process_res = QString::fromLocal8Bit(doc["img_result"].GetString());
		QString process_time = QString::fromLocal8Bit(doc["img_proc_time"].GetString());
		QString img_path = QString::fromLocal8Bit(doc["img_path"].GetString());
		QString raw_image_path = QString::fromLocal8Bit(doc["img_raw_path"].GetString());
		QString pos_ok = QString::fromLocal8Bit(doc["img_pos_res"].GetString());
		emit  sig_logOutput(img_path, QColor(255, 0, 0));
		emit m_parent->sig_updateImage(img_path);

		int gridColor;//界面格子颜色flag
		if (process_res == "OK")
			gridColor = 1;
		else if (process_res == "NG")
			gridColor = 0;
		else if (process_res == "NO")
			gridColor = 2;

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