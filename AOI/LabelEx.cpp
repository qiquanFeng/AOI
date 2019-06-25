#include "LabelEx.h"
#include <QKeyEvent>

LabelEx::LabelEx(QString text, QWidget *parent)
	: QLabel(parent)
{
	ui.setupUi(this);
}

LabelEx::~LabelEx()
{
}

void LabelEx::mouseDoubleClickEvent(QMouseEvent *event) {
	//QKeyEvent keyEvt(QEvent::Type::KeyPress, Qt::Key_Return,Qt::KeyboardModifier::NoModifier);
	//QApplication::sendEvent(this, &keyEvt);
	if (text() == "" || text().size() == 0)
		return;

	emit sig_doubleClick(this);
}