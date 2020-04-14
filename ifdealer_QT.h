#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_ifdealer_QT.h"

#include "imagectrl.h"
#include "processImage.h"
#include <qdialog.h>
#include <qstring.h>
#include <qfiledialog.h>
#include <qgraphicsview.h>

class ifdealer_QT : public QMainWindow
{
	Q_OBJECT

public:
	ifdealer_QT(QWidget* parent = Q_NULLPTR);

private:
	Ui::ifdealer_QTClass ui;
	QString filepath; //图片路径
	Image *image;  //图像对象
	QImage img;
	QPixmap tempPixmap;

	ImageWidget* m_Image;
	

private slots:
	//选择文件槽函数
	void SelectFile(); 
	//显示图片
	void ShowWindow();
};
