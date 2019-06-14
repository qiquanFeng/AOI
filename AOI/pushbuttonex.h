#ifndef PUSHBUTTONEX_H
#define PUSHBUTTONEX_H

#include <QPushButton>
#include <QWidget>

class PushButtonEx : public QPushButton
{
	Q_OBJECT

public:
	PushButtonEx(QString text,int ioNumber,int card,QWidget *parent=nullptr);
	~PushButtonEx();

signals:
	void sig_sendIO(int ioNumber,int card);

	public slots:
	void slot_pressed();
	void slot_statusChange(int);
private:
	int m_iCardNumber;
	int m_iIONumber;
	int m_iStatus;
	
};

#endif // PUSHBUTTONEX_H
