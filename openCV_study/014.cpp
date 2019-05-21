#include "study_content.h"

//图像插值(Image Interpolation)
//最常见四种插值算法
//INTER_NEAREST = 0  最近邻 速度快
//INTER_LINEAR = 1
//INTER_CUBIC = 2 三次样条插值
//INTER_LANCZOS4 = 4 Lanczos插值
//相关的应用场景
//几何变换、透视变换、插值计算新像素
//resize,
//如果size有值，使用size做放缩插值，否则根据fx与fy
//卷积、


void ImageInterpolation()
{
	Mat src = imread("home.jpg");

	Mat dst;
	resize(src, dst, Size(src.size().width * 2, src.size().height * 2), 0, 0, INTER_NEAREST);
	imshow("INTER_NEAREST",dst);

	resize(src, dst, Size(src.size().width * 2, src.size().height * 2), 0, 0, INTER_LINEAR);
	imshow("INTER_LINEAR", dst);

	resize(src, dst, Size(src.size().width * 2, src.size().height * 2), 0, 0, INTER_CUBIC);
	imshow("INTER_CUBIC", dst);

	resize(src, dst, Size(src.size().width * 2, src.size().height * 2), 0, 0, INTER_CUBIC);
	imshow("INTER_LANCZOS4", dst);
}