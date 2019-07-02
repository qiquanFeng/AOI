#include "aoi.h"
#include <QHBoxLayout>
#include <QPushButton>

AOI::AOI(QWidget *parent)
	: QMainWindow(parent), m_labStatus(""), m_widDebug(tr("Operation Pannel"), "operation"), m_widOutputPannel(tr("OutputPannel"), "outpannel"), \
	m_widFrame(tr("Preview Frame"), "frame"), m_widOutIOStatus(tr("Out IO Status"), "outpannel"), m_widLotNum(tr("LotNum"), "lot"), m_widResult(tr("Result"), "result"), m_result(new widResult), \
	m_widInIOStatus(tr("In IO Status"), "instatus"), m_widCameraStatus(tr("Camera Status"), "camerastatus"), m_widStatus(tr("Status"), "status"), m_widOperater(tr("Operater"), "operater"), m_diaAuto(new DialogEx(this)), m_labImage(""),
	m_labConfigName(m_configName), m_butLoad(tr("load")), m_butUnLoad(tr("unload")), m_butRun(tr("run")), m_butReset(tr("reset")), m_butAuto(tr("auto")), m_butSuspended(tr("suspended")), \
	m_butStop(tr("stop")), m_tabOutIOStatus(2, 16), m_tabInIOStatus(2, 16), uiRows(3), uiColumns(11), axisdebug(this)
{
	ui.setupUi(this);

	m_widconfig=new widconfig(this);

	QThread *thr1 = new QThread();
	th = new Motion_thread(this);
	th->moveToThread(thr1);
	thr1->start();
	th->start();

	for (int i = 0; i < 16; i++)
	{
		m_butOutIO_Card0[i] = new PushButtonEx("", i, 0);
		m_butOutIO_Card1[i] = new PushButtonEx("", i, 1);
		m_butInIO_Card0[i] = new PushButtonEx("", i, 0,false);
		m_butInIO_Card1[i] = new PushButtonEx("", i, 1, false);

		m_tabOutIOStatus.setCellWidget(0, i, m_butOutIO_Card0[i]);
		m_tabOutIOStatus.setCellWidget(1, i, m_butOutIO_Card1[i]);
		m_tabInIOStatus.setCellWidget(0, i, m_butInIO_Card0[i]);
		m_tabInIOStatus.setCellWidget(1, i, m_butInIO_Card1[i]);

		connect(m_butOutIO_Card0[i], SIGNAL(sig_sendIO(int,int)), th, SLOT(slot_sendChangeIO(int, int)));
		connect(m_butOutIO_Card1[i], SIGNAL(sig_sendIO(int, int)), th, SLOT(slot_sendChangeIO(int, int)));
	}
	connect(this, SIGNAL(sig_resetAxis()),th,SLOT(slot_resetAxis()));
	connect(this, SIGNAL(sig_load()), th, SLOT(slot_load()));
	connect(this, SIGNAL(sig_unload()), th, SLOT(slot_unload()));
	connect(this, SIGNAL(sig_test()), th, SLOT(slot_test()));
	connect(this, SIGNAL(sig_auto()), th, SLOT(slot_auto()));
	connect(m_diaAuto, SIGNAL(sig_commit(QStringList)), th, SLOT(slot_auto(QStringList)));
	connect(th, SIGNAL(sig_setLot(int)), m_diaAuto, SLOT(slot_setLot(int)));
	connect(this, SIGNAL(sig_Suspended()), th, SLOT(slot_Suspended()));

	connect(&m_butStop, SIGNAL(pressed()), this, SLOT(slot_butStop()));

	connect(this, SIGNAL(sig_updateResult(bool bresult, int iPannel, int iSample, int timeProcess, QString strPath, QString strMD5)),\
		m_result, SLOT(slot_update(bool bresult, int iPannel, int iSample, int timeProcess, QString strPath, QString strMD5)));
	connect(this, SIGNAL(sig_updateResult(bool,int,int,int,QString,QString)), m_result, SLOT(slot_update(bool, int, int, int, QString, QString)));
	connect(this, SIGNAL(sig_axisChange(int,int,long)), &axisdebug, SLOT(slot_axisUpdate(int,int,long)));
	//*****************************
	setChildsAttribute();
	createLayout();
	m_labImage.setFixedSize(750,500);

	

	QFile fileStyle("qstyle");
	fileStyle.open(QIODevice::ReadOnly);
	setStyleSheet(QString(fileStyle.readAll()));
	fileStyle.close();

	applyLayout();

	emit sig_updateResult(true,1,1,123,"test","testMD5");
}

