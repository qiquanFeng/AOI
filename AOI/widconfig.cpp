#include "widconfig.h"
#include <QSqlDatabase>
#include "aoi.h"
#include <qcheckbox.h>

widconfig::widconfig(QWidget *parent)
	: QDialog(parent), m_parent((QObject*)parent)
{
	ui.setupUi(this);

	connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(slot_listWidDoubleClicked(QListWidgetItem*)));
	connect(ui.pushButton_add, SIGNAL(clicked()), this, SLOT(slot_configAdd()));
	connect(ui.pushButton_del, SIGNAL(clicked()), this, SLOT(slot_configDel()));
	connect(ui.pushButton_save, SIGNAL(clicked()), this, SLOT(slot_configSave()));
	connect(ui.pushButton_save2, SIGNAL(clicked()), this, SLOT(slot_mechanicalConfigSave()));
	connect(ui.pushButton_fit, SIGNAL(clicked()), this, SLOT(slot_configFit()));
	connect(this,&widconfig::sig_logOutput, (AOI*)parent, &AOI::slot_outputLog);

	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName("database.db");
	if (!m_db.open())
	{
		emit sig_logOutput(QString::fromLocal8Bit("打开数据库失败！"));
		return;
	}

	ui.listWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	ui.listWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	slot_updatelist();
}

