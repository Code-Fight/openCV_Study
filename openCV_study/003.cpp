#include "study_content.h"


void image_object()
{
	Mat src = imread("test.jpg");

	//clone & copy
	//如果接触过别的oop语言，这里有点不太一样
	//一般copy会有深拷贝和浅拷贝 但是这里 的copy和clone效果一样
	//都是完成了整个内存的复制
	Mat img_clone,img_copy;
	img_clone = src.clone();
	src.copyTo(img_copy);

	
	imshow("img_clone", img_clone);
	imshow("img_copy", img_copy);

	//赋值
	Mat img_e = src;
	imshow("img_e", img_copy);

	//创建空白图像
	Mat img_blank_1 = Mat::zeros(src.size(), src.type());

	imshow("img_blank_1", img_blank_1);

	Mat img_blank_2 = Mat::zeros(Size(512,512),CV_8UC3);
	imshow("img_blank_2", img_blank_2);

	Mat img_blank_3 = Mat::ones(Size(512, 512), CV_8UC3);
	imshow("img_blank_3", img_blank_3);


	//Mat_类一般应用于矩阵(matrix)的运算。
	//Mat_类继承自Mat类,对数据类型更加灵活，可定义为Mat_<_Tp>的矩阵形式
	// 0, -1, 0
	// -1, 5, -1
	// 0, -1, 0
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);










}