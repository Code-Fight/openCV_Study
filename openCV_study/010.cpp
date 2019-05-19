#include "study_content.h"


// ֪ʶ�㣺 ����ֵͳ��
// - ��С(min)
// - ���(max)
// - ��ֵ(mean)
// - ��׼����(standard deviation)
//
// API֪ʶ��
// - �����СֵminMaxLoc
// - �����ֵ���׼����meanStdDev


void means_stddev()
{
	//minmaxloc
	Mat src = imread("home.jpg", IMREAD_GRAYSCALE);
	Mat dst;
	double minVal, maxVal;
	Point minLoc, maxLoc;

	minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc);

	printf("minVal:%.2f,maxVal:%.2f\n", minVal, maxVal);
	printf("minLoc:%.2d,%.2d,maxLoc:%.2d,%.2d\n", minLoc.x, minLoc.y, maxLoc.x, maxLoc.y);


	//means,stddev

	src = imread("home.jpg");
	Mat means, stddev;
	meanStdDev(src, means, stddev);


	printf("blue channel->> mean: %.2f, stddev: %.2f\n", means.at<double>(0, 0), stddev.at<double>(0, 0));
	printf("green channel->> mean: %.2f, stddev: %.2f\n", means.at<double>(1, 0), stddev.at<double>(1, 0));
	printf("red channel->> mean: %.2f, stddev: %.2f\n", means.at<double>(2, 0), stddev.at<double>(2, 0));

}