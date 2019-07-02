#pragma once

#include <QDockWidget>
#include "ui_axisDebug.h"

class axisDebug : public QDockWidget
{
	Q_OBJECT

public:
	axisDebug(QWidget *parent = Q_NULLPTR);
	~axisDebug();

	public slots:
	void slot_start();
	void slot_axisUpdate(int,int,long);
private:
	Ui::axisDebug ui;
};
