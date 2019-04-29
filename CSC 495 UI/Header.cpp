#include <iostream>
#include <opencv2\opencv.hpp>
#include "Header.h"

using namespace cv;
using namespace std;
using namespace cams;

Camera::Camera()
{
}
System::Drawing::Bitmap^ Camera::Show(cv::Mat & colorImage) {
	System::IntPtr ptr(colorImage.ptr());
	System::Drawing::Bitmap^ b;
	switch (colorImage.type())
	{
	case CV_8UC3:
		b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
		break;
	case CV_8UC1:
		b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
			System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr);
		break;
	default:
		break;
	}
	return b;
}
