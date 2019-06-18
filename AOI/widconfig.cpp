#include "widconfig.h"
#include <QSqlDatabase>

widconfig::widconfig(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QSqlDatabase db;
	if (QSqlDatabase::contains("qt_sql_default_connection"))
		db = QSqlDatabase::database("qt_sql_default_connection");
	else
	{
		db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("./config/datebase.db");
	}
	if (!db.open())
	{
		//QMessageBox::warning(this, "Error", QString::fromLocal8Bit("不能打开数据库！"));
		//emit sigWarnningLogAdd(QString::fromLocal8Bit("不能打开数据库！"));
		//emit sigLogAdd(QString::fromLocal8Bit("不能打开数据库！"));
		return;
	}
}

widconfig::~widconfig()
{
}
