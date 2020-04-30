
#include "ifdealer_QT.h"


ifdealer_QT::ifdealer_QT(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//��ʼ��ͼ�����
	//���Ӱ�ť��ѡ���ļ���
	connect(ui.SelectFile, &QPushButton::clicked, this, &ifdealer_QT::SelectFile);
	//connect(ui.Showimage, &QPushButton::clicked, this, &ifdealer_QT::Showimage);





	//----------------------��ӳ���ź�
	signalMapper = new QSignalMapper(this);
	connect(ui.Showimage, SIGNAL(clicked()), signalMapper, SLOT(map()));

	//ͨ��mapӳ���ﵽ����ÿ�ε����ʾ��ͬ��ͼƬ����ͼƬ����vector�У�ÿ�ε����ʾ��β��ͼƬ������Ҫ��ͼƬ����봰�����
	signalMapper->setMapping(ui.Showimage, -1);   //Ĭ�ϴ�-1 ��ʾ���������һ��ͼƬ  �����������ط������޸�

	connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(ShowWindow(int)));


	//-------------------ģ���������ź�
	connect(ui.blurSlider, SIGNAL(valueChanged(int)), this, SLOT(blurImage(int)));

	
}	

//ѡ���ļ�����ʼ��ͼ��
void ifdealer_QT::SelectFile() {
	filepath = QFileDialog::getOpenFileName(this, "ѡ��ͼƬ", "/", "Image Files(*.jpg *.png *.bmp)");	
	//���������������
	//string cdata = filepath.toLocal8Bit().toStdString();
	Image *img = new Image;
	image.push_back(img);
	//��ȡͼƬ

	img->readimage(filepath.toLocal8Bit().toStdString());
	cvtColor(img->SourceImage, img->SourceImage, CV_BGR2RGB);
	
}


void ifdealer_QT::ShowWindow(int i)
{
	if (i == -1) {  //�����-1 ��ȡ���һ��ͼƬ�� ����ȡ����i�е�ͼƬ
		i = image.size() - 1;
	}

	Mat pic = image[i]->SourceImage;
	
	img = QImage((const unsigned char*)(pic.data), pic.cols, pic.rows, QImage::Format_RGB888);
	int width = img.width();
	int height = img.height();
	ImageWidget* tmp_Image = new ImageWidget(image[i]);
	m_Image.push_back(tmp_Image);
	tmp_Image->setQGraphicsViewWH(width + 2, height + 2);
	tmp_Image->buildWin(width, height);
	

}

void ifdealer_QT::blurImage(int i)
{
	int index = image.size() - 1;
	image[index]->blur(i);
	m_Image[index]->setPix(image[index]);
	
}
