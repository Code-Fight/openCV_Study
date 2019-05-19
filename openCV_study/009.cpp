#include "study_content.h"

//֪ʶ�㣺 ɫ�ʿռ���ɫ�ʿռ�ת��
//- RGBɫ�ʿռ� ͨ��
//- HSVɫ�ʿռ� ֱ��ͼ��ص�ͼ�����㷨 ����
//- YUVɫ�ʿռ� ŷ������ı�׼ Android linux ��ԭʼ������
//- YCrCbɫ�ʿռ� Ƥ�����
//
//API֪ʶ��
//- ɫ�ʿռ�ת��cvtColor
//- ��ȡָ��ɫ�ʷ�Χ����inRange


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