#include "study_content.h"

/*
 *
 */
void read_show()
{
	// int flags = IMREAD_COLOR
	//�ڶ�����ȡ���� ����Ҫ  һ��Ҫ����ʵ��ͼƬ����ʽ��д  �����Ĭ�ϲ�ɫͼ��
	//�������ȡ����һ��gray��Ҳ�Ƿ��� channel��3
	Mat image = imread("test.jpg", IMREAD_COLOR);
	namedWindow("test show", WINDOW_AUTOSIZE);
	imshow("test show", image);

}