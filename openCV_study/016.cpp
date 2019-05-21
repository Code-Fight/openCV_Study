#include "study_content.h"

// ͼ��ROI��ROI����
// ͼ��ROI���� :
// ͼ���ROI(region of interest)��ָͼ���и���Ȥ������OpenCV��ͼ������ͼ��ROI����ʵ��ֻ��ROI���������
//
// 1. ����ROI������ȡ
// 2. ����ROI����copy
//
// 3. ������ROI����
// - ROI����mask����
// - ����λ and����
// - ��ȡ��ROI����
// - �ӱ���or����
// - add ������ROI����

void image_roi()
{
	//=================����ROI=================
	Mat src = imread("test2.jpg");
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	// ��ȡROI
	Rect rect(606, 0, 1099-606, 1080);
	Mat roi = src(rect);
	imshow("roi", roi);
	
	Mat image = roi.clone();
	// modify ROI
	roi.setTo(Scalar(255, 0, 0));
	imshow("result", src);

	// modify copy roi
	image.setTo(Scalar(0, 0, 255));
	imshow("copy roi", image);

	//=================������ROI=================
	// example with ROI - generate mask
	Mat src2 = imread("timg.jpeg");
	imshow("src2", src2);
	Mat hsv, mask;
	cvtColor(src2, hsv, COLOR_BGR2HSV);
	inRange(hsv, Scalar(35, 43, 46), Scalar(99, 255, 255), mask);
	imshow("mask", mask);

	// extract person ROI
	Mat person;
	bitwise_not(mask, mask);
	//��ɫ�ǵ�ǰROI��������� Ҳ������
	imshow("mask", mask);
	//��ȡ��ɫ�������
	bitwise_and(src2, src2, person,mask);
	imshow("person", person);

	// generate background
	Mat result = Mat::zeros(src2.size(), src2.type());
	result.setTo(Scalar(255, 0, 0));

	// combine background + person
	Mat dst;
	//ȡ����ROI
	bitwise_not(mask, mask);
	//����ROI�ں�
	bitwise_or(person, result, dst, mask);
	//���� �� �� ���
	// bitwise_or(person, dst, dst); ����������Ч��һ��
	add(dst, person, dst);

	imshow("dst", dst);
	waitKey(0);
}