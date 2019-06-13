#include "aoi.h"
#include <QHBoxLayout>
#include <QPushButton>

AOI::AOI(QWidget *parent)
	: QMainWindow(parent), m_widDebug(tr("Debug")), m_widFrame(tr("Preview Frame"),this),m_labImage(""),
	butLoad(tr("load")),butUnLoad(tr("unload")),butRun(tr("run"))
{
	ui.setupUi(this);

	setChildsAttribute();
	createLayout();
	m_labImage.setFixedSize(800,600);

	QFile file("001.bmp");
	file.open(QIODevice::ReadOnly);
	QByteArray arrBuf=file.readAll();
	m_labImage.setPixmap(QPixmap::fromImage(QImage((uchar*)arrBuf.data(),2608,1960,QImage::Format_RGB888)));
	m_labImage.setScaledContents(true);
	file.close();

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
	m_widFrame.setWidget(&m_labImage);
	//****************** Layout *********************
	addDockWidget(Qt::LeftDockWidgetArea, &m_widFrame);
	addDockWidget(Qt::LeftDockWidgetArea, &m_widDebug);

	QWidget *wid = new QWidget();
	m_widDebug.setWidget(wid);
	wid->setLayout(&m_vLayout1);
	m_vLayout1.addWidget(&butLoad);
	m_vLayout1.addWidget(&butUnLoad);
	m_vLayout1.addWidget(&butRun);
	m_vLayout1.addStretch(10);

	//********************** Menu *******************
	m_actOption = new QAction(tr("&Option"));
	menuBar()->addAction(m_actOption);


	return 0;
}
int AOI::setChildsAttribute() {
	m_widFrame.setFeatures(m_widFrame.features()&~QDockWidget::DockWidgetClosable);
	m_widDebug.setFeatures(m_widDebug.features()&~QDockWidget::DockWidgetClosable);
	return 0;
}
