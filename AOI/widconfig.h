#pragma once

#include <QWidget>
#include "ui_widconfig.h"

class widconfig : public QWidget
{
	Q_OBJECT

public:
	widconfig(QWidget *parent = Q_NULLPTR);
	~widconfig();

private:
	Ui::widconfig ui;
};
