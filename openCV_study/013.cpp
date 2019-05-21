#include "study_content.h"

//图像翻转(Image Flip)
//图像翻转的本质像素映射，OpenCV支持三种图像翻转方式
//- X轴翻转，flipcode = 0
//- Y轴翻转, flipcode = 1
//- XY轴翻转, flipcode = -1
//
//相关的API
//flip
//- src输入参数
//- dst 翻转后图像
//- flipcode

void image_flip()
{
	Mat dst;
	Mat	 src = imread("home.jpg");
	if (src.empty())
	{
		cout << "image empty" << endl;
		return;
	}

	//x 翻转
	flip(src, dst, 0);
	imshow("X", dst);

	//y 翻转
	flip(src, dst, 1);
	imshow("Y", dst);

	//xy 翻转
	flip(src, dst,-1);
	imshow("XY", dst);
}