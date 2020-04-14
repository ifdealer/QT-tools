#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

class Image {
private:
	Mat SourceImage;
	string filepath;
	int width;
	int hight;
public:
	//∂¡»°Õº∆¨
	bool readimage(string filepath, int readflag = 1);
	Mat getImage();
	
};