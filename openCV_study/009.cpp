#include "study_content.h"

//知识点： 色彩空间与色彩空间转换
//- RGB色彩空间 通用
//- HSV色彩空间 直方图相关的图像处理算法 常用
//- YUV色彩空间 欧洲早起的标准 Android linux 最原始的数据
//- YCrCb色彩空间 皮肤检测
//
//API知识点
//- 色彩空间转换cvtColor
//- 提取指定色彩范围区域inRange


void convert_color()
{
	Mat src = imread("home.jpg");
	Mat src_resize;
	resize(src, src_resize, Size(700, 466));
	//imshow("src resize", src_resize);
	Mat dst;

	cvtColor(src, dst, COLOR_BGR2HSV);
	imshow("COLOR_BGR2HSV", dst);

	cvtColor(src, dst, COLOR_BGR2YUV);
	imshow("COLOR_BGR2YUV", dst);

	cvtColor(src, dst, COLOR_BGR2YCrCb);
	imshow("COLOR_BGR2YCrCb", dst);


	Mat src2 = imread("timg.jpeg");

	cvtColor(src2, dst, COLOR_BGR2HSV);
	Mat mask,mask_not;
	cv::inRange(dst, Scalar(35, 43, 46), Scalar(78, 255, 255), mask); 
	bitwise_not(mask, mask_not);

	imshow("mask_not", mask_not);
	Mat mask_ret;
	bitwise_and(src2, src2, mask_ret, mask_not);
	imshow("mask_ret", mask_ret);
	Mat ret;

	//bitwise_and(src_resize, src_resize, src_resize,mask_not);
	imshow("src resize", src_resize);
	bitwise_xor(src_resize, mask_ret, ret);

	imshow("ret", ret);

	
	
}