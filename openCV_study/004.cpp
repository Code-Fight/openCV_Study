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
				//�������ص���ɫ��ת����
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
				//TODO:͸��ͼ��
			}

		}
	}
	return src;
	
}

//ͨ��ָ���ȡ����

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
				//K++ ��ִ�� ��ֵ���� Ȼ����� �Լ�
				blue = *curr_row++;
				green = *curr_row++;
				red = *curr_row++;

				//K++ ��ִ�� ��ֵ���� Ȼ����� �Լ�
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
	//ͨ��for�������ݵķ�ʽ��ȡ����
	//ע�� ��ɫͼ�ͻҶ�ͼ��ͨ����һ��
	Mat src = imread("test.jpg");	
	//imshow("3channel", loop(src));

	Mat src_g = imread("gray.png");
	//imshow("1channel", loop(src_g));


	//ͨ��for����ָ���ȡ����
	//ע�� ��ɫͼ�ͻҶ�ͼ��ͨ����һ��
	//imshow("3channel", loop_ptr(src));

	//imshow("1channel", loop_ptr(src_g));

}
