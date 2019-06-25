#pragma once

#include <QWidget>
#include "ui_widResult.h"

class widResult : public QWidget
{
	Q_OBJECT

public:
	widResult(QWidget *parent = Q_NULLPTR);
	~widResult();

private:
	Ui::widResult ui;
};
