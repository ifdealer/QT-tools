#include "processImage.h"

//��ȡͼƬ
bool Image::readimage(string filepath, int readflag)
{
	if (filepath.empty()) {
		return false;
	}
	SourceImage = imread(filepath, readflag);
	this->filepath = filepath;
	/*imshow("image", SourceImage);
	waitKey(0);*/
	return true;

}



