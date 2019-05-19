#include "study_content.h"


/*
 *֪ʶ�㣺 ���ز���֮�߼�����
 *bitwise_and  ��
 *bitwise_xor  ���
 *bitwise_or   ��
 *bitwise_not  ��
 *
 *���еĲ��������������ֵ
 */



void operator_and_xor()
{
	// create image 
	Mat src = Mat::zeros(Size(400, 400), CV_8UC3);
	Mat src2 = Mat::zeros(Size(400, 400), CV_8UC3);

	//set color
	Rect r = Rect(50, 50, 100, 100);

	src(r) = Scalar(0, 0, 255);
	src2(Rect(100, 100, 100, 100)) = Scalar(0,0, 255);

	// xor and or
	Mat dst_and, dst_xor, dst_or;
	// and �ص��Ĳ���
	bitwise_and(src, src2, dst_and);
	// xor ���ԵĲ��ֵĺ� ȥ���ص��Ĳ���
	bitwise_xor(src, src2, dst_xor);
	// or ����
	bitwise_or(src, src2, dst_or);

	//show 
	imshow("dst_and", dst_and);
	imshow("bitwise_xor", dst_xor);
	imshow("bitwise_or", dst_or);


	//not
	Mat dst_not;
	Mat src_not = imread("LinuxLogo.jpg");

	bitwise_not(src_not, dst_not);

	imshow("src for not", src_not);
	imshow("dst for not", dst_not);
}