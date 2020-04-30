#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_ifdealer_QT.h"

#include "imagectrl.h"
#include "processImage.h"
#include <qdialog.h>
#include <qstring.h>
#include <qfiledialog.h>
#include <qgraphicsview.h>
#include <QSignalMapper>

class ifdealer_QT : public QMainWindow
{
	Q_OBJECT

public:
	ifdealer_QT(QWidget* parent = Q_NULLPTR);

private:
	Ui::ifdealer_QTClass ui;
	QString filepath; //图片路径
	vector<Image*> image;  //图像对象
	QImage img;
	QPixmap tempPixmap;

	vector<ImageWidget*> m_Image;


	//转发器
	QSignalMapper* signalMapper;
	

private slots:
	//选择文件槽函数
	void SelectFile(); 
	//显示图片
	void ShowWindow(int i);
	void blurImage(int i);
};
