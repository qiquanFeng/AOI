#pragma once

#include <QDockWidget>
#include "ui_axisDebug.h"

class axisDebug : public QDockWidget
{
	Q_OBJECT

public:
	axisDebug(QWidget *parent = Q_NULLPTR);
	~axisDebug();

private:
	Ui::axisDebug ui;
};
