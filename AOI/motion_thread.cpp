#include "motion_thread.h"

Motion_thread::Motion_thread(QObject *parent)
	: QThread(nullptr), m_CardNum(0), m_bES(false)
{
	configFilePath[0] = QString("DMC3400.ini");
	configFilePath[1] = QString("DMC3800.ini");
	connect(this, SIGNAL(sig_logOutput(QString, QColor)), parent, SLOT(slot_outputLog(QString, QColor)));
	connect(this, SIGNAL(sig_statusChange(int,int,int)), parent, SLOT(slot_IOChangeInfo(int, int, int)));
	motion_Init();
}

Motion_thread::~Motion_thread()
{

}
void Motion_thread::run() {
	while (1) {
		short status[2][16];

		for (int card = 0; card < 2; card++)
		{
			for (int axis = 0; axis < 16;axis++) {
				status[card][axis]=dmc_read_inbit(card,axis);
			}
		}
		
		if (status[1][11]) {
			m_bES = true;
			dmc_stop(1, 2, 1);
		}
		msleep(20);
	}
}

void Motion_thread::slot_sendChangeIO(int iIoNumber, int iCard) {
	int i = iIoNumber;
	i = iCard;
	short status = dmc_read_outbit(iCard, iIoNumber);
	dmc_write_outbit(iCard, iIoNumber, !status);

	status = dmc_read_outbit(iCard, iIoNumber);
	emit sig_statusChange(iIoNumber, iCard, status);
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
	axis_move(0, 2, 2000, 0, 0, 1, false);
	

	m_bES = false;
	emit sig_logOutput(tr("reset success!"), QColor(0, 255, 0));
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
	/*
	QString strSend("{\"init\":\"1\"}");
	emit sigLogAdd(tr("sent init post"));
	for (int i = 0; i < 4; i++)
	{
		if (!bReceived)
		{
			m_HTTP_Interface->sendPost(strSend.toLatin1(), QUrl("http://127.0.0.1:6789/init"), 6789);
			mysleep(2500);
		}
	}
	if (!bReceived)
	{
		emit sigWarnningLogAdd(QString::fromLocal8Bit("初始化失败"));
		emit sigLogAdd(QString::fromLocal8Bit("初始化失败"));
		return;
	}

	emit sigWarnningLogAdd(QString::fromLocal8Bit("初始化成功"));
	emit sigLogAdd(QString::fromLocal8Bit("初始化成功"));
	bInited = true;
	*/

	return m_CardNum;
}
void Motion_thread::slot_load() {
	emit sig_logOutput("start load...");
	axis_move(1, 0, 80000, 1, 1040000,0,false);
	axis_move(1, 1, 80000, 1, -1020000, 0, false);
	axis_move(0, 1, 20000, 1, 88600, 0, false);
	axis_move(0, 0, 20000, 1, 0,1,false);
}
void Motion_thread::slot_unload() {
	emit sig_logOutput("start unload...");
	dmc_write_outbit(0, 1, 0);
	dmc_write_outbit(0, 2, 1);

	axis_move(0, 1, 20000, 1, 88600, 0, false);
	axis_move(0, 0, 40000, 1, -350000);
	msleep(300);
	dmc_write_outbit(0, 0, 0);
}
void Motion_thread::slot_test() {
	emit sig_logOutput("start test... ");
	short status = 0;
	emit sig_logOutput(tr("check box exists..."),QColor());
	do {
		msleep(10);
		status = dmc_read_inbit(1, 9);
	} while (!status);

	emit sig_logOutput(tr("check box success!"));
	axis_move(1, 2, 20000, 1, -90000);

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
			break;
		}
	} while (status);
	
	dmc_stop(0, 2, 1);
	msleep(500);
	dmc_write_outbit(0, 1, 1);
	dmc_write_outbit(0, 2, 0);
	dmc_write_outbit(0, 0, 1);

	slot_MatrixMove(3, 11, 12.5, 19.5);
}
void Motion_thread::slot_MatrixMove(int row, int col, double rowMargin, double colMargin) {
	double rowStep = rowMargin * 1000;
	double colStep = colMargin * 1000;

	for (int c = 0; c < col; c++) {
		for (int r = 0; r < row; r++)
		{
			if (c % 2) {
				axis_move(0, 1, 10000, 0, -rowStep);
			}
			else {
				axis_move(0, 1, 10000, 0, rowStep);
			}
		}
		axis_move(0, 0, 10000, 0, -colStep);
	}
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
	
	if(orgMode)
		dmc_set_position(card, axis, 0);
	return 0;
}