#include "DialogEx.h"
#include <QKeyEvent>
#include <QMessageBox>

DialogEx::DialogEx(QWidget *parent)
	: QDialog(parent), lab1(""), lab2(""), lab3(""), lab1_head(tr("LotNum1:")), lab2_head(tr("LotNum2:")), lab3_head(tr("LotNum3:")), bFirstKey(true),\
	thr1(this), butClear(tr("Clean")),butCommit(tr("Commit"))
{
	ui.setupUi(this);

	this->setLayout(&lay);

	QHBoxLayout *hlay1 = new QHBoxLayout;
	QHBoxLayout *hlay2 = new QHBoxLayout;
	QHBoxLayout *hlay3 = new QHBoxLayout;

	hlay1->addWidget(&lab1_head);
	hlay1->addWidget(&lab1,100,Qt::AlignLeft);
	hlay2->addWidget(&lab2_head);
	hlay2->addWidget(&lab2,100, Qt::AlignLeft);
	hlay3->addWidget(&lab3_head);
	hlay3->addWidget(&lab3,100, Qt::AlignLeft);

	lay.addLayout(hlay1);
	lay.addLayout(hlay2);
	lay.addLayout(hlay3);
	QHBoxLayout *pHlay = new QHBoxLayout;
	lay.addLayout(pHlay,50);
	pHlay->addWidget(&butCommit);
	pHlay->addWidget(&butClear);

	connect(&lab1, SIGNAL(sig_doubleClick(QLabel*)), this, SLOT(slot_clear(QLabel*)));
	connect(&lab2, SIGNAL(sig_doubleClick(QLabel*)), this, SLOT(slot_clear(QLabel*)));
	connect(&lab3, SIGNAL(sig_doubleClick(QLabel*)), this, SLOT(slot_clear(QLabel*)));

	connect(&butCommit, SIGNAL(pressed()), this, SLOT(slot_commit()));
	connect(&butClear, SIGNAL(pressed()), this, SLOT(slot_clear()));
	
	connect(&thr1, SIGNAL(sig_setStyle(int, QString,QString)), this, SLOT(slot_setStyle(int,QString,QString)));
	connect(&thr1, SIGNAL(sig_sendClose()), this, SLOT(slot_closeWindown()));

	setEnabled(false);
}


DialogEx::~DialogEx()
{
	
}

void DialogEx::keyPressEvent(QKeyEvent *evt) {
	int key = evt->key();
	if (key == Qt::Key_Return || key == Qt::Key_Enter)
		return;

	if (bFirstKey) {
		mutex_key.lock();
		bFirstKey = false;
		mutex_key.unlock();
		thr1.start();
	}
		
	str_temp.append(evt->text());
	int i;
}
void DialogEx::slot_clear(QLabel *pLab) {
	if (str_temp != "" && str_temp.size() != 0)
	strLotNum.append(str_temp);
	str_temp.clear();
	strLotNum.removeAt(strLotNum.lastIndexOf(pLab->text()));

	lab1.clear();
	lab2.clear();
	lab3.clear();

	lab1.setStyleSheet("background-color:white;");
	lab2.setStyleSheet("background-color:white;");
	lab3.setStyleSheet("background-color:white;");

	switch (strLotNum.size())
	{
	case 1:
		lab1.setText(strLotNum.at(0));
		lab1.setStyleSheet("background-color:green;");
		break;
	case 2:
		lab1.setText(strLotNum.at(0));
		lab2.setText(strLotNum.at(1));
		lab2.setStyleSheet("background-color:green;");
		lab1.setStyleSheet("background-color:green;");
		break;
	case 3:
		lab1.setText(strLotNum.at(0));
		lab2.setText(strLotNum.at(1));
		lab3.setText(strLotNum.at(2));
		lab3.setStyleSheet("background-color:green;");
		lab2.setStyleSheet("background-color:green;");
		lab1.setStyleSheet("background-color:green;");
		break;
	default:
		break;
	}
}
void DialogEx::slot_setStyle(int inx, QString strStyle, QString strText) {
	LabelEx *pLab = NULL;
	switch (inx) {
	case 1:
		pLab=&lab1;
		break;
	case 2:
		pLab = &lab2;
		break;
	case 3:
		pLab = &lab3;
		break;
	}

	pLab->setStyleSheet(strStyle);
	if(strText.size()!=0)
		pLab->setText(strText);
}
void DialogEx::slot_closeWindown() {
	thr1.exit();
	close();
}
void DialogEx::slot_clear() {
	lab1.setStyleSheet("background-color:white;");
	lab2.setStyleSheet("background-color:white;");
	lab3.setStyleSheet("background-color:white;");
	lab1.clear();
	lab2.clear();
	lab3.clear();
	strLotNum.clear();
}
void DialogEx::slot_commit() {


	if (strLotNum.size() <= 0) {
		return;
	}
	lab1.setStyleSheet("background-color:white;");
	lab2.setStyleSheet("background-color:white;");
	lab3.setStyleSheet("background-color:white;");
	setEnabled(false);

	emit sig_commit(strLotNum);
}

void DialogEx::slot_setLot(int lotNumber) {
	switch (lotNumber)
	{
	case 0:
		lab1.setStyleSheet("background-color:green;color:red;");
		break;
	case 1:
		lab2.setStyleSheet("background-color:green;color:red;");
		break;
	case 2:
		lab3.setStyleSheet("background-color:green;color:red;");
		break;
	}
}