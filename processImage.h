#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

class Image {
private:
	
	string filepath;
public:
	//��ȡͼƬ
	Mat SourceImage;
	bool readimage(string filepath, int readflag = 1);
	
	
};