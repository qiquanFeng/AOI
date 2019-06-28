#include "axisDebug.h"
#include "aoi.h"

axisDebug::axisDebug(QWidget *parent)
	: QDockWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_stop, SIGNAL(pressed()), parent, SLOT(slot_butStop()));
}

axisDebug::~axisDebug()
{
}

void axisDebug::slot_start() {
	dmc_set_profile(ui.comboBox_card->currentIndex(), ui.comboBox_axis->currentIndex(), ui.spinBox_speed->value(), ui.spinBox_speed->value(), 0.1, 0.1, 0);
	dmc_pmove(ui.comboBox_card->currentIndex(), ui.comboBox_axis->currentIndex(), ui.spinBox_target->value(), ui.comboBox_mode->currentIndex());
}