AOI::~AOI()
{
	slot_butStop();
	saveLayout();
}

void AOI::resizeEvent(QResizeEvent *event) {
	event->size();
}
void AOI::keyPressEvent(QKeyEvent *evt){
	switch (evt->key()) {
	case Qt::Key_Space:
		slot_butStop();
		break;
	}
}

int AOI::createLayout(){
	this->centralWidget()->setHidden(true);

	m_butReset.setEnabled(false);

	//****  Out IO Tab **********************************
	m_tabOutIOStatus.setHorizontalHeaderLabels(QStringList() << "0" << "1" << "2" << "3" << "4" << "5" << "6"\
		<< "7" << "8" << "9" << "10" << "11" << "12" << "13" << "14"<<"15");
	m_tabOutIOStatus.setVerticalHeaderLabels(QStringList() << "Card0" << "Card1");
	m_tabOutIOStatus.resizeRowsToContents();
	m_tabOutIOStatus.resizeColumnsToContents();
	m_tabOutIOStatus.setFocusPolicy(Qt::NoFocus);
	m_tabOutIOStatus.setEditTriggers(QAbstractItemView::NoEditTriggers);
	m_tabOutIOStatus.setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	m_tabOutIOStatus.setSelectionMode(QAbstractItemView::SingleSelection);

	//******************** In IO ******************************************
	m_tabInIOStatus.setHorizontalHeaderLabels(QStringList() << "0" << "1" << "2" << "3" << "4" << "5" << "6"\
		<< "7" << "8" << "9" << "10" << "11" << "12" << "13" << "14" << "15");
	m_tabInIOStatus.setVerticalHeaderLabels(QStringList() << "Card0" << "Card1");
	m_tabInIOStatus.resizeRowsToContents();
	m_tabInIOStatus.resizeColumnsToContents();
	m_tabInIOStatus.setFocusPolicy(Qt::NoFocus);
	m_tabInIOStatus.setEditTriggers(QAbstractItemView::NoEditTriggers);
	m_tabInIOStatus.setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	m_tabInIOStatus.setSelectionMode(QAbstractItemView::SingleSelection);

	//******************** Camera Status **************************************************************
	m_tabCameraStatus.setRowCount(m_config.iPlateRows);
	m_tabCameraStatus.setColumnCount(m_config.iPlatCols);
	for (int r = 0; r < m_config.iPlateRows; r++)
	{
		for (int c = 0; c < m_config.iPlatCols; c++)
		{
			m_tabCameraStatus.setItem(r,c,new QTableWidgetItem);
			m_tabCameraStatus.item(r, c)->setBackground(QColor(255, 255, 255));
		}
	}
	
	m_tabCameraStatus.resizeRowsToContents();
	m_tabCameraStatus.resizeColumnsToContents();
	m_tabCameraStatus.setFocusPolicy(Qt::NoFocus);
	m_tabCameraStatus.setEditTriggers(QAbstractItemView::NoEditTriggers);
	m_tabCameraStatus.setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	m_tabCameraStatus.setSelectionMode(QAbstractItemView::SingleSelection);

	//****************** Operation Pannel**************************
	QWidget *widOperation = new QWidget();
	widOperation->setLayout(&m_hLayout1);
	//m_vLayout1.addWidget(&m_butLoad);
	//m_vLayout1.addWidget(&m_butUnLoad);
	//m_vLayout1.addWidget(&m_butRun);
	m_hLayout1.addWidget(&m_butReset);
	m_hLayout1.addWidget(&m_butAuto);
	m_hLayout1.addWidget(&m_butSuspended);
	m_hLayout1.addWidget(&m_butStop);
	

	//*********************************************
	m_widOperater.setWidget(widOperation);
	m_widFrame.setWidget(&m_labImage); m_widFrame.setFeatures(QDockWidget::DockWidgetFeature::DockWidgetFloatable);
	m_widOutputPannel.setWidget(&m_editLog);
	m_widOutIOStatus.setWidget(&m_tabOutIOStatus);
	m_widInIOStatus.setWidget(&m_tabInIOStatus);
	m_widCameraStatus.setWidget(&m_tabCameraStatus);
	
	m_widResult.setWidget(m_result);
	m_widLotNum.setWidget(m_diaAuto);
	//****************** Layout *********************
	addDockWidget(Qt::LeftDockWidgetArea, &m_widFrame);
	addDockWidget(Qt::BottomDockWidgetArea, &m_widOutputPannel);
	addDockWidget(Qt::BottomDockWidgetArea, &m_widOperater);
	addDockWidget(Qt::RightDockWidgetArea, &m_widResult);
	addDockWidget(Qt::TopDockWidgetArea, &m_widLotNum);
	addDockWidget(Qt::TopDockWidgetArea, &m_widCameraStatus);

	//addDockWidget(Qt::TopDockWidgetArea, &m_widOutIOStatus);
	//addDockWidget(Qt::TopDockWidgetArea, &m_widInIOStatus);

	slot_updateImage("15-03-01_Testing_1_23.jpg");
	//********************** Menu *******************
	m_actOption = new QAction(tr("&Option"));
	
	m_actInputIO = new QAction(tr("inIO"));
	m_actOutputIO = new QAction(tr("outIO"));
	m_actDebug = new QAction(tr("Debug"));
	m_actCameraPosition = new QAction(tr("CamPos"));
	//m_actInputIO->setCheckable(true);
	//m_actOutputIO->setCheckable(true);
	//m_actDebug->setCheckable(true);

	QMenu *menSetting=menuBar()->addMenu(tr("setting"));
	menuBar()->addMenu(tr("tool"));
	QMenu *menMode=menuBar()->addMenu(tr("model"));
	menuBar()->addMenu(tr("help"));
	menSetting->addAction(m_actOption);
	menMode->addAction(m_actInputIO);
	menMode->addAction(m_actOutputIO);
	menMode->addAction(m_actDebug);
	menMode->addAction(m_actCameraPosition);

	connect(m_actOption, SIGNAL(triggered()), this, SLOT(slot_Option()));
	connect(m_actInputIO, SIGNAL(triggered()), this, SLOT(slot_actIOIN()));
	connect(m_actOutputIO, SIGNAL(triggered()), this, SLOT(slot_actIOOut()));
	connect(m_actDebug, SIGNAL(triggered()), this, SLOT(slot_actDebug()));
	connect(m_actCameraPosition, SIGNAL(triggered()), this, SLOT(slot_actCamPos()));

	return 0;
}
int AOI::setChildsAttribute() {
	axisdebug.hide();
	m_labStatus.setFixedWidth(500);
	QWidget *wid = new QWidget;
	ui.mainToolBar->addWidget(wid);
	QHBoxLayout *phlay = new QHBoxLayout;
	wid->setLayout(phlay);
	phlay->addWidget(&m_labStatus);
	phlay->addWidget(&m_labConfigName);


	//m_labStatus.setFixedSize(400, 120);

	m_editLog.setReadOnly(true);

	connect(this, SIGNAL(sig_logOutput(QString, QColor)), this, SLOT(slot_outputLog(QString, QColor)),\
		Qt::ConnectionType::DirectConnection);
	connect(&m_butLoad, SIGNAL(pressed()), this, SLOT(slot_butLoad()));
	connect(&m_butUnLoad, SIGNAL(pressed()), this, SLOT(slot_butUnLoad()));
	connect(&m_butRun, SIGNAL(pressed()), this, SLOT(slot_butRun()));
	connect(&m_butReset, SIGNAL(pressed()), this, SLOT(slot_butReset()));
	connect(&m_butAuto, SIGNAL(pressed()), this, SLOT(slot_butAuto()));
	connect(&m_butSuspended, SIGNAL(pressed()), this, SLOT(slot_butSuspended()));
	return 0;
}
void AOI::slot_butLoad() {
	emit sig_load();
	setFocus();
}
void AOI::slot_butUnLoad() {
	emit sig_unload();
	setFocus();
}
void AOI::slot_butRun() {
	setFocus();
}
void AOI::slot_butReset() {
	m_actCameraPosition->setEnabled(false);
	th->m_bSuspended = false;
	th->m_bES = false;

	m_butAuto.setEnabled(false);
	emit sig_resetAxis();
	setFocus();

	m_butAuto.setEnabled(true);
	m_actCameraPosition->setEnabled(TRUE);
};
void AOI::slot_butAuto() {
	emit sig_load();
	while (!th->m_bAutoMode) {
		QApplication::processEvents();
	}

	m_diaAuto->setEnabled(true);
	m_diaAuto->lab1.clear();
	m_diaAuto->lab2.clear();
	m_diaAuto->lab3.clear();
	m_diaAuto->strLotNum.clear();

	m_butAuto.setEnabled(false);
	m_butReset.setEnabled(false);
	m_diaAuto->setFocus();
}
void AOI::slot_butStop() {
	emit sig_logOutput(tr("Emergency Stop!"),QColor(255,0,0));
	slot_setStatus(tr("Emergency Stop!"), "color:red;");
	dmc_stop(0, 0, 1);
	dmc_stop(0, 1, 1);
	dmc_stop(0, 2, 1);
	dmc_stop(1, 0, 1);
	dmc_stop(1, 1, 1);
	dmc_stop(1, 2, 1);
	th->m_bES = true;
	th->m_bSuspended = false;
	setFocus();
	m_butAuto.setEnabled(true);
	m_butReset.setEnabled(true);
}
void AOI::slot_butSuspended() {
	slot_setStatus(tr("pause"), "color:Black;");
	th->m_bSuspended = !th->m_bSuspended;
	emit sig_Suspended();

	m_butAuto.setEnabled(false);
	if (th->m_bSuspended){
		m_butSuspended.setText(tr("continue"));
	m_butReset.setEnabled(true);
	}
	else{
		m_butSuspended.setText(tr("pause"));
	}
	
	setFocus();
}

