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
	QObject *m_parent;
	QMutex *mutex1;
	bool m_bReceived;
	QThread *th1;

	QString m_strBoxID;
	int m_iPannelID;
	int m_iSampleID;

	bool m_bES;//¼±Í£×´Ì¬
	bool m_bSuspended;//ÔÝÍ£×´Ì¬
	bool m_bAutoMode;// ×Ô¶¯Ä£Ê½
	bool m_bResetMode;

	int motion_Init();
	int axis_move(int card, int axis, int speed, int absMode,int target, int orgMode = 0,bool bAck=true,bool bReset=false);
signals:
	void sig_statusChange(int iIoNumber, int iCard,bool bIn,int status);
	void sig_logOutput(QString text, QColor color = QColor(0, 0, 0));
	void sig_updateImage(QString strPath);
	void sig_predict();
	void sig_setStatus(QString, QString);

	void sig_testResult(int row, int col, int result);
	void sig_updateResult(bool bresult, int iPannel, int iSample, int timeProcess, QString strPath, QString strMD5);

	public slots:
		void slot_sendChangeIO(int iIoNumber,int iCard);
		void slot_resetAxis();
		int slot_writeOutIO(WORD card, WORD bitNo, WORD status,bool bReset=false);

		void slot_predict(QString boxID, int pannelID, int sampleID);
		void slot_load();
		void slot_test();
		void slot_unload();
		void slot_auto();
		void slot_Suspended();
		
		void slot_MatrixMove(int row,int col, double rowMargin, double colMargin, QString boxID, int pannelID);
		QString onReply(QNetworkReply *pReply);
protected:
	virtual void run();
private:
	

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
	void sig_testResult(int row, int col, int result);

	public slots:
	void slot_predict(QString boxID,int pannelID,int sampleID);
	QString onReply(QNetworkReply *pReply);
	QNetworkAccessManager* slot_sendPost(QByteArray buf, QUrl url, int port, QString contentType = QString("application/json"));
protected:
	virtual void run();

private:
	QNetworkAccessManager *m_pManager;
};
#endif // MOTION_THREAD_H
