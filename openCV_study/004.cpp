#include "study_content.h"



Mat loop(Mat src)
{
	int img_h = src.rows;
	int img_w = src.cols;
	int channel = src.channels();

	for (int row = 0; row<img_h; row++)
	{
		for (int col = 0; col<img_w; col++)
		{
			if (channel == 3)
			{
				Vec3b bgr = src.at<Vec3b>(row, col);
				//进行像素点颜色翻转操作
				bgr[0] = 255 - bgr[0];
				bgr[1] = 255 - bgr[1];
				bgr[2] = 255 - bgr[2];
				src.at<Vec3b>(row, col) = bgr;
			}
			else if (channel == 1)
			{
				int gray = src.at<uchar>(row, col);
				src.at<uchar>(row, col) = 255 - gray;
			}
			else if (channel == 4)
			{
				//TODO:透明图像
			}

		}
	}
	return src;
	
}

//通过指针读取像素

Mat loop_ptr(Mat src)
{
	Mat result = Mat::zeros(src.size(), src.type());

	int blue = 0, green = 0, red = 0;
	int gray = 0;

	for (int row =0;row<src.rows;row++)
	{
		uchar* curr_row = src.ptr<uchar>(row);
		uchar* result_row = result.ptr<uchar>(row);
		for (int col=0;col<src.cols;col++)
		{
			if (src.channels()==3)
			{
				//K++ 先执行 赋值操作 然后进行 自加
				blue = *curr_row++;
				green = *curr_row++;
				red = *curr_row++;

				//K++ 先执行 赋值操作 然后进行 自加
				*result_row++ = blue;
				*result_row++ = green;
				*result_row++ = red;


			}
			else if (src.channels() == 1)
			{
				gray = *curr_row++;
				*result_row ++= gray;
			}

		}
	}

	return result;

}



void oprational_pixel()
{
	//通过for遍历数据的方式获取像素
	//注意 彩色图和灰度图的通道不一致
	Mat src = imread("test.jpg");	
	//imshow("3channel", loop(src));

	Mat src_g = imread("gray.png");
	//imshow("1channel", loop(src_g));


	//通过for遍历指针获取像素
	//注意 彩色图和灰度图的通道不一致
	//imshow("3channel", loop_ptr(src));

	//imshow("1channel", loop_ptr(src_g));

}
