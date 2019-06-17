#ifndef MOTION_THREAD_H
#define MOTION_THREAD_H

#include <QThread>
#include "Library/Leisai/LTDMC.h"
#include <QColor>
#include <Windows.h>

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
	int axis_move(int card, int axis, int speed, int absMode,int target, int orgMode = 0,bool bAck=true);
signals:
	void sig_statusChange(int iIoNumber, int iCard,int status);
	void sig_logOutput(QString text, QColor color = QColor(0, 0, 0));

	public slots:
		void slot_sendChangeIO(int iIoNumber,int iCard);
		void slot_resetAxis();

		void slot_load();
		void slot_test();
		void slot_unload();
		void slot_MatrixMove(int row,int col, double rowMargin, double colMargin);
protected:
	virtual void run();
private:
	bool m_bES;//¼±Í£×´Ì¬
	int m_CardNum;
	QString configFilePath[2];

	
	
};

#endif // MOTION_THREAD_H
