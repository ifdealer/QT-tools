#include "imagectrl.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QGraphicsSceneDragDropEvent>
#include <QDrag>
#include <math.h>
#include <iostream>
using namespace std;
ImageWidget::ImageWidget(Image* image)
{
	m_image = image;
	m_pix = QPixmap::fromImage(QImage((const unsigned char*)(image->SourceImage.data), image->SourceImage.cols, image->SourceImage.rows, QImage::Format_RGB888));

	//If enabled is true, this item will accept hover events; otherwise, it will ignore them. By default, items do not accept hover events.
	setAcceptDrops(true);//true接收悬停事件
	m_scaleValue = 0;
	m_scaleDafault = 0;
	m_isMove = false;
	imgWindow = new ImageWindow;
	originalScene = new QGraphicsScene(imgWindow);
}

QRectF ImageWidget::boundingRect() const
{
	return QRectF(-m_pix.width() / 2, -m_pix.height() / 2,
		m_pix.width(), m_pix.height());

}

void ImageWidget::paint(QPainter* painter, const QStyleOptionGraphicsItem*,
	QWidget*)
{
	painter->drawPixmap(-m_pix.width() / 2, -m_pix.height() / 2, m_pix);
}

void ImageWidget::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	if (event->buttons() == Qt::MidButton)
	{
		m_startPos = event->pos();//鼠标中击时，获取当前鼠标在图片中的坐标

		m_isMove = true;//标记鼠标中键被按下
	}
	else if (event->button() == Qt::RightButton)
	{
		ResetItemPos();//右击鼠标重置大小
		//cout << "*************" << endl;
	}
	else if (event->button() == Qt::LeftButton) {   //左键按下获取坐标并在窗口下方显示
		recordPoint = event->pos();
		recordPoint.setX(recordPoint.x() + m_pix.width() / 2);
		recordPoint.setY(recordPoint.y() + m_pix.height() / 2);
		imgWindow->setCor(recordPoint);
		int x = recordPoint.x();
		int y = recordPoint.y();
		//cout << (int)m_image->SourceImage.at<uchar>(y, x) << endl;
		imgWindow->setCorValue(
			m_image->SourceImage.at<Vec3b>(y, x)[0],
			m_image->SourceImage.at<Vec3b>(y, x)[1],
			m_image->SourceImage.at<Vec3b>(y, x)[2]);

		//int r = qRed(m_image.pixel(10,10));
		//int g = qGreen(m_image.pixel(recordPoint.toPoint()));
		//int b = qBlue(m_image.pixel(recordPoint.toPoint()));
		//imgWindow->setCorValue(r, g, b);
	}


}

void ImageWidget::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{


	qreal x = m_pix.width() * 5;
	qreal y = m_pix.height() * 5;

	if (pos().x() <= (-x))
	{
		setPos(qreal(-x + 1), pos().y());
		m_isMove = false;
	}
	if (pos().x() >= x)
	{
		setPos(QPointF(x - 1, pos().y()));
		m_isMove = false;
	}
	if (pos().y() <= (-y))
	{
		setPos(pos().x(), qreal(-y + 1));
		m_isMove = false;
	}
	if (pos().y() >= y)
	{
		setPos(pos().x(), qreal(y - 1));
		m_isMove = false;
	}
	if (m_isMove)
	{
		QPointF point = (event->pos() - m_startPos) * m_scaleValue;
		moveBy(point.x(), point.y());
	}
	//qDebug() << "event->xpos=" << event->pos().x()+ m_pix.width()/2;
	// qDebug() << "event->ypos=" << event->pos().y()+ m_pix.height()/2;
	// qDebug() << "event->ypos=" << event->scenePos();
	//qDebug() << "pos=" << pos();
}

void ImageWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	m_isMove = false;//标记鼠标中键已经抬起


}


void ImageWidget::wheelEvent(QGraphicsSceneWheelEvent* event)//鼠标滚轮事件
{
	//选点缩放=缩放+移动
	if ((event->delta() > 0) && (m_scaleValue >= 50))//最大放大到原始图像的50倍
	{
		return;
	}
	else if ((event->delta() < 0) && (m_scaleValue <= m_scaleDafault*0.1))//图像缩小到自适应大小之后就不继续缩小
	{
		//ResetItemPos();//重置图片大小和位置，使之自适应控件窗口大小
		return;
	}
	else
	{
		//①缩放
		qreal qrealOriginScale = m_scaleValue;
		if (event->delta() > 0)//鼠标滚轮向前滚动
		{
			m_scaleValue *= 1.1;//每次放大10%
		}
		else
		{
			m_scaleValue *= 0.9;//每次缩小10%
		}
		setScale(m_scaleValue);
		//②移动
		if (event->delta() > 0)
		{
			moveBy(-event->pos().x() * qrealOriginScale * 0.1, -event->pos().y() * qrealOriginScale * 0.1);//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
		}
		else
		{
			moveBy(event->pos().x() * qrealOriginScale * 0.1, event->pos().y() * qrealOriginScale * 0.1);//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
		}
	}


}

void ImageWidget::setQGraphicsViewWH(int nwidth, int nheight)//将主界面的控件QGraphicsView的width和height传进本类中，并根据图像的长宽和控件的长宽的比例来使图片缩放到适合控件的大小
{
	int nImgWidth = m_pix.width();
	int nImgHeight = m_pix.height();
	qreal temp1 = nwidth * 1.0 / nImgWidth;
	qreal temp2 = nheight * 1.0 / nImgHeight;
	if (temp1 > temp2)
	{
		m_scaleDafault = temp2;
	}
	else
	{
		m_scaleDafault = temp1;
	}
	setScale(m_scaleDafault);
	m_scaleValue = m_scaleDafault;
}

QPointF ImageWidget::getRecordPoint()
{
	return this->recordPoint;
}



void ImageWidget::buildWin(int width, int height)
{
	originalScene->addItem(this);
	imgWindow->setSize(width, height, originalScene);

	imgWindow->show();
}

ImageWindow* ImageWidget::getImageWindow()
{
	return imgWindow;
}

void ImageWidget::ResetItemPos()//重置图片位置
{
	m_scaleValue = m_scaleDafault;//缩放比例回到一开始的自适应比例
	setScale(m_scaleDafault);//缩放到一开始的自适应大小
	setPos(0, 0);
}

qreal ImageWidget::getScaleValue() const
{
	return m_scaleValue;
}