#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_ifdealer_QT.h"


#include <qdialog.h>
#include <qstring.h>
#include <qfiledialog.h>


class ifdealer_QT : public QMainWindow
{
	Q_OBJECT

public:
	ifdealer_QT(QWidget* parent = Q_NULLPTR);

private:
	Ui::ifdealer_QTClass ui;
	QString filestr;
	
private slots:
	void SelectFile();
	
};
