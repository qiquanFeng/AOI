#include "aoi.h"
#include <QtWidgets/QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QLocale locale;
	QTranslator translator;
	switch (locale.language())
	{
	case QLocale::Chinese:
		translator.load("aoi_zh.qm");
		a.installTranslator(&translator);
		break;
	default:
		break;
	}

	AOI w;
	w.show();
	return a.exec();
}
