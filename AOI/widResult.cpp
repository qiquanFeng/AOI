#include "widResult.h"

widResult::widResult(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.lab_imagepath->setStyleSheet("font: 75 12pt ""Î¢ÈíÑÅºÚ"";");

}

widResult::~widResult()
{
}

void widResult::slot_update(bool bresult, int iPannel, int iSample, int timeProcess, QString strPath, QString strMD5) {
	if (bresult) {
		ui.lab_result->setText("OK");
		ui.lab_result->setStyleSheet("background-color:green;");
	}
	else
	{
		ui.lab_result->setText("NG");
		ui.lab_result->setStyleSheet("background-color:red;");
	}
		

	if(iPannel)
		ui.lab_pannel->setText(QString::number(iPannel));
	if(iSample)
		ui.lab_sampleposition->setText(QString::number(iSample));

	if(timeProcess)
		ui.lab_processtime->setText(QString::number(timeProcess));

	if (strPath.size() > 0) {
		ui.lab_imagepath->setText(strPath);
	}
		

	if (strMD5.size()>0)
		ui.lab_MD5->setText(strMD5);
}