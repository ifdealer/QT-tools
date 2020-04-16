
#include "ifdealer_QT.h"


ifdealer_QT::ifdealer_QT(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//��ʼ��ͼ�����
	//���Ӱ�ť��ѡ���ļ���
	connect(ui.SelectFile, &QPushButton::clicked, this, &ifdealer_QT::SelectFile);
	//connect(ui.Showimage, &QPushButton::clicked, this, &ifdealer_QT::Showimage);
	connect(ui.Showimage, &QPushButton::clicked, this, &ifdealer_QT::ShowWindow);
	
	image = new Image;
	
}	

//ѡ���ļ�����ʼ��ͼ��
void ifdealer_QT::SelectFile() {
	filepath = QFileDialog::getOpenFileName(this, "ѡ��ͼƬ", "/", "Image Files(*.jpg *.png)");	
	//���������������
	//string cdata = filepath.toLocal8Bit().toStdString();
	//��ȡͼƬ
	image->readimage(filepath.toLocal8Bit().toStdString());
}


void ifdealer_QT::ShowWindow()
{

	Mat pic = image->SourceImage;
	cvtColor(image->SourceImage, image->SourceImage, CV_BGR2RGB);
	img = QImage((const unsigned char*)(pic.data), pic.cols, pic.rows, QImage::Format_RGB888);
	int width = img.width();
	int height = img.height();
	tempPixmap = QPixmap::fromImage(img);
	m_Image = new ImageWidget(image);
	m_Image->setQGraphicsViewWH(width + 2, height + 2);
	m_Image->buildWin(width, height);
	
	
}
