#include "study_content.h"

// 图像直方图均衡化
//
// 图像直方图均衡化可以用于图像增强、
// 对输入图像进行直方图均衡化处理，
// 提升后续对象检测的准确率在OpenCV人脸检测的代码演示中已经很常见。
// 此外对医学影像图像与卫星遥感图像也经常通过直方图均衡化来提升图像质量。
//
// OpenCV中直方图均衡化的API很简单
// - equalizeHist(src, dst)


void  histogram_equalization()
{
	Mat src = imread("home.jpg");

	if (src.empty()) {
		printf("could not load image...\n");
		return ;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	Mat gray, dst;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	imshow("input", gray);
	equalizeHist(gray, dst);
	imshow("eq", dst);

}
