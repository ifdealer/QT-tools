#include "processImage.h"

//¶ÁÈ¡Í¼Æ¬
bool Image::readimage(string filepath, int readflag)
{
	if (filepath.empty()) {
		return false;
	}
	SourceImage = imread(filepath, readflag);
	this->filepath = filepath;
	this->hight = SourceImage.rows;
	this->width = SourceImage.cols;
	/*imshow("image", SourceImage);
	waitKey(0);*/
	return true;

}

Mat Image::getImage()
{
	return SourceImage.clone();
}

