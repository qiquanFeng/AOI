#ifndef MOTION_THREAD_H
#define MOTION_THREAD_H

#include <QThread>
#include "Library/Leisai/LTDMC.h"
#include <QColor>
#include <Windows.h>
#include "interface.h"
#include <QDateTime>
#include <QTime>
#include <qapplication.h>
#include <QMutex>

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
	QMutex *mutex1;
	bool m_bReceived;
	QThread *th1;

	int motion_Init();
	int axis_move(int card, int axis, int speed, int absMode,int target, int orgMode = 0,bool bAck=true);
signals:
	void sig_statusChange(int iIoNumber, int iCard,int status);
	void sig_logOutput(QString text, QColor color = QColor(0, 0, 0));
	void sig_updateImage(QString strPath);
	void sig_predict();

	public slots:
		void slot_sendChangeIO(int iIoNumber,int iCard);
		void slot_resetAxis();

		void slot_predict();
		void slot_load();
		void slot_test();
		void slot_unload();
		void slot_MatrixMove(int row,int col, double rowMargin, double colMargin);
		QString onReply(QNetworkReply *pReply);
protected:
	virtual void run();
private:
	bool m_bES;//¼±Í£×´Ì¬
	int m_CardNum;
	QString configFilePath[2];
	HTTP_Interface *m_HTTP_Interface;
};

class Motion_thread1 : public QThread
{
	Q_OBJECT
public:
	Motion_thread1(QObject *parent);
	~Motion_thread1();
	Motion_thread *m_parent;
	

	bool m_bReceived;
signals:
	void sig_logOutput(QString text, QColor color = QColor(0, 0, 0));

	public slots:
	void slot_predict();
	QString onReply(QNetworkReply *pReply);
	QNetworkAccessManager* slot_sendPost(QByteArray buf, QUrl url, int port, QString contentType = QString("application/json"));
protected:
	virtual void run();

private:
	QNetworkAccessManager *m_pManager;
};
#endif // MOTION_THREAD_H
