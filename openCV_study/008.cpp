#include "study_content.h"

// ֪ʶ�㣺 ͨ��������ϲ�
// OpenCV��Ĭ��imread��������ͼ���ļ���
// ���ؽ���������ͨ����ɫͼ��
// ɫ�ʿռ���RGBɫ�ʿռ䡢
// ͨ��˳����BGR����ɫ����ɫ����ɫ����
// ������ͨ����ͼ��OpenCV���ṩ������API��������ʵ��ͨ��������ϲ���
//
// - split // ͨ������
// - merge // ͨ���ϲ�


void split_merge()
{
	Mat src = imread("home.jpg");
	vector<Mat> src_split;
	split(src, src_split);

	
	// imshow("B", src_split[0]);
	// imshow("G", src_split[1]);
	// imshow("R", src_split[2]);


	Mat dst;

	vector<Mat> src_(3);
	Mat n = Mat::zeros(src_split[0].size(), src_split[0].type());
	//����red
	
	src_[0]=(src_split[0]);
	src_[1]=(src_split[1]);
	src_[2] = (n);
	merge(src_, dst);
	imshow("not R", dst);
	//src_.clear();

	//����Green
	src_[0] = (src_split[0]);
	src_[1] = (n);
	src_[2] = (src_split[2]);
	merge(src_, dst);
	imshow("not G", dst);
	

	//����Blue
	src_[0] = (n);
	src_[1] = (src_split[1]);
	src_[2] = (src_split[2]);
	merge(src_, dst);
	imshow("not B", dst);

	



	



	

}