#include "motion_thread.h"

Motion_thread::Motion_thread(QObject *parent)
	: QThread(nullptr), m_CardNum(0)
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
	int i = 9;
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
	emit sig_logOutput("axis reset...");
	dmc_set_profile(1, 2, 2000, 10000, 0.1, 0.1, 0);
	dmc_set_homemode(1, 2, 0, 1, 0, 0);
	dmc_home_move(1, 2);
	while (!dmc_check_done(1, 2)) {
		msleep(10);
	}
	dmc_set_position(1, 0, 0);

	dmc_set_profile(1, 0, 2000, 10000, 0.1, 0.1, 0);
	dmc_set_homemode(1, 0, 1, 1, 0, 0);
	dmc_home_move(1, 0);
	while (!dmc_check_done(1, 0)) {
		msleep(10);
	}
	dmc_set_position(1, 0, 0);

	dmc_set_profile(0, 1, 2000, 10000, 0.1, 0.1, 0);
	dmc_set_homemode(0, 1, 0, 1, 0, 0);
	dmc_home_move(0, 1);
	while (!dmc_check_done(0, 1)) {
		msleep(10);
	}
	dmc_set_position(0, 1, 0);

	dmc_set_profile(0, 0, 2000, 10000, 0.1, 0.1, 0);
	dmc_set_homemode(0, 0, 1, 1, 0, 0);
	dmc_home_move(0, 0);
	while (!dmc_check_done(0, 0)) {
		msleep(10);
	}
	dmc_set_position(0, 0, 0);
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
		emit sigWarnningLogAdd(QString::fromLocal8Bit("��ʼ��ʧ��"));
		emit sigLogAdd(QString::fromLocal8Bit("��ʼ��ʧ��"));
		return;
	}

	emit sigWarnningLogAdd(QString::fromLocal8Bit("��ʼ���ɹ�"));
	emit sigLogAdd(QString::fromLocal8Bit("��ʼ���ɹ�"));
	bInited = true;
	*/

	return m_CardNum;
}