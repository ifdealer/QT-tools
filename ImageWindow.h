#pragma once

#include <QWidget>
#include "ui_ImageWindow.h"

#include <qgraphicsview.h>
#include <sstream>
#include <QMouseEvent>
using namespace std;
class ImageWindow : public QWidget
{
	Q_OBJECT

public:

	ImageWindow(QWidget* parent = Q_NULLPTR);
	~ImageWindow();
	//���������ú���
	//void setQimage(QImage qimage, ImageWidget* m_Image, QGraphicsScene* originalScene);
	void setSize(int width ,int height, QGraphicsScene* originalScene);
	void setCor(QPointF ptsf);
private:
	
	Ui::ImageWindow ui;
	
private slots:




};
