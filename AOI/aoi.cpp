#include "aoi.h"
#include <QHBoxLayout>
#include <QPushButton>

AOI::AOI(QWidget *parent)
	: QMainWindow(parent), m_widDebug(tr("OutputPannel")), m_widFrame(tr("Preview Frame")), m_widIOStatus(tr("IO Status")), m_labImage(""),
	m_butLoad(tr("load")), m_butUnLoad(tr("unload")), m_butRun(tr("run")), m_butReset(tr("reset")), m_tabIOStatus(2,16), uiRows(3), uiColumns(11),
	m_widconfig(new widconfig(this))
{
	ui.setupUi(this);

	QThread *thr1 = new QThread();
	Motion_thread *th = new Motion_thread(this);
	th->moveToThread(thr1);
	thr1->start();
	th->start();

	for (int i = 0; i < 16; i++)
	{
		short status0 = dmc_read_outbit(0, i);
		short status1 = dmc_read_outbit(1, i);

		m_butIO_Card0[i] = new PushButtonEx("", i, 0);
		m_butIO_Card1[i] = new PushButtonEx("", i, 1);
		m_tabIOStatus.setCellWidget(0, i, m_butIO_Card0[i]);
		m_tabIOStatus.setCellWidget(1, i, m_butIO_Card1[i]);
		m_butIO_Card0[i]->slot_statusChange(status0);
		m_butIO_Card1[i]->slot_statusChange(status1);

		connect(m_butIO_Card0[i], SIGNAL(sig_sendIO(int,int)), th, SLOT(slot_sendChangeIO(int, int)));
		connect(m_butIO_Card1[i], SIGNAL(sig_sendIO(int, int)), th, SLOT(slot_sendChangeIO(int, int)));
		
	}
	connect(this, SIGNAL(sig_resetAxis()),th,SLOT(slot_resetAxis()));
	connect(this, SIGNAL(sig_load()), th, SLOT(slot_load()));
	connect(this, SIGNAL(sig_unload()), th, SLOT(slot_unload()));
	connect(this, SIGNAL(sig_test()), th, SLOT(slot_test()));
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
	//****  IO Tab **********************************
	m_tabIOStatus.setHorizontalHeaderLabels(QStringList() << "0" << "1" << "2" << "3" << "4" << "5" << "6"\
		<< "7" << "8" << "9" << "10" << "11" << "12" << "13" << "14"<<"15");
	m_tabIOStatus.setVerticalHeaderLabels(QStringList() << "Card0" << "Card1");
	m_tabIOStatus.resizeRowsToContents();
	m_tabIOStatus.resizeColumnsToContents();
	m_tabIOStatus.setFocusPolicy(Qt::NoFocus);
	m_tabIOStatus.setEditTriggers(QAbstractItemView::NoEditTriggers);
	m_tabIOStatus.setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	m_tabIOStatus.setSelectionMode(QAbstractItemView::SingleSelection);

	m_widFrame.setWidget(&m_labImage);
	m_widDebug.setWidget(&m_editLog);
	m_widIOStatus.setWidget(&m_tabIOStatus);
	//****************** Layout *********************
	addDockWidget(Qt::LeftDockWidgetArea, &m_widFrame);
	addDockWidget(Qt::LeftDockWidgetArea, &m_widDebug);
	addDockWidget(Qt::TopDockWidgetArea, &m_widIOStatus);

	this->centralWidget()->setLayout(&m_vLayout1);
	m_vLayout1.addWidget(&m_butLoad);
	m_vLayout1.addWidget(&m_butUnLoad);
	m_vLayout1.addWidget(&m_butRun);
	m_vLayout1.addWidget(&m_butReset);
	
	m_vLayout1.addStretch(10);

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
void AOI::slot_outputLog(QString text,QColor color) {
	m_editLog.setTextColor(color);
	QTime time = QTime::currentTime();
	m_editLog.append(time.toString("hh:mm:ss:zzz ")+text);
}
void AOI::slot_IOChangeInfo(int iIoNumber, int iCard, int status) {
	if (iCard == 0) {
		m_butIO_Card0[iIoNumber]->slot_statusChange(status);
	}
	else {
		m_butIO_Card1[iIoNumber]->slot_statusChange(status);
	}
}
void AOI::slot_Option() {
	m_widconfig->show();
}

void AOI::slot_updateImage(QString strPath) {
	QFile file(strPath);
	file.open(QIODevice::ReadOnly);
	QByteArray arrBuf = file.readAll();
	m_labImage.setPixmap(QPixmap::fromImage(QImage(strPath)));
	m_labImage.setScaledContents(true);
	file.close();
}