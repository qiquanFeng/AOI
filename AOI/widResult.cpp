#include "widResult.h"

widResult::widResult(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


}

widResult::~widResult()
{
}

void widResult::slot_update(bool bresult, int iPannel, int iSample, int timeProcess, QString strPath, QString strMD5) {
	if (bresult)
		ui.lab_result->setText("OK");
	else
		ui.lab_result->setText("NG");

	ui.lab_pannel->setText(QString::number(iPannel));
	ui.lab_sampleposition->setText(QString::number(iSample));
	ui.lab_processtime->setText(QString::number(timeProcess));
	ui.lab_imagepath->setText(strPath);
	ui.lab_MD5->setText(strMD5);
}