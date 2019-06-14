#include "motion_thread.h"

Motion_thread::Motion_thread(QObject *parent)
	: QThread(parent)
{

	connect(this, SIGNAL(sig_logOutput(QString, QColor)), parent, SLOT(slot_outputLog(QString, QColor)));
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
}
int Motion_thread::motion_Init() {
	int nCardNum = dmc_board_init();

	emit sig_logOutput(QString("Card Number:%1").arg(nCardNum));
	return nCardNum;
}