#pragma once

#include <QObject>
#include <QThread>

class DialogEx;

class DialogEx_thread : public QThread
{
	Q_OBJECT

public:
	DialogEx_thread(QObject *parent);
	~DialogEx_thread();

	DialogEx *m_parent;

signals:
	void sig_sendClose();
	void sig_clear(int inx);
	void sig_setStyle(int inx,QString strStyle,QString strText=QString());
protected:
	virtual void run();
};
