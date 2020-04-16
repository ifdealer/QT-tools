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
	if (width > 1300) {
		ui.ShowImage->setGeometry(0, 0, 1280 + 2, 720 + 2);  //����ͼƬ������С
		this->resize(QSize(1280 + 2, 720 + 20));  //���ô��ڴ�С
		ui.poslabel->setGeometry(0, 720 + 5, 100, 10);   //����������ʾlabelλ��
		ui.picvalue->setGeometry(1280 - 110, 720 + 5, 100, 10);
		ui.ShowImage->setSceneRect(QRectF(-(1280 / 2), -(720 / 2), 1280, 720));  //����scenRect��С
	}
	else {
		ui.ShowImage->setGeometry(0, 0, width + 2, height + 2);  //����ͼƬ������С
		this->resize(QSize(width + 2, height + 20));  //���ô��ڴ�С
		ui.poslabel->setGeometry(0, height + 5, 100, 10);   //����������ʾlabelλ��
		ui.picvalue->setGeometry(width - 110, height + 5, 100, 10);
		ui.ShowImage->setSceneRect(QRectF(-(width / 2), -(height / 2), width, height));  //����scenRect��С
	}
	
	
	
	
	ui.ShowImage->setScene(originalScene);    //Ϊgraphyview���� Scene
	
}

//��ͼƬ�·���ʾ�����
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

void ImageWindow::setCorValue(int B, int G, int R)
{
	stringstream strd;
	strd << R;
	string sstr = strd.str();
	QString qstr = QString::fromStdString(sstr) + ",";
	strd.clear();
	strd.str("");
	strd << G;
	sstr = strd.str();
	qstr += QString::fromStdString(sstr) + ",";
	strd.clear();
	strd.str("");
	strd << B;
	sstr = strd.str();
	qstr += QString::fromStdString(sstr);
	ui.picvalue->setText(qstr);
}






//void ImageWindow::setQimage(QImage qimage, ImageWidget* m_Image,QGraphicsScene* originalScene)
//{
//	int width = qimage.width();
//	int height = qimage.height();
//	this->img = qimage;
//	tempPixmap = QPixmap::fromImage(img);  //ת��Ϊpixmap
//	originalScene = new QGraphicsScene(this);   //newһ��scene
//	this->resize(QSize(qimage.width()+2, qimage.height()+20));  //���ô��ڴ�С �ײ�Ԥ��λ����ʾ����
//	m_Image = new ImageWidget(&tempPixmap);  //�Զ���ͼƬ������
//	m_Image->setQGraphicsViewWH(qimage.width() + 2, qimage.height() + 2);
//	ui.ShowImage->setGeometry(0, 0, qimage.width()+2, qimage.height()+2);  //����ͼƬ������С
//	ui.ShowImage->setSceneRect(QRectF(-(width / 2), -(height / 2), width, height));
//	//ui.ShowImage->setAttribute(Qt::WA_TransparentForMouseEvents);   //��������¼���͸�����ڴ����ϵ�����Դ��������ڵ�����¼�
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

