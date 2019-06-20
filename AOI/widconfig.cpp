#include "widconfig.h"
#include <QSqlDatabase>
#include "aoi.h"

widconfig::widconfig(QWidget *parent)
	: QWidget(nullptr), m_parent((QObject*)parent)
{
	ui.setupUi(this);
	
	connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(slot_listWidDoubleClicked(QListWidgetItem*)));
	connect(ui.pushButton_add, SIGNAL(clicked()), this, SLOT(slot_configAdd()));
	connect(ui.pushButton_del, SIGNAL(clicked()), this, SLOT(slot_configDel()));
	connect(ui.pushButton_save, SIGNAL(clicked()), this, SLOT(slot_configSave()));
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
:ORG_Speed_LoadX,:ORG_Speed_LoadZ,:ORG_Speed_unLoadZ,:ORG_Speed_TestX,:ORG_Speed_TestY,:ORG_Speed_TestX2)");
	query.bindValue(":configName", ui.lineEdit_configName->text());
	query.bindValue(":boxRows", ui.boxRows->value());
	query.bindValue(":boxMargin", ui.boxMargin->value());
	query.bindValue(":boxPadding", ui.boxPadding->value());
	query.bindValue(":plateRows", ui.plateRows->value());
	query.bindValue(":plateCols", ui.plateCols->value());
	query.bindValue(":plateRowPadding", ui.plateRowPadding->value());
	query.bindValue(":plateColPadding", ui.plateColPadding->value());
	query.bindValue(":loadSpeed_Z", ui.loadSpeed_Z->value());
	query.bindValue(":loadPos_Z", ui.loadPos_Z->value());
	query.bindValue(":loadSpeed_X", ui.loadSpeed_X->value());
	query.bindValue(":loadPos_X", ui.loadPos_X->value());
	query.bindValue(":loadSpeed_Y", ui.loadSpeed_Y->value());
	query.bindValue(":loadPos_Y", ui.loadPos_Y->value());
	query.bindValue(":unLoadSpeed_Z", ui.unLoadSpeed_Z->value());
	query.bindValue(":unLoadPos_Z", ui.unLoadPos_Z->value());
	query.bindValue(":unLoadSpeed_X", ui.unLoadSpeed_X->value());
	query.bindValue(":unLoadPos_X", ui.unLoadPos_X->value());
	query.bindValue(":unLoadSpeed_Y", ui.unLoadSpeed_Y->value());
	query.bindValue(":unLoadPos_Y", ui.unLoadPos_Y->value());
	query.bindValue(":testFirstPos_X", ui.testFirstPos_X->value());
	query.bindValue(":testFirstPos_Y", ui.testFirstPos_Y->value());
	query.bindValue(":testSpeed", ui.testSpeed->value());

	AOI *aoi=(AOI*)m_parent;
	query.bindValue(":ORG_Speed_LoadX", aoi->m_config.lORG_Speed_LoadX);
	query.bindValue(":ORG_Speed_LoadZ", aoi->m_config.lORG_Speed_LoadZ);
	query.bindValue(":ORG_Speed_unLoadZ", aoi->m_config.lORG_Speed_unLoadZ);
	query.bindValue(":ORG_Speed_TestX", aoi->m_config.lORG_Speed_TestX);
	query.bindValue(":ORG_Speed_TestY", aoi->m_config.lORG_Speed_TestY);
	query.bindValue(":ORG_Speed_TestX2", aoi->m_config.lORG_Speed_TestX2);

	if (!query.exec()) {
		emit sig_logOutput("Add Config Fail:" + query.lastError().text(),QColor(255,0,0));
		return;
	}
	updateConfig(aoi->m_config);
	slot_updatelist();
}
void widconfig::slot_configDel() {
	QSqlQuery query(m_db);
	QList<QListWidgetItem*> list= ui.listWidget->selectedItems();
	if (!query.exec("delete from AOI_config where configName='" + list.at(0)->text() + "'")) {
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
:loadSpeed_Z,:loadPos_Z,:loadSpeed_X,:loadPos_X,:loadSpeed_Y,:loadPos_Y,\
:unLoadSpeed_Z,:unLoadPos_Z,:unLoadSpeed_X,:unLoadPos_X,:unLoadSpeed_Y,:unLoadPos_Y,:testFirstPos_X,:testFirstPos_Y,:testSpeed,\
:ORG_Speed_LoadX,:ORG_Speed_LoadZ,:ORG_Speed_unLoadZ,:ORG_Speed_TestX,:ORG_Speed_TestY,:ORG_Speed_TestX2)");
	query.bindValue(":configName", strConfigName);
	query.bindValue(":boxRows", ui.boxRows->value());
	query.bindValue(":boxMargin", ui.boxMargin->value());
	query.bindValue(":boxPadding", ui.boxPadding->value());
	query.bindValue(":plateRows", ui.plateRows->value());
	query.bindValue(":plateCols", ui.plateCols->value());
	query.bindValue(":plateRowPadding", ui.plateRowPadding->value());
	query.bindValue(":plateColPadding", ui.plateColPadding->value());
	query.bindValue(":loadSpeed_Z", ui.loadSpeed_Z->value());
	query.bindValue(":loadPos_Z", ui.loadPos_Z->value());
	query.bindValue(":loadSpeed_X", ui.loadSpeed_X->value());
	query.bindValue(":loadPos_X", ui.loadPos_X->value());
	query.bindValue(":loadSpeed_Y", ui.loadSpeed_Y->value());
	query.bindValue(":loadPos_Y", ui.loadPos_Y->value());
	query.bindValue(":unLoadSpeed_Z", ui.unLoadSpeed_Z->value());
	query.bindValue(":unLoadPos_Z", ui.unLoadPos_Z->value());
	query.bindValue(":unLoadSpeed_X", ui.unLoadSpeed_X->value());
	query.bindValue(":unLoadPos_X", ui.unLoadPos_X->value());
	query.bindValue(":unLoadSpeed_Y", ui.unLoadSpeed_Y->value());
	query.bindValue(":unLoadPos_Y", ui.unLoadPos_Y->value());
	query.bindValue(":testFirstPos_X", ui.testFirstPos_X->value());
	query.bindValue(":testFirstPos_Y", ui.testFirstPos_Y->value());
	query.bindValue(":testSpeed", ui.testSpeed->value());

	AOI *aoi = (AOI*)m_parent;
	query.bindValue(":ORG_Speed_LoadX", aoi->m_config.lORG_Speed_LoadX);
	query.bindValue(":ORG_Speed_LoadZ", aoi->m_config.lORG_Speed_LoadZ);
	query.bindValue(":ORG_Speed_unLoadZ", aoi->m_config.lORG_Speed_unLoadZ);
	query.bindValue(":ORG_Speed_TestX", aoi->m_config.lORG_Speed_TestX);
	query.bindValue(":ORG_Speed_TestY", aoi->m_config.lORG_Speed_TestY);
	query.bindValue(":ORG_Speed_TestX2", aoi->m_config.lORG_Speed_TestX2);

	if (!query.exec()) {
		emit sig_logOutput("Add Config Fail:" + query.lastError().text(), QColor(255, 0, 0));
		return;
	}

	slot_updatelist();
	emit sig_logOutput("Save Success!", QColor(0, 255, 0));
	
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
	ui.loadSpeed_Z->setValue(query.value("loadSpeed_Z").toInt());
	ui.unLoadPos_Z->setValue(query.value("loadPos_Z").toInt());
	ui.loadSpeed_X->setValue(query.value("loadSpeed_X").toInt());
	ui.loadPos_X->setValue(query.value("loadPos_X").toInt());
	ui.loadSpeed_Y->setValue(query.value("loadSpeed_Y").toInt());
	ui.loadPos_Y->setValue(query.value("loadPos_Y").toInt());
	ui.unLoadSpeed_Z->setValue(query.value("unLoadSpeed_Z").toInt());
	ui.unLoadPos_Z->setValue(query.value("unLoadPos_Z").toInt());
	ui.unLoadSpeed_X->setValue(query.value("unLoadSpeed_X").toInt());
	ui.unLoadPos_X->setValue(query.value("unLoadPos_X").toInt());
	ui.unLoadSpeed_Y->setValue(query.value("unLoadSpeed_Y").toInt());
	ui.unLoadPos_Y->setValue(query.value("unLoadPos_Y").toInt());
	ui.testFirstPos_X->setValue(query.value("testFirstPos_X").toInt());
	ui.testFirstPos_Y->setValue(query.value("testFirstPos_Y").toInt());
	ui.testSpeed->setValue(query.value("testSpeed").toInt());
	query.value("ORG_Speed_LoadX");
	query.value("ORG_Speed_LoadZ");
	query.value("ORG_Speed_unLoadZ");
	query.value("ORG_Speed_TestX");
	query.value("ORG_Speed_TestY");
	query.value("ORG_Speed_TestX2");
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