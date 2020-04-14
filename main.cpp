#include "ifdealer_QT.h"
#include "processImage.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ifdealer_QT w;
	w.show();
	
	return a.exec();
}
