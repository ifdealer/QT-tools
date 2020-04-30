#pragma once
#include <QWidget>
#include <QtGui>
#include <QPixmap>
#include <QPainter>
#include <QRectF>
#include <QMouseEvent>
#include <QPointF>
#include <QDragEnterEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsItem>
#include "ImageWindow.h"
#include <qgraphicsview.h>
#include "processImage.h"


/*
	图片操作控制类
	继承QGraphicsItems类
	然后重载其鼠标事件等
	完成缩放和平移功能
	
*/

enum Enum_ZoomState {
	NO_STATE,
	RESET,
	ZOOM_IN,
	ZOOM_OUT

};
// class ImageWidget :public QObject, QGraphicsItem
class ImageWidget :public QGraphicsItem
{
	//Q_OBJECT
public:
	ImageWidget(Image* image);
	QRectF  boundingRect() const;
	void    paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	void    wheelEvent(QGraphicsSceneWheelEvent* event);
	void    ResetItemPos();
	//QVariant itemChange(GraphicsItemChange change, const QVariant &value);
	void    mousePressEvent(QGraphicsSceneMouseEvent* event);
	void    mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	void    mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	qreal   getScaleValue() const;
	void    setQGraphicsViewWH(int nwidth, int nheight);
	QPointF getRecordPoint();   //获取鼠标记录点

	void buildWin(int width, int height);  //创建图片窗口
	ImageWindow* getImageWindow();
	void setPix(Image* image);
private:
	qreal       m_scaleValue;
	qreal       m_scaleDafault;
	QPixmap     m_pix;
	
	int         m_zoomState;
	bool        m_isMove;
	QPointF     m_startPos;
	QPointF     recordPoint;
	
	QGraphicsScene* originalScene;

	ImageWindow* imgWindow;
	Image*       m_image;   //自定义图像操作类
	int index; //图像索引
};