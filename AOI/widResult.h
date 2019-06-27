#pragma once

#include <QWidget>
#include "ui_widResult.h"
#include <QTime>

class widResult : public QWidget
{
	Q_OBJECT

public:
	widResult(QWidget *parent = Q_NULLPTR);
	~widResult();

	bool bresult;
	int iPannel;
	int iSample;
	QTime timeProcess;
	QString strPath;
	QString strMD5;

	public slots:
	void slot_update(bool bresult, int iPannel, int iSample, int timeProcess, QString strPath, QString strMD5);
private:
	Ui::widResult ui;
};
