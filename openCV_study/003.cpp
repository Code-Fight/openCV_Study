#include "study_content.h"


void image_object()
{
	Mat src = imread("test.jpg");

	//clone & copy
	//����Ӵ������oop���ԣ������е㲻̫һ��
	//һ��copy���������ǳ���� �������� ��copy��cloneЧ��һ��
	//��������������ڴ�ĸ���
	Mat img_clone,img_copy;
	img_clone = src.clone();
	src.copyTo(img_copy);

	
	imshow("img_clone", img_clone);
	imshow("img_copy", img_copy);

	//��ֵ
	Mat img_e = src;
	imshow("img_e", img_copy);

	//�����հ�ͼ��
	Mat img_blank_1 = Mat::zeros(src.size(), src.type());

	imshow("img_blank_1", img_blank_1);

	Mat img_blank_2 = Mat::zeros(Size(512,512),CV_8UC3);
	imshow("img_blank_2", img_blank_2);

	Mat img_blank_3 = Mat::ones(Size(512, 512), CV_8UC3);
	imshow("img_blank_3", img_blank_3);


	//Mat_��һ��Ӧ���ھ���(matrix)�����㡣
	//Mat_��̳���Mat��,���������͸������ɶ���ΪMat_<_Tp>�ľ�����ʽ
	// 0, -1, 0
	// -1, 5, -1
	// 0, -1, 0
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);










}