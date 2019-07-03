#ifndef ABOUTDIA_H
#define ABOUTDIA_H

#include <QDialog>
#include "ui_aboutdia.h"

class aboutDia : public QDialog
{
	Q_OBJECT

public:
	aboutDia(QWidget *parent = 0);
	~aboutDia();

private:
	Ui::aboutDia ui;
};

#endif // ABOUTDIA_H
