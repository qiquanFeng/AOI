#ifndef MOTION_THREAD_H
#define MOTION_THREAD_H

#include <QThread>
#include "Library/Leisai/LTDMC.h"
#include <QColor>

#ifdef _WIN64
#pragma comment(lib,"Library/Leisai/X64/LTDMC")
#else
#pragma comment(lib,"Library/Leisai/X86/LTDMC")
#endif // _WIN64


class Motion_thread : public QThread
{
	Q_OBJECT

public:
	Motion_thread(QObject *parent=nullptr);
	~Motion_thread();

	int motion_Init();
signals:
	void sig_statusChange();
	void sig_logOutput(QString text, QColor color = QColor(0, 0, 0));

	public slots:
		void slot_sendChangeIO(int iIoNumber,int iCard);
protected:
	virtual void run();
private:
	
};

#endif // MOTION_THREAD_H
