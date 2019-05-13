#include "study_content.h"

/*
 * 图像像素的 加减乘除 内部函数
 */
void oprational_pixel_jjcx()
{


	char current_path[MAX_PATH];
	_getcwd(current_path, MAX_PATH);
	string path = current_path;
	

	Mat	img_1 = imread(path + string("/image/aero1.jpg"));
	Mat	img_2 = imread(path + string("/image/aero3.jpg"));

	Mat add_ret = Mat::zeros(img_1.size(), img_1.type());
	add(img_1, img_2, add_ret);
	imshow("add", add_ret);


	Mat sub_ret = Mat::zeros(img_1.size(), img_1.type());
	subtract(img_1, img_2, sub_ret);
	imshow("sub_ret", sub_ret);

	Mat mul_ret = Mat::zeros(img_1.size(), img_1.type());
	multiply(img_1, img_2, mul_ret);
	imshow("mul_ret", mul_ret);

	Mat div_ret = Mat::zeros(img_1.size(), img_1.type());
	divide(img_1, img_2, div_ret);
	imshow("div_ret", div_ret);


	
}


/*
* 图像像素的 加法 自己实现
*/
void oprational_pixel_add_by_custom()
{

	char current_path[MAX_PATH];
	_getcwd(current_path, MAX_PATH);
	string path = current_path;


	Mat	img_1 = imread(path + string("/image/aero1.jpg"));
	Mat	img_2 = imread(path + string("/image/aero3.jpg"));

	Mat add_ret = Mat::zeros(img_1.size(), img_1.type());

	for(int row =0; row<img_1.rows;row++)
	{
		for (int col = 0;col<img_1.cols;col++)
		{
			
			//P.S.
			//saturate_cast 是一个很好用的类型转换函数
			//saturate_cast<uchar> 是由于 图像的最大值 只能是255 所有在进行图像像素的操作后，会越界，那么这里采用saturate_cast<uchar>进行一下转换
			

			add_ret.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(img_1.at<Vec3b>(row, col)[0] + img_2.at<Vec3b>(row, col)[0]);
			add_ret.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(img_1.at<Vec3b>(row, col)[1] + img_2.at<Vec3b>(row, col)[1]);
			add_ret.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(img_1.at<Vec3b>(row, col)[2] + img_2.at<Vec3b>(row, col)[2]);


		}
	}

	imshow("add", add_ret);



}

