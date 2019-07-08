#include "DialogEx_thread.h"
#include <QTime>
#include "DialogEx.h"

DialogEx_thread::DialogEx_thread(QObject *parent)
	: QThread(parent), m_parent((DialogEx*)parent)
{
}

DialogEx_thread::~DialogEx_thread()
{
}

void DialogEx_thread::run() {
	m_parent->mutex_key.lock();
	QTime time = QTime::currentTime();
	while (QTime::currentTime() < time.addMSecs(500)) {
	}

	int inx = m_parent->strLotNum.lastIndexOf(m_parent->str_temp);
	if (inx >=0) {
		m_parent->bFirstKey = true;
		//emit sig_clear(m_parent->strLotNum.size()+1);
		emit sig_setStyle(inx + 1, "background-color:red;");
		msleep(300);
		emit sig_setStyle(inx + 1, "background-color:blue;");
		msleep(300);
		emit sig_setStyle(inx + 1, "background-color:green;");
		msleep(300);
		emit sig_setStyle(inx + 1, "background-color:white;");
		m_parent->str_temp.clear();
		m_parent->mutex_key.unlock();
		return;
	}
		
	m_parent->strLotNum.append(m_parent->str_temp);
	m_parent->str_temp.clear();

	
	emit sig_setStyle(1, "background-color:white;");
	emit sig_setStyle(2, "background-color:white;");
	emit sig_setStyle(3, "background-color:white;");

	switch (m_parent->strLotNum.size()) {
	case 1:
		emit sig_setStyle(1,"background-color:white;",m_parent->strLotNum.at(0));
		break;
	case 2:
		emit sig_setStyle(1,"background-color:white;", m_parent->strLotNum.at(0));
		emit sig_setStyle(2,"background-color:white;", m_parent->strLotNum.at(1));
		break;
	case 3:
		emit sig_setStyle(1,"background-color:white;", m_parent->strLotNum.at(0));
		emit sig_setStyle(2,"background-color:white;", m_parent->strLotNum.at(1));
		emit sig_setStyle(3,"background-color:white;", m_parent->strLotNum.at(2));
		break;
	}
	
	m_parent->bFirstKey = true;

	m_parent->mutex_key.unlock();
}
