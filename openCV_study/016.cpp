#include "study_content.h"

// 图像ROI与ROI操作
// 图像ROI解释 :
// 图像的ROI(region of interest)是指图像中感兴趣区域、在OpenCV中图像设置图像ROI区域，实现只对ROI区域操作。
//
// 1. 矩形ROI区域提取
// 2. 矩形ROI区域copy
//
// 3. 不规则ROI区域
// - ROI区域mask生成
// - 像素位 and操作
// - 提取到ROI区域
// - 加背景or操作
// - add 背景与ROI区域

void image_roi()
{
	//=================规则ROI=================
	Mat src = imread("test2.jpg");
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	// 获取ROI
	Rect rect(606, 0, 1099-606, 1080);
	Mat roi = src(rect);
	imshow("roi", roi);
	
	Mat image = roi.clone();
	// modify ROI
	roi.setTo(Scalar(255, 0, 0));
	imshow("result", src);

	// modify copy roi
	image.setTo(Scalar(0, 0, 255));
	imshow("copy roi", image);

	//=================不规则ROI=================
	// example with ROI - generate mask
	Mat src2 = imread("timg.jpeg");
	imshow("src2", src2);
	Mat hsv, mask;
	cvtColor(src2, hsv, COLOR_BGR2HSV);
	inRange(hsv, Scalar(35, 43, 46), Scalar(99, 255, 255), mask);
	imshow("mask", mask);

	// extract person ROI
	Mat person;
	bitwise_not(mask, mask);
	//白色是当前ROI区域的内容 也就是人
	imshow("mask", mask);
	//提取白色区域的人
	bitwise_and(src2, src2, person,mask);
	imshow("person", person);

	// generate background
	Mat result = Mat::zeros(src2.size(), src2.type());
	result.setTo(Scalar(255, 0, 0));

	// combine background + person
	Mat dst;
	//取背景ROI
	bitwise_not(mask, mask);
	//背景ROI融合
	bitwise_or(person, result, dst, mask);
	//背景 和 人 组合
	// bitwise_or(person, dst, dst); 这个和下面的效果一样
	add(dst, person, dst);

	imshow("dst", dst);
	waitKey(0);
}