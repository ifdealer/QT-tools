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
	ImageWidget(QPixmap* pixmap);
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
	QPointF getRecordPoint();
	bool getRecord();

	void buildWin(int width, int height);
	ImageWindow* getImageWindow();
private:
	qreal       m_scaleValue;
	qreal       m_scaleDafault;
	QPixmap     m_pix;
	int         m_zoomState;
	bool        m_isMove;
	QPointF     m_startPos;
	QPointF     recordPoint;
	ImageWindow* imgWindow;
	QGraphicsScene* originalScene;
};