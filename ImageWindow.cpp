#include "ImageWindow.h"

ImageWindow::ImageWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	
}

ImageWindow::~ImageWindow()
{
	
}

void ImageWindow::setSize(int width, int height, QGraphicsScene* originalScene)
{
	ui.ShowImage->setGeometry(0, 0, width + 2, height + 2);  //重置图片容器大小
	this->resize(QSize(width + 2, height + 20));  //重置窗口大小
	ui.ShowImage->setSceneRect(QRectF(-(width / 2), -(height / 2), width, height));  //设置scenRect大小
	
	ui.ShowImage->setScene(originalScene);
	ui.poslabel->setGeometry(0, height + 5, 100, 10);
}

void ImageWindow::setCor(QPointF ptsf)
{
	QPointF pts = ptsf;
	float x = pts.x();
	float y = pts.y();
	stringstream strd;
	strd << (int)x;
	string sstr = strd.str();
	QString qstr = QString::fromStdString(sstr) + ",";
	strd.clear();
	strd.str("");
	strd << (int)y;
	sstr = strd.str();
	qstr += QString::fromStdString(sstr);
	ui.poslabel->setText(qstr);
}





//void ImageWindow::setQimage(QImage qimage, ImageWidget* m_Image,QGraphicsScene* originalScene)
//{
//	int width = qimage.width();
//	int height = qimage.height();
//	this->img = qimage;
//	tempPixmap = QPixmap::fromImage(img);  //转换为pixmap
//	originalScene = new QGraphicsScene(this);   //new一个scene
//	this->resize(QSize(qimage.width()+2, qimage.height()+20));  //重置窗口大小 底部预留位置显示坐标
//	m_Image = new ImageWidget(&tempPixmap);  //自定义图片控制类
//	m_Image->setQGraphicsViewWH(qimage.width() + 2, qimage.height() + 2);
//	ui.ShowImage->setGeometry(0, 0, qimage.width()+2, qimage.height()+2);  //重置图片容器大小
//	ui.ShowImage->setSceneRect(QRectF(-(width / 2), -(height / 2), width, height));
//	//ui.ShowImage->setAttribute(Qt::WA_TransparentForMouseEvents);   //设置鼠标事件穿透，即在窗口上点击可以触发父窗口的鼠标事件
//	ui.poslabel->setGeometry(0, height + 5, 20, 10);
//	originalScene->addItem(m_Image);
//	ui.ShowImage->setScene(originalScene);
//	
//	/*QPointF pts = m_Image->getRecordPoint();
//	float x = pts.x();
//	float y = pts.y();
//	stringstream strd;
//	strd << (int)x;
//	string sstr = strd.str();
//	QString qstr = QString::fromStdString(sstr);;
//	ui.poslabel->setText(qstr);*/
//	
//	
//	
//	
//}

