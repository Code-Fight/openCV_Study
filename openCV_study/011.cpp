#include "study_content.h"


// 知识点： 像素归一化
//
// OpenCV中提供了四种归一化的方法
// - NORM_MINMAX
// - NORM_INF
// - NORM_L1 总和为1
// - NORM_L2 单位向量为1
// 最常用的就是NORM_MINMAX归一化方法。
//
// 相关API函数：
// normalize(
// 	InputArray 	src, // 输入图像
// 	InputOutputArray 	dst, // 输出图像
// 	double 	alpha = 1, // NORM_MINMAX时候低值
// 	double 	beta = 0, // NORM_MINMAX时候高值
// 	int 	norm_type = NORM_L2, // 只有alpha
// 	int 	dtype = -1, // 默认类型与src一致
// 	InputArray 	mask = noArray() // mask默认值为空
// )


void normalize_test()
{
	Mat src = imread("home.jpg");
	Mat gray =src;
	cvtColor(src, gray, COLOR_BGR2GRAY);

	//转换为浮点型
	gray.convertTo(gray, CV_32F);

	//NORM_MINMAX 其他的只需要替换最后一个参数即可
	Mat dst = Mat::zeros(gray.size(), CV_32FC1);
	normalize(gray, dst, 1.0, 0, NORM_MINMAX);
	Mat result = dst * 255;
	result.convertTo(dst, CV_8UC1);
	imshow("NORM_MINMAX", dst);

}