widconfig::~widconfig()
{
	m_db.close();
}
void widconfig::slot_listWidDoubleClicked(QListWidgetItem* item) {
	QSqlQuery query(m_db);
	if (!query.exec("update current_config set configName='" + item->text() + "'")) {
		emit sig_logOutput("Load Config Fail:" + query.lastError().text(), QColor(255, 0, 0));
		return;
	}

	slot_updatelist();
	emit sig_logOutput("load config success",QColor(0,255,0));
}
void widconfig::slot_configAdd() {
	QSqlQuery query(m_db);
	query.prepare("insert into AOI_config values(:configName,:boxRows,:boxMargin,:boxPadding,:plateRows,:plateCols,:plateRowPadding,:plateColPadding,\
:loadSpeed_Z,:loadPos_Z,:loadSpeed_X,:loadPos_X,:loadSpeed_Y,:loadPos_Y,\
:unLoadSpeed_Z,:unLoadPos_Z,:unLoadSpeed_X,:unLoadPos_X,:unLoadSpeed_Y,:unLoadPos_Y,:testFirstPos_X,:testFirstPos_Y,:testSpeed,\
:ORG_Speed_LoadX,:ORG_Speed_LoadZ,:ORG_Speed_unLoadZ,:ORG_Speed_TestX,:ORG_Speed_TestY,:ORG_Speed_TestX2,:penPos_X,:penPos_Y,:penOffset,:penE)");
	query.bindValue(":configName", ui.lineEdit_configName->text());
	query.bindValue(":boxRows", ui.boxRows->value());
	query.bindValue(":boxMargin", ui.boxMargin->value());
	query.bindValue(":boxPadding", ui.boxPadding->value());
	query.bindValue(":plateRows", ui.plateRows->value());
	query.bindValue(":plateCols", ui.plateCols->value());
	query.bindValue(":plateRowPadding", ui.plateRowPadding->value());
	query.bindValue(":plateColPadding", ui.plateColPadding->value());
	query.bindValue(":testFirstPos_X", ui.testFirstPos_X->value());
	query.bindValue(":testFirstPos_Y", ui.testFirstPos_Y->value());
	query.bindValue(":penPos_X", ui.pen_X->value());
	query.bindValue(":penPos_Y", ui.pen_Y->value());
	query.bindValue(":penOffset", ui.pen_offset->value());
	query.bindValue(":penE", ui.checkBox_pen->isChecked());

	if (!query.exec()) {
		emit sig_logOutput("Add Config Fail:" + query.lastError().text(),QColor(255,0,0));
		return;
	}

	AOI *aoi=(AOI*)m_parent;
	updateConfig(aoi->m_config);
	slot_updatelist();
}
void widconfig::slot_configDel() {
	QSqlQuery query(m_db);
	if (!query.exec("select configName from current_config where 1")) {
		emit sig_logOutput("save config fail:" + query.lastError().text());
	}
	query.next();
	QString strConfigName = query.value("configName").toString();
	if (!query.exec("delete from AOI_config where configName='" + strConfigName + "'")) {
		emit sig_logOutput("delete config fail:" + query.lastError().text());
	}

	slot_updatelist();
}
void widconfig::slot_configSave() {
	QSqlQuery query(m_db);
	if (!query.exec("select configName from current_config where 1")) {
		emit sig_logOutput("save config fail:" + query.lastError().text());
	}
	query.next();
	QString strConfigName=query.value("configName").toString();

	if (!query.exec("delete from AOI_config where configName='" + strConfigName + "'")) {
		emit sig_logOutput("update config fail:" + query.lastError().text(),QColor(255,0,0));
		return;
	}

	query.prepare("insert into AOI_config values(:configName,:boxRows,:boxMargin,:boxPadding,:plateRows,:plateCols,:plateRowPadding,:plateColPadding,\
:testFirstPos_X,:testFirstPos_Y,:penPos_X,:penPos_Y,:penOffset,:penEnable)");
	query.bindValue(":configName", strConfigName);
	query.bindValue(":boxRows", ui.boxRows->value());
	query.bindValue(":boxMargin", ui.boxMargin->value());
	query.bindValue(":boxPadding", ui.boxPadding->value());
	query.bindValue(":plateRows", ui.plateRows->value());
	query.bindValue(":plateCols", ui.plateCols->value());
	query.bindValue(":plateRowPadding", ui.plateRowPadding->value());
	query.bindValue(":plateColPadding", ui.plateColPadding->value());
	query.bindValue(":testFirstPos_X", ui.testFirstPos_X->value());
	query.bindValue(":testFirstPos_Y", ui.testFirstPos_Y->value());
	query.bindValue(":penPos_X", ui.pen_X->value());
	query.bindValue(":penPos_Y", ui.pen_Y->value());
	query.bindValue(":penOffset", ui.pen_offset->value());
	query.bindValue(":penEnable", ui.checkBox_pen->isChecked());

	if (!query.exec()) {
		emit sig_logOutput("Save Config Fail:" + query.lastError().text(), QColor(255, 0, 0));
		return;
	}

	slot_updatelist();
	emit sig_logOutput("Save Success!", QColor(0, 255, 0));
	
}
void widconfig::slot_mechanicalConfigSave() {
	QSqlQuery query(m_db);
	query.exec("delete from mechanical_config where 1");
	query.prepare("insert into mechanical_config values(:loadX_Speed,:loadY_Speed,:loadZ_Speed,:loadX_Pos,:loadY_Pos,:loadZ_Pos,\
:unLoadX_Speed,:unLoadY_Speed,:unLoadZ_Speed,:unLoadX_Pos,:unLoadY_Pos,:unLoadZ_Pos,:testSpeed,:clawSpeed,:lORG_Speed_LoadZ,\
:lORG_Speed_unLoadZ,:lORG_Speed_LoadX,:lORG_Speed_TestX,:lORG_Speed_TestY,:lORG_Speed_TestX2)");
	query.bindValue(":loadX_Speed", ui.loadSpeed_X->value());
	query.bindValue(":loadY_Speed", ui.loadSpeed_Y->value());
	query.bindValue(":loadZ_Speed", ui.loadSpeed_Z->value());
	query.bindValue(":loadX_Pos", ui.loadPos_X->value());
	query.bindValue(":loadY_Pos", ui.loadPos_Y->value());
	query.bindValue(":loadZ_Pos", ui.loadPos_Z->value());
	query.bindValue(":unLoadX_Speed", ui.unLoadSpeed_X->value());
	query.bindValue(":unLoadY_Speed", ui.unLoadSpeed_Y->value());
	query.bindValue(":unLoadZ_Speed", ui.unLoadSpeed_Z->value());
	query.bindValue(":unLoadX_Pos", ui.unLoadPos_X->value());
	query.bindValue(":unLoadY_Pos", ui.unLoadPos_Y->value());
	query.bindValue(":unLoadZ_Pos", ui.unLoadPos_Z->value());
	query.bindValue(":testSpeed", ui.testSpeed->value());
	query.bindValue(":clawSpeed", ui.testClawSpeed->value());
	query.bindValue(":lORG_Speed_LoadZ", ui.org_load_speed->value());
	query.bindValue(":lORG_Speed_unLoadZ", ui.org_unload_speed->value());
	query.bindValue(":lORG_Speed_LoadX", ui.org_push_speed->value());
	query.bindValue(":lORG_Speed_TestX", ui.org_testX_speed->value());
	query.bindValue(":lORG_Speed_TestY", ui.org_testY_speed->value());
	query.bindValue(":lORG_Speed_TestX2", ui.org_testX2_speed->value());

	if (!query.exec()) {
		emit sig_logOutput("Add Config Fail:" + query.lastError().text(), QColor(255, 0, 0));
		return;
	}

	slot_updatelist();
	emit sig_logOutput("mechanical Save Success!", QColor(0, 255, 0));
}

