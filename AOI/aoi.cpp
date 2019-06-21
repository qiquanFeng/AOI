#include "aoi.h"
#include <QHBoxLayout>
#include <QPushButton>

AOI::AOI(QWidget *parent)
	: QMainWindow(parent), m_widDebug(tr("Operation Pannel")),m_widOutputPannel(tr("OutputPannel")), \
	m_widFrame(tr("Preview Frame")), m_widOutIOStatus(tr("Out IO Status")),\
	m_widInIOStatus(tr("In IO Status")), m_widCameraStatus(tr("Camera Status")),m_labImage(""),
	m_butLoad(tr("load")), m_butUnLoad(tr("unload")), m_butRun(tr("run")), m_butReset(tr("reset")), m_butAuto(tr("auto")), m_butSuspended(tr("suspended")),\
	m_tabOutIOStatus(2,16), m_tabInIOStatus(2,16), uiRows(3), uiColumns(11)
{
	ui.setupUi(this);

	m_widconfig=new widconfig(this);

	QThread *thr1 = new QThread();
	Motion_thread *th = new Motion_thread(this);
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
	connect(this, SIGNAL(sig_Suspended()), th, SLOT(slot_Suspended()));
	//*****************************
	setChildsAttribute();
	createLayout();
	m_labImage.setFixedSize(800,600);

	

	QFile fileStyle("qstyle");
	fileStyle.open(QIODevice::ReadOnly);
	setStyleSheet(QString(fileStyle.readAll()));
	fileStyle.close();

	applyLayout();
}

AOI::~AOI()
{
	saveLayout();
}

void AOI::resizeEvent(QResizeEvent *event) {
	event->size();
}

int AOI::createLayout(){
	this->centralWidget()->setHidden(true);
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
	m_tabCameraStatus.resizeRowsToContents();
	m_tabCameraStatus.resizeColumnsToContents();
	m_tabCameraStatus.setFocusPolicy(Qt::NoFocus);
	m_tabCameraStatus.setEditTriggers(QAbstractItemView::NoEditTriggers);
	m_tabCameraStatus.setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	m_tabCameraStatus.setSelectionMode(QAbstractItemView::SingleSelection);

	//****************** Operation Pannel**************************
	QWidget *widOperation = new QWidget();
	widOperation->setLayout(&m_vLayout1);
	m_vLayout1.addWidget(&m_butLoad);
	m_vLayout1.addWidget(&m_butUnLoad);
	m_vLayout1.addWidget(&m_butRun);
	m_vLayout1.addWidget(&m_butReset);
	m_vLayout1.addWidget(&m_butAuto);
	m_vLayout1.addWidget(&m_butSuspended);
	m_vLayout1.addStretch(10);

	//*********************************************
	m_widDebug.setWidget(widOperation);
	m_widFrame.setWidget(&m_labImage);
	m_widOutputPannel.setWidget(&m_editLog);
	m_widOutIOStatus.setWidget(&m_tabOutIOStatus);
	m_widInIOStatus.setWidget(&m_tabInIOStatus);
	m_widCameraStatus.setWidget(&m_tabCameraStatus);
	//****************** Layout *********************
	addDockWidget(Qt::LeftDockWidgetArea, &m_widFrame);
	addDockWidget(Qt::BottomDockWidgetArea, &m_widOutputPannel);
	addDockWidget(Qt::RightDockWidgetArea, &m_widDebug);
	addDockWidget(Qt::TopDockWidgetArea, &m_widOutIOStatus);
	addDockWidget(Qt::TopDockWidgetArea, &m_widInIOStatus);
	addDockWidget(Qt::BottomDockWidgetArea, &m_widCameraStatus);

	slot_updateImage("D:/sf/images/04_25/10-01-09_0P_1_14.jpg");
	//********************** Menu *******************
	m_actOption = new QAction(tr("&Option"));
	QMenu *menSetting=menuBar()->addMenu("setting");
	menSetting->addAction(m_actOption);

	connect(m_actOption, SIGNAL(triggered()), this, SLOT(slot_Option()));

	return 0;
}
int AOI::setChildsAttribute() {
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
}
void AOI::slot_butUnLoad() {
	emit sig_unload();
}
void AOI::slot_butRun() {
	emit sig_test();
}
void AOI::slot_butReset() {
	emit sig_resetAxis();
};
void AOI::slot_butAuto() {
	emit sig_logOutput("auto");
	QMessageBox::warning(this, "warning", "test","OK","NG","cencal");
	emit sig_auto();
}
void AOI::slot_butSuspended() {
	emit sig_logOutput("Suspended");
	emit sig_Suspended();
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

void AOI::slot_updateImage(QString strPath) {
	QFile file(strPath);
	file.open(QIODevice::ReadOnly);
	QByteArray arrBuf = file.readAll();
	m_labImage.setPixmap(QPixmap::fromImage(QImage(strPath)));
	m_labImage.setScaledContents(true);
	file.close();
}