void AOI::slot_outputLog(QString text,QColor color) {
	m_editLog.setTextColor(color);
	QTime time = QTime::currentTime();
	m_editLog.append(time.toString("hh:mm:ss:zzz ")+text);
}
void AOI::slot_IOChangeInfo(int iIoNumber, int iCard,bool bIn, int status) {
	if (bIn) {
		if (iCard == 0) {
			m_butInIO_Card0[iIoNumber]->slot_statusChange(status);
		}
		else {
			m_butInIO_Card1[iIoNumber]->slot_statusChange(status);
		}
	}
	else {
		if (iCard == 0) {
			m_butOutIO_Card0[iIoNumber]->slot_statusChange(status);
		}
		else {
			m_butOutIO_Card1[iIoNumber]->slot_statusChange(status);
		}
	}
	
}
void AOI::slot_Option() {
	m_widconfig->setModal(true);
	m_widconfig->exec();
}
void AOI::slot_actIOIN() {
		m_widInIOStatus.setParent(this);
		m_widInIOStatus.setFloating(true);
		m_widInIOStatus.setFixedSize(580, 90);
		m_widInIOStatus.show();
		m_widInIOStatus.setFeatures(QDockWidget::DockWidgetClosable);
		m_widInIOStatus.setAllowedAreas(Qt::DockWidgetArea::NoDockWidgetArea);
		m_widInIOStatus.move(300, 300);

}
void AOI::slot_actIOOut() {
		m_widOutIOStatus.setParent(this);
		m_widOutIOStatus.setFloating(true);
		m_widOutIOStatus.setFixedSize(580, 90);
		m_widOutIOStatus.show();
		m_widOutIOStatus.setFeatures(QDockWidget::DockWidgetClosable);
		m_widOutIOStatus.setAllowedAreas(Qt::DockWidgetArea::NoDockWidgetArea);
		m_widOutIOStatus.move(100, 100);
}
void AOI::slot_actDebug() {
		axisdebug.setParent(this);
		axisdebug.setFloating(true);
		axisdebug.setFixedSize(650, 70);
		axisdebug.show();
		axisdebug.setAllowedAreas(Qt::DockWidgetArea::NoDockWidgetArea);
		axisdebug.move(200, 200);
}
void AOI::slot_actCamPos() {
	if (th->m_bAutoMode) {
		emit sig_logOutput(tr("Fail:auto mode running!"),QColor(255,0,0));
		return;
	}

	m_butAuto.setEnabled(false);
	m_butReset.setEnabled(false);

	dmc_write_outbit(0, 0, 1);
	dmc_write_outbit(0, 1, 0);
	dmc_write_outbit(1, 5, 1);
	dmc_write_outbit(1, 6, 1);
	dmc_write_outbit(1, 7, 1);
	dmc_write_outbit(0, 2, 1);
	dmc_write_outbit(1, 4, 1);

	th->axis_move(0, 1, m_config.lLoadSpeed_Y, 1, m_config.lLoadPos_Y, 0, false);
	th->axis_move(0, 0, m_config.lORG_Speed_TestX, 1, 0, 1, false);
	th->axis_move(0, 2, m_config.lORG_Speed_TestX2, 0, 0, 1, false);
	th->axis_move(1, 1, m_config.lunLoadSpeed_Z, 1, m_config.lunLoadPos_Z, 0, false);
	th->axis_move(1, 2, m_config.lORG_Speed_LoadX, 0, 0, 1, true);
	th->axis_move(1, 0, m_config.lLoadSpeed_Z, 1, m_config.lLoadPos_Z, 0, true);
		
	if (th->m_bES)
		return;

	short status = 0;

	th->axis_move(0, 0, m_config.lORG_Speed_TestX, 1, 0, 1, true);
	th->axis_move(0, 2, m_config.lORG_Speed_TestX2, 0, 0, 1, true);

	//********** ¼ì²âÁÏºÐ *************************************
	slot_setStatus(tr("Check Load Box"), "color:black;");
	do {
		sleep(10);
		status = dmc_read_inbit(1, 9);
	} while (!status);

	slot_setStatus(tr("Check unLoad Box"), "color:black;");
	do {
		status = dmc_read_inbit(1, 5);
	} while (!status);
	slot_setStatus(tr("running"), "color:green;");

	th->axis_move(1, 2, m_config.lLoadSpeed_X, 1, m_config.lLoadPos_X, 0, true);

	th->axis_move(1, 2, m_config.lORG_Speed_LoadX, 0, 0, 1, true);

	// ************************** ¼ÐÁÏ 
	th->axis_move(1, 2, 20000, 0, 0, 1, false);
		dmc_write_outbit(0, 0, 0);
		th->axis_move(0, 2, 2000, 1, -9000);
		dmc_write_outbit(0, 0, 1);
		th->axis_move(0, 2, 2000, 0, 0, 1);
		dmc_write_outbit(0, 0, 0);
		th->axis_move(0, 2, 1000, 0, -5000, 0, false);
		do {
			status = dmc_read_inbit(0, 2);
			if (dmc_check_done(0, 2)) {
				emit sig_logOutput(QString::fromLocal8Bit("ÔØ°åÉÏÁÏ¼ì²âÊ§°Ü£¡"));
				slot_setStatus(tr("Load Plate Fail!"), "color:red;");
				th->m_bES = true;
				return;
			}
		} while (status);
		dmc_stop(0, 2, 1);
		sleep(500);
		dmc_write_outbit(0, 1, 1);
		sleep(500);
		dmc_write_outbit(0, 2, 0);
		dmc_write_outbit(0, 0, 1);

		th->axis_move(0, 0, m_config.lORG_Speed_TestX, 1, m_config.lTestFirstPos_X, 0, false);
		th->axis_move(0, 1, m_config.lORG_Speed_TestY, 1, m_config.lTestFirstPos_Y, 0, false);

		do {
			status = 1;
			if (dmc_check_done(0, 0) == 0 || dmc_check_done(0, 1) == 0) {
				status = 0;
			}
		} while (!status);

	m_butAuto.setEnabled(true);
	m_butReset.setEnabled(true);
}

