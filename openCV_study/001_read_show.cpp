#include "study_content.h"

/*
 *
 */
void read_show()
{
	// int flags = IMREAD_COLOR
	//第二个读取参数 很重要  一定要按照实际图片的样式填写  否则会默认彩色图像。
	//哪怕你读取的是一个gray，也是发现 channel是3
	Mat image = imread("test.jpg", IMREAD_COLOR);
	namedWindow("test show", WINDOW_AUTOSIZE);
	imshow("test show", image);

}