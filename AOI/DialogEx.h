#pragma once

#include <QDialog>
#include "ui_DialogEx.h"
#include <QLabel>
#include <QLayout>
#include <QThread>
#include "labelex.h"
#include "DialogEx_thread.h"
#include <QMutex>
#include <qpushbutton.h>

class DialogEx : public QDialog
{
	Q_OBJECT

public:
	DialogEx(QWidget *parent = Q_NULLPTR);
	~DialogEx();
	LabelEx lab1;
	LabelEx lab2;
	LabelEx lab3;
	QPushButton butClear;
	QPushButton butCommit;

	DialogEx_thread thr1;
	QMutex mutex_key;
	bool bFirstKey;
	QString str_temp;
	QStringList strLotNum;

	__inline QStringList getStrLotNum() {
		return strLotNum;
	}
	__inline void clearStrLotNum() {
		lab1.clear();
		lab2.clear();
		lab3.clear();
		lab1.setStyleSheet("background-color:white;");
		lab2.setStyleSheet("background-color:white;");
		lab3.setStyleSheet("background-color:white;");
		return strLotNum.clear();
	}
	
	
	int curPos;
	QVBoxLayout lay;

	public slots:
	void slot_clear(QLabel *);
	void slot_setStyle(int inx,QString strStyle, QString strText);
	void slot_clear();
	void slot_closeWindown();
	void slot_commit();
protected:
	void keyPressEvent(QKeyEvent *);
private:
	Ui::DialogEx ui;
};
