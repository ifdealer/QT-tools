#include "processImage.h"

//¶ÁÈ¡Í¼Æ¬
bool Image::readimage(string filepath, int readflag)
{
	if (filepath.empty()) {
		return false;
	}
	Mat tmpimage = imread(filepath, readflag);
	tmpimage.copyTo(this->SourceImage);
	this->filepath = (filepath);
	/*imshow("image", SourceImage);
	waitKey(0);*/
	return true;

}

bool Image::blur(int achor)
{
	
	achor *= 2;
	achor += 1;
	medianBlur(SourceImage, this->processImage, achor);
	return true;
}



