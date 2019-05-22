#include "study_content.h"

// ͼ��ֱ��ͼ���⻯
//
// ͼ��ֱ��ͼ���⻯��������ͼ����ǿ��
// ������ͼ�����ֱ��ͼ���⻯����
// ���������������׼ȷ����OpenCV�������Ĵ�����ʾ���Ѿ��ܳ�����
// �����ҽѧӰ��ͼ��������ң��ͼ��Ҳ����ͨ��ֱ��ͼ���⻯������ͼ��������
//
// OpenCV��ֱ��ͼ���⻯��API�ܼ�
// - equalizeHist(src, dst)


void  histogram_equalization()
{
	Mat src = imread("home.jpg");

	if (src.empty()) {
		printf("could not load image...\n");
		return ;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	Mat gray, dst;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	imshow("input", gray);
	equalizeHist(gray, dst);
	imshow("eq", dst);

}
