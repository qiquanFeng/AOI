#pragma once

#include <QWidget>
#include <QDockWidget>
#include "ui_widconfig.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDialog>

struct srt_config {
	// 配置名称
	char pConfigName[256];

	// 弹夹相关
	int iBoxRows;
	int iBoxMargin; //mm
	int iBoxPadding; //mm

	//  载板相关
	int iPlateRows;
	int iPlatCols;
	int iPlatRowPadding;
	int iPlatColPadding;

	// 上料
	long lLoadSpeed_Z;
	long lLoadPos_Z;
	long lLoadSpeed_X;
	long lLoadPos_X;
	long lLoadSpeed_Y;
	long lLoadPos_Y;

	//下料
	long lunLoadSpeed_Z;
	long lunLoadPos_Z;
	long lunLoadSpeed_X;
	long lunLoadPos_X;
	long lunLoadSpeed_Y;
	long lunLoadPos_Y;

	// 测试
	long lTestFirstPos_X;
	long lTestFirstPos_Y;
	long lTestSpeed;

	//回零
	long lORG_Speed_LoadX;
	long lORG_Speed_LoadZ;
	long lORG_Speed_unLoadZ;
	long lORG_Speed_TestX;
	long lORG_Speed_TestY;
	long lORG_Speed_TestX2;

	srt_config() {
		memset(pConfigName, 0, 256);

		iBoxRows=10;
		iBoxMargin=30; //mm
		iBoxPadding=12.5; //mm
						  
		iPlateRows=0;
		iPlatCols=0;
		iPlatRowPadding=0;
		iPlatColPadding=0;

		// 上料
		lLoadSpeed_Z=1040000;
		lLoadPos_Z=40000;
		lLoadSpeed_X=-140000;
		lLoadPos_X=20000;
		lLoadSpeed_Y= 20000;
		lLoadPos_Y= 88600;

		//下料
		lunLoadSpeed_Z=40000;
		lunLoadPos_Z=-1010000;
		lunLoadSpeed_X=40000;
		lunLoadPos_X=-340000;
		lunLoadSpeed_Y=20000;
		lunLoadPos_Y=88600;

		lORG_Speed_LoadX=20000;
		lORG_Speed_LoadZ=80000;
		lORG_Speed_unLoadZ=80000;
		lORG_Speed_TestX=40000;
		lORG_Speed_TestY=20000;
		lORG_Speed_TestX2=3000;
	}
};


class widconfig : public QDialog
{
	Q_OBJECT

public:
	widconfig(QWidget *parent = Q_NULLPTR);
	~widconfig();
	void updateConfig(srt_config&);
	QSqlDatabase m_db;
	QObject *m_parent;
	

signals:
	void sig_logOutput(QString text, QColor color = QColor(0, 0, 0));

	public slots:
	void slot_listWidDoubleClicked(QListWidgetItem* item);
	void slot_configAdd();
	void slot_configDel();
	void slot_configSave();
	void slot_configFit();
	void slot_updatelist();
	
	
private:
	Ui::widconfig ui;
};
