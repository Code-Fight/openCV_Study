#include "study_content.h"


// ֪ʶ�㣺 ���ع�һ��
//
// OpenCV���ṩ�����ֹ�һ���ķ���
// - NORM_MINMAX
// - NORM_INF
// - NORM_L1 �ܺ�Ϊ1
// - NORM_L2 ��λ����Ϊ1
// ��õľ���NORM_MINMAX��һ��������
//
// ���API������
// normalize(
// 	InputArray 	src, // ����ͼ��
// 	InputOutputArray 	dst, // ���ͼ��
// 	double 	alpha = 1, // NORM_MINMAXʱ���ֵ
// 	double 	beta = 0, // NORM_MINMAXʱ���ֵ
// 	int 	norm_type = NORM_L2, // ֻ��alpha
// 	int 	dtype = -1, // Ĭ��������srcһ��
// 	InputArray 	mask = noArray() // maskĬ��ֵΪ��
// )


void normalize_test()
{
	Mat src = imread("home.jpg");
	Mat gray =src;
	cvtColor(src, gray, COLOR_BGR2GRAY);

	//ת��Ϊ������
	gray.convertTo(gray, CV_32F);

	//NORM_MINMAX ������ֻ��Ҫ�滻���һ����������
	Mat dst = Mat::zeros(gray.size(), CV_32FC1);
	normalize(gray, dst, 1.0, 0, NORM_MINMAX);
	Mat result = dst * 255;
	result.convertTo(dst, CV_8UC1);
	imshow("NORM_MINMAX", dst);

}