#include "pushbuttonex.h"

PushButtonEx::PushButtonEx(QString text, int ioNumber, int card,bool enable, QWidget *parent)
	: QPushButton(text,parent), m_iCardNumber(card),m_iIONumber(ioNumber), m_iStatus(0), m_bEnable(enable)
{
	//setStyleSheet("background-color:rgb(0,255,0);border: 3px solid red;border-radius:8px;");
	setObjectName(QString("button_%1_%2").arg(card).arg(ioNumber));

	slot_statusChange(m_iStatus);
	connect(this, SIGNAL(pressed()), this, SLOT(slot_pressed()));

}

PushButtonEx::~PushButtonEx()
{

}
void PushButtonEx::slot_pressed() {
	if (m_iStatus == 2||!m_bEnable)
		return;

	slot_statusChange(2);
	emit sig_sendIO(m_iIONumber,m_iCardNumber);
}
void PushButtonEx::slot_statusChange(int status) {
	m_iStatus = status;
	switch (status)
	{
	case 0:
		setStyleSheet("QPushButton{background-color:green;}");
		break;
	case 1:
		setStyleSheet("background-color:red;");
		break;
	case 2:
		setStyleSheet("background-color:yellow;");
		break;
	}
}