#ifndef AOI_H
#define AOI_H

#include <QtWidgets/QMainWindow>
#include "ui_aoi.h"
#include <QFile>
#include <QAction>
#include <QLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QDockWidget>
#include <QResizeEvent>
#include "dockwidgetex.h"
#include <QTextEdit>
#include <QSettings>
#include <QTableWidget>
#include "./rapidjson/rapidjson.h"
#include "./rapidjson/document.h"
#include "interface.h"
#include "pushbuttonex.h"
#include "motion_thread.h"
#include "widconfig.h"
#include <Windows.h>
#include <QListWidget>
#include <QMessageBox>
#include "dialogex.h"
#include "widresult.h"

class AOI : public QMainWindow
{
	Q_OBJECT

public:
	AOI(QWidget *parent = 0);
	~AOI();
	QListWidget wid;

	Motion_thread *th;

signals:
	void sig_logOutput(QString text, QColor color = QColor(0, 0, 0));
	void sig_resetAxis();
	void sig_load();
	void sig_unload();
	void sig_auto();
	void sig_Suspended();

	void sig_updateResult(bool bresult, int iPannel, int iSample, int timeProcess, QString strPath, QString strMD5);

	public slots:
	void slot_outputLog(QString,QColor);
	void slot_butLoad();
	void slot_butUnLoad();
	void slot_butRun();
	void slot_butReset();
	void slot_butAuto();
	void slot_butSuspended();
protected:
	virtual void resizeEvent(QResizeEvent *event);
	void keyPressEvent(QKeyEvent *);

public:
	srt_config m_config;
	//**  Menu Bar ****************
	QAction *m_actOption;
	widconfig *m_widconfig;
	DialogEx *m_diaAuto;
	widResult *m_result;

	//**  QGroupBox ***************
	DockWidgetEx m_widOutputPannel;
	DockWidgetEx m_widDebug;
	DockWidgetEx m_widFrame;
	DockWidgetEx m_widOutIOStatus;
	DockWidgetEx m_widInIOStatus;
	DockWidgetEx m_widStatus;
	DockWidgetEx m_widCameraStatus;
	DockWidgetEx m_widLotNum;
	DockWidgetEx m_widResult;
	DockWidgetEx m_widOperater;
	

	//**  Layout ******************
	QHBoxLayout m_hLayout1;
	QVBoxLayout m_vLayout1;

	//**  TableView ***************
	QTableWidget m_tabOutIOStatus;
	QTableWidget m_tabInIOStatus;
	QTableWidget m_tabCameraStatus;

	//**  Button ******************
	QPushButton m_butLoad;
	QPushButton m_butUnLoad;
	QPushButton m_butRun;
	QPushButton m_butReset;
	QPushButton m_butAuto;
	QPushButton m_butSuspended;
	QPushButton m_butStop;

	PushButtonEx* m_butOutIO_Card0[16];
	PushButtonEx* m_butOutIO_Card1[16];
	PushButtonEx* m_butInIO_Card0[16];
	PushButtonEx* m_butInIO_Card1[16];

	//**  Label *******************
	QLabel m_labImage;
	QLabel m_labStatus;

	//**  QTextEdit *****************
	QTextEdit m_editLog;

	//**  Mothods *******************
	int setChildsAttribute();
	int createLayout();

	
private:
	Ui::AOIClass ui;
	

	unsigned int uiRows;
	unsigned int uiColumns;

	__inline void saveLayout() {
		QSettings settings("layout.ini",QSettings::Format::IniFormat);
		settings.setValue("geometry", saveGeometry());
		settings.setValue("windowState", saveState());
	}

	__inline void applyLayout() {
		QSettings settings("layout.ini", QSettings::Format::IniFormat);
		restoreGeometry(settings.value("geometry").toByteArray());
		restoreState(settings.value("windowState").toByteArray());
		/*
		QList<QDockWidget *> dwList = this->findChildren<QDockWidget*>();
		foreach(QDockWidget *dw, dwList) {
			restoreDockWidget(dw);
		}*/
	}

	public slots:
	void slot_IOChangeInfo(int iIoNumber, int iCard, bool bIn, int status);
	void slot_Option();
	void slot_updateImage(QString strPath);
	void slot_butStop();
	void slot_setStatus(QString status,QString strStyle);
	void slot_setCameraResult(int row,int col,int result);


};

#endif // AOI_H
