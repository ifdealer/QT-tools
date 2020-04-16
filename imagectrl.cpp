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
	setAcceptDrops(true);//true������ͣ�¼�
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
		m_startPos = event->pos();//����л�ʱ����ȡ��ǰ�����ͼƬ�е�����

		m_isMove = true;//�������м�������
	}
	else if (event->button() == Qt::RightButton)
	{
		ResetItemPos();//�һ�������ô�С
		//cout << "*************" << endl;
	}
	else if (event->button() == Qt::LeftButton) {   //������»�ȡ���겢�ڴ����·���ʾ
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
	m_isMove = false;//�������м��Ѿ�̧��


}


void ImageWidget::wheelEvent(QGraphicsSceneWheelEvent* event)//�������¼�
{
	//ѡ������=����+�ƶ�
	if ((event->delta() > 0) && (m_scaleValue >= 50))//���Ŵ�ԭʼͼ���50��
	{
		return;
	}
	else if ((event->delta() < 0) && (m_scaleValue <= m_scaleDafault*0.1))//ͼ����С������Ӧ��С֮��Ͳ�������С
	{
		//ResetItemPos();//����ͼƬ��С��λ�ã�ʹ֮����Ӧ�ؼ����ڴ�С
		return;
	}
	else
	{
		//������
		qreal qrealOriginScale = m_scaleValue;
		if (event->delta() > 0)//��������ǰ����
		{
			m_scaleValue *= 1.1;//ÿ�ηŴ�10%
		}
		else
		{
			m_scaleValue *= 0.9;//ÿ����С10%
		}
		setScale(m_scaleValue);
		//���ƶ�
		if (event->delta() > 0)
		{
			moveBy(-event->pos().x() * qrealOriginScale * 0.1, -event->pos().y() * qrealOriginScale * 0.1);//ʹͼƬ���ŵ�Ч��������������������ڵ�Ϊ���Ľ������ŵ�
		}
		else
		{
			moveBy(event->pos().x() * qrealOriginScale * 0.1, event->pos().y() * qrealOriginScale * 0.1);//ʹͼƬ���ŵ�Ч��������������������ڵ�Ϊ���Ľ������ŵ�
		}
	}


}

void ImageWidget::setQGraphicsViewWH(int nwidth, int nheight)//��������Ŀؼ�QGraphicsView��width��height���������У�������ͼ��ĳ���Ϳؼ��ĳ���ı�����ʹͼƬ���ŵ��ʺϿؼ��Ĵ�С
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

void ImageWidget::ResetItemPos()//����ͼƬλ��
{
	m_scaleValue = m_scaleDafault;//���ű����ص�һ��ʼ������Ӧ����
	setScale(m_scaleDafault);//���ŵ�һ��ʼ������Ӧ��С
	setPos(0, 0);
}

qreal ImageWidget::getScaleValue() const
{
	return m_scaleValue;
}