void widconfig::slot_configFit() {
	QSqlQuery query(m_db);
	query.exec("select configName from AOI_config where configName like '%"+ui.lineEdit_configName->text()+"%'");

	ui.listWidget->clear();
	while (query.next()) {
		ui.listWidget->addItem(query.value("configName").toString());
	}
}
void widconfig::slot_updatelist() {
	QSqlQuery query(m_db);
	query.exec("select configName from AOI_config where 1");

	ui.listWidget->clear();
	while (query.next()) {
		ui.listWidget->addItem(query.value("configName").toString());
	}

	//****************** load ********************************************
	query.exec("select configName from current_config where 1");
	if (!query.next())
		return;

	QString currentConfig = query.value("configName").toString();
	QList<QListWidgetItem*> list = ui.listWidget->findItems(currentConfig, Qt::MatchFlag::MatchExactly);
	if (!list.size())
		return;
	ui.listWidget->setItemSelected(list.at(0), true);
	ui.listWidget->setCurrentItem(list.at(0));
	list.at(0)->setTextColor(QColor(0, 255, 0));

	query.exec("select * from AOI_config where configName='" + currentConfig + "'");
	if (!query.next())
		return;

	ui.boxRows->setValue(query.value("boxRows").toInt());
	ui.boxMargin->setValue(query.value("boxMargin").toDouble());
	ui.boxPadding->setValue(query.value("boxPadding").toDouble());
	ui.plateRows->setValue(query.value("plateRows").toInt());
	ui.plateCols->setValue(query.value("plateCols").toInt());
	ui.plateRowPadding->setValue(query.value("plateRowPadding").toDouble());
	ui.plateColPadding->setValue(query.value("plateColPadding").toDouble());
	ui.checkBox_pen->setChecked(query.value("penEnable").toBool());
	ui.pen_X->setValue(query.value("penPos_X").toInt());
	ui.pen_Y->setValue(query.value("penPos_Y").toDouble());
	ui.pen_offset->setValue(query.value("penOffset").toDouble());
	ui.testFirstPos_X->setValue(query.value("testFirstPos_X").toInt());
	ui.testFirstPos_Y->setValue(query.value("testFirstPos_Y").toInt());

	((AOI*)m_parent)->m_tabCameraStatus.setRowCount(query.value("plateRows").toInt());
	((AOI*)m_parent)->m_tabCameraStatus.setColumnCount(query.value("plateCols").toInt());
	((AOI*)m_parent)->m_tabCameraStatus.resizeRowsToContents();
	((AOI*)m_parent)->m_tabCameraStatus.resizeColumnsToContents();
	((AOI*)m_parent)->m_configName = getCurrentConfigName();
	((AOI*)m_parent)->m_labConfigName.setText(tr("Model Code:")+((AOI*)m_parent)->m_configName);

	for (int r = 0; r < query.value("plateRows").toInt(); r++)
	{
		for (int c = 0; c < query.value("plateCols").toInt(); c++)
		{
			((AOI*)m_parent)->m_tabCameraStatus.setItem(r, c, new QTableWidgetItem);
			((AOI*)m_parent)->m_tabCameraStatus.item(r, c)->setBackground(QColor(255,255,255));
		}
	}

	query.exec("select * from mechanical_config where 1");
	if (!query.next())
		return;
	ui.loadSpeed_Z->setValue(query.value("loadZ_Speed").toInt());
	ui.loadPos_Z->setValue(query.value("loadZ_Pos").toInt());
	ui.loadSpeed_X->setValue(query.value("loadX_Speed").toInt());
	ui.loadPos_X->setValue(query.value("loadX_Pos").toInt());
	ui.loadSpeed_Y->setValue(query.value("loadY_Speed").toInt());
	ui.loadPos_Y->setValue(query.value("loadY_Pos").toInt());
	ui.unLoadSpeed_Z->setValue(query.value("unLoadZ_Speed").toInt());
	ui.unLoadPos_Z->setValue(query.value("unLoadZ_Pos").toInt());
	ui.unLoadSpeed_X->setValue(query.value("unLoadX_Speed").toInt());
	ui.unLoadPos_X->setValue(query.value("unLoadX_Pos").toInt());
	ui.unLoadSpeed_Y->setValue(query.value("unLoadY_Speed").toInt());
	ui.unLoadPos_Y->setValue(query.value("unLoadY_Pos").toInt());
	ui.testSpeed->setValue(query.value("testSpeed").toInt());
	ui.testClawSpeed->setValue(query.value("clawSpeed").toInt());
	ui.org_push_speed->setValue(query.value("lORG_Speed_LoadX").toInt());
	ui.org_load_speed->setValue(query.value("lORG_Speed_LoadZ").toInt());
	ui.org_unload_speed->setValue(query.value("lORG_Speed_unLoadZ").toInt());
	ui.org_testX_speed->setValue(query.value("lORG_Speed_TestX").toInt());
	ui.org_testY_speed->setValue(query.value("lORG_Speed_TestY").toInt());
	ui.org_testX2_speed->setValue(query.value("lORG_Speed_TestX2").toInt());

	updateConfig(((AOI*)m_parent)->m_config);
}
QString widconfig::getCurrentConfigName() {
	QSqlQuery query(m_db);
	query.exec("select configName from current_config where 1");
	if (!query.next())
		return "";

	return query.value("configName").toString();
}

