
#include "ifdealer_QT.h"


ifdealer_QT::ifdealer_QT(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//初始化图像对象
	//连接按钮和选择文件槽
	connect(ui.SelectFile, &QPushButton::clicked, this, &ifdealer_QT::SelectFile);
	//connect(ui.Showimage, &QPushButton::clicked, this, &ifdealer_QT::Showimage);





	//----------------------重映射信号
	signalMapper = new QSignalMapper(this);
	connect(ui.Showimage, SIGNAL(clicked()), signalMapper, SLOT(map()));

	//通过map映射表达到可以每次点击显示不同的图片，将图片存在vector中，每次点击显示最尾部图片，还需要绑定图片序号与窗口序号
	signalMapper->setMapping(ui.Showimage, -1);   //默认传-1 表示向量中最后一张图片  可以在其他地方进行修改

	connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(ShowWindow(int)));


	//-------------------模糊滑动条信号
	connect(ui.blurSlider, SIGNAL(valueChanged(int)), this, SLOT(blurImage(int)));

	
}	

//选择文件并初始化图像
void ifdealer_QT::SelectFile() {
	filepath = QFileDialog::getOpenFileName(this, "选择图片", "/", "Image Files(*.jpg *.png *.bmp)");	
	//解决中文乱码问题
	//string cdata = filepath.toLocal8Bit().toStdString();
	Image *img = new Image;
	image.push_back(img);
	//读取图片

	img->readimage(filepath.toLocal8Bit().toStdString());
	cvtColor(img->SourceImage, img->SourceImage, CV_BGR2RGB);
	
}


void ifdealer_QT::ShowWindow(int i)
{
	if (i == -1) {  //如果是-1 则取最后一张图片， 否则取向量i中的图片
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
