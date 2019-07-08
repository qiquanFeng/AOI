#pragma once

#include <QWidget>
#include "ui_widResult.h"
#include <QTime>
#include <QClipboard>

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
	__inline void slot_butMD5() {
		QClipboard *clipboard = QApplication::clipboard();
		clipboard->setText(ui.pushButton_MD5->text());
	}
	__inline void slot_butPath() {
		QClipboard *clipboard = QApplication::clipboard();
		clipboard->setText(ui.pushButton_imagepath->text());
	}
private:
	Ui::widResult ui;
};