void AOI::slot_updateImage(QString strPath) {
	QFile file(strPath);
	file.open(QIODevice::ReadOnly);
	QByteArray arrBuf = file.readAll();
	m_labImage.setPixmap(QPixmap::fromImage(QImage(strPath)));
	m_labImage.setScaledContents(true);
	file.close();
}
void AOI::slot_setStatus(QString status,QString strStyle) {
	m_labStatus.setText(status);
	m_labStatus.setStyleSheet(strStyle);
}
void AOI::slot_setCameraResult(int row,int col,int result) {

	if (row == 0xFF&&col==0xFF) {
		for (int r = 0; r < m_tabCameraStatus.rowCount(); r++) {
			for (int c = 0; c < m_tabCameraStatus.columnCount(); c++) {
				m_tabCameraStatus.item(r, c)->setBackground(QColor(255, 255, 255));
			}
		}
		return;
	}

	int c = std::floor(row % m_tabCameraStatus.columnCount());
	int r = std::ceil(row / m_tabCameraStatus.columnCount());

	switch (result) {
	case 0:
		m_tabCameraStatus.item(r, c)->setBackground(QColor(255, 0, 0));
		break;
	case 1:
		m_tabCameraStatus.item(r, c)->setBackground(QColor(0, 255, 0));
		break;
	case 2:
		m_tabCameraStatus.item(r, c)->setBackground(QColor(255, 255, 0));
		break;
	}
}