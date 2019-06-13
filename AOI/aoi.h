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

class AOI : public QMainWindow
{
	Q_OBJECT

public:
	AOI(QWidget *parent = 0);
	~AOI();

protected:
	virtual void resizeEvent(QResizeEvent *event);

public:
	//**  Menu Bar ****************
	QAction *m_actOption;

	//**  QGroupBox ***************
	QDockWidget m_widDebug;
	DockWidgetEx m_widFrame;

	//**  Layout ******************
	QHBoxLayout m_hLayout1;
	QVBoxLayout m_vLayout1;

	//**  Button ******************
	QPushButton butLoad;
	QPushButton butUnLoad;
	QPushButton butRun;

	//**  Label *******************
	QLabel m_labImage;

	//**  Mothods *******************
	int setChildsAttribute();
	int createLayout();

private:
	Ui::AOIClass ui;

	__inline void saveLayout() {
		QFile file("layout");
		file.open(QIODevice::ReadWrite);
		QDataStream out(&file);
		out << saveState();
		file.close();
	}

	__inline void applyLayout() {
		QFile file("layout");
		file.open(QIODevice::ReadWrite);
		QDataStream in(&file);
		QByteArray lay;
		in >> lay;
		restoreState(lay);
		file.close();
	}

	public slots:

};

#endif // AOI_H
