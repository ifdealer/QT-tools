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
	QString filepath; //ͼƬ·��
	Image *image;  //ͼ�����
	QImage img;
	QPixmap tempPixmap;

	ImageWidget* m_Image;
	

private slots:
	//ѡ���ļ��ۺ���
	void SelectFile(); 
	//��ʾͼƬ
	void ShowWindow();
};
