#include "axisDebug.h"
#include "aoi.h"

axisDebug::axisDebug(QWidget *parent)
	: QDockWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_stop, SIGNAL(pressed()), parent, SLOT(slot_butStop()));
	connect(ui.pushButton_start, SIGNAL(pressed()), this, SLOT(slot_start()));
}

axisDebug::~axisDebug()
{
}

void axisDebug::slot_start() {
	dmc_set_profile(ui.comboBox_card->currentIndex(), ui.comboBox_axis->currentIndex(), ui.spinBox_speed->value(), ui.spinBox_speed->value(), 0.1, 0.1, 0);
	dmc_pmove(ui.comboBox_card->currentIndex(), ui.comboBox_axis->currentIndex(), ui.spinBox_target->value(), ui.comboBox_mode->currentIndex());
}

void axisDebug::slot_axisUpdate(int card,int axis,long pos) {
	switch (card)
	{
	case 0:
		switch (axis) {
		case 0:
			ui.label_C0A0->setText("COAO__"+QString::number(pos));
			break;
		case 1:
			ui.label_C0A1->setText("COA1__" + QString::number(pos));
			break;
		case 2:
			ui.label_C0A2->setText("COA2__" + QString::number(pos));
			break;
		}
		break;
	case 1:
		switch (axis) {
		case 0:
			ui.label_C1A0->setText("C1AO__" + QString::number(pos));
			break;
		case 1:
			ui.label_C1A1->setText("C1A1__" + QString::number(pos));
			break;
		case 2:
			ui.label_C1A2->setText("C1A2__" + QString::number(pos));
			break;
		}
		break;
	}
}
