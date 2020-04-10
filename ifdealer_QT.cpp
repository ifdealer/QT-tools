#include "ifdealer_QT.h"
#include "Dialog.h"
#include<opencv2/opencv.hpp>
using namespace cv;
ifdealer_QT::ifdealer_QT(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.PT1, &QPushButton::clicked, this, &ifdealer_QT::SelectFile);
	//connect(ui.PT1,&QPushButton::clicked, &filed,&fileDialog::SelectFile);
}	

void ifdealer_QT::SelectFile() {
	QFileDialog::getOpenFileName(this, "Ñ¡ÔñÍ¼Æ¬", "/", "Image Files(*.jpg *.png)");
}