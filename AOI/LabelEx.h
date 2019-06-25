#pragma once

#include <QLabel>
#include "ui_LabelEx.h"

class LabelEx : public QLabel
{
	Q_OBJECT

public:
	LabelEx(QString text,QWidget *parent = Q_NULLPTR);
	~LabelEx();

signals:
	void sig_doubleClick(QLabel *);
protected:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
private:
	Ui::LabelEx ui;
};
