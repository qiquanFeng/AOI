#include "dockwidgetex.h"
#include <QResizeEvent>
#include "AOI.h"

DockWidgetEx::DockWidgetEx(QString strTitle,QWidget *parent)
	: QDockWidget(strTitle, parent)
{
	setFeatures(features()&~QDockWidget::DockWidgetClosable);
}

DockWidgetEx::~DockWidgetEx()
{

}

void DockWidgetEx::resizeEvent(QResizeEvent *event) {
	QFile file("001.bmp");
	file.open(QIODevice::ReadOnly);
	QByteArray arrBuf = file.readAll();
	((AOI*)parent())->m_labImage.setPixmap(QPixmap::fromImage(QImage((uchar*)arrBuf.data(), 2608, 1960, QImage::Format_RGB888)));
	((AOI*)parent())->m_labImage.setScaledContents(true);
	file.close();
	
	QSize size=event->size();
	QSize oldsize = event->oldSize();
	return;
}