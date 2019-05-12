#include "study_content.h"

/*
* 色彩空间转换
* 图像保存
*/
void convert_write()
{
	Mat image = imread("test.jpg");
	namedWindow("test show", WINDOW_AUTOSIZE);
	Mat image_gray;
	cvtColor(image, image_gray, COLOR_BGR2GRAY);

	imwrite("gray.png", image_gray);

	imshow("test show", image_gray);

}