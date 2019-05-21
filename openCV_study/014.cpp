#include "study_content.h"

//ͼ���ֵ(Image Interpolation)
//������ֲ�ֵ�㷨
//INTER_NEAREST = 0  ����� �ٶȿ�
//INTER_LINEAR = 1
//INTER_CUBIC = 2 ����������ֵ
//INTER_LANCZOS4 = 4 Lanczos��ֵ
//��ص�Ӧ�ó���
//���α任��͸�ӱ任����ֵ����������
//resize,
//���size��ֵ��ʹ��size��������ֵ���������fx��fy
//�����


void ImageInterpolation()
{
	Mat src = imread("home.jpg");

	Mat dst;
	resize(src, dst, Size(src.size().width * 2, src.size().height * 2), 0, 0, INTER_NEAREST);
	imshow("INTER_NEAREST",dst);

	resize(src, dst, Size(src.size().width * 2, src.size().height * 2), 0, 0, INTER_LINEAR);
	imshow("INTER_LINEAR", dst);

	resize(src, dst, Size(src.size().width * 2, src.size().height * 2), 0, 0, INTER_CUBIC);
	imshow("INTER_CUBIC", dst);

	resize(src, dst, Size(src.size().width * 2, src.size().height * 2), 0, 0, INTER_CUBIC);
	imshow("INTER_LANCZOS4", dst);
}