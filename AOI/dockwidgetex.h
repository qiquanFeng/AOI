#ifndef DOCKWIDGETEX_H
#define DOCKWIDGETEX_H

#include <QDockWidget>
#include <QString>

class DockWidgetEx : public QDockWidget
{
	Q_OBJECT

public:
	DockWidgetEx(QString strTitle, QWidget *parent=nullptr);
	~DockWidgetEx();

protected:
	virtual void resizeEvent(QResizeEvent *event);
private:
	
};

#endif // DOCKWIDGETEX_H