void widconfig::updateConfig(srt_config &config) {
	sprintf(config.pConfigName,"%s",ui.lineEdit_configName->text().toLatin1().data());
	config.iBoxRows=ui.boxRows->value();
	config.iBoxMargin = ui.boxMargin->value();
	config.iBoxPadding = ui.boxPadding->value();
	config.iPlatColPadding = ui.plateColPadding->value();
	config.iPlatCols = ui.plateCols->value();
	config.iPlateRows = ui.plateRows->value();
	config.iPlatRowPadding= ui.plateRowPadding->value();
	config.bEnablePen = ui.checkBox_pen->isChecked();
	config.iPenPos_X= ui.pen_X->value();
	config.iPenPos_Y = ui.pen_Y->value();
	config.iPenOffset = ui.pen_offset->value();
	config.lLoadPos_X = ui.loadPos_X->value();
	config.lLoadPos_Y = ui.loadPos_Y->value();
	config.lLoadPos_Z = ui.loadPos_Z->value();
	config.lLoadSpeed_X = ui.loadSpeed_X->value();
	config.lLoadSpeed_Y = ui.loadSpeed_Y->value();
	config.lLoadSpeed_Z = ui.loadSpeed_Z->value();
	config.lunLoadPos_X = ui.unLoadPos_X->value();
	config.lunLoadPos_Y = ui.unLoadPos_Y->value();
	config.lunLoadPos_Z = ui.unLoadPos_Z->value();
	config.lunLoadSpeed_X = ui.unLoadSpeed_X->value();
	config.lunLoadSpeed_Y = ui.unLoadSpeed_Y->value();
	config.lunLoadSpeed_Z = ui.unLoadSpeed_Z->value();
	config.lTestFirstPos_X = ui.testFirstPos_X->value();
	config.lTestFirstPos_Y = ui.testFirstPos_Y->value();
	config.lTestSpeed = ui.testSpeed->value();
}