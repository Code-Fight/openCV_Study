#include "study_content.h"

//ͼ��ת(Image Flip)
//ͼ��ת�ı�������ӳ�䣬OpenCV֧������ͼ��ת��ʽ
//- X�ᷭת��flipcode = 0
//- Y�ᷭת, flipcode = 1
//- XY�ᷭת, flipcode = -1
//
//��ص�API
//flip
//- src�������
//- dst ��ת��ͼ��
//- flipcode

void image_flip()
{
	Mat dst;
	Mat	 src = imread("home.jpg");
	if (src.empty())
	{
		cout << "image empty" << endl;
		return;
	}

	//x ��ת
	flip(src, dst, 0);
	imshow("X", dst);

	//y ��ת
	flip(src, dst, 1);
	imshow("Y", dst);

	//xy ��ת
	flip(src, dst,-1);
	imshow("XY", dst);
}