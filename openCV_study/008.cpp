#include "study_content.h"

// 知识点： 通道分离与合并
// OpenCV中默认imread函数加载图像文件，
// 加载进来的是三通道彩色图像，
// 色彩空间是RGB色彩空间、
// 通道顺序是BGR（蓝色、绿色、红色）、
// 对于三通道的图像OpenCV中提供了两个API函数用以实现通道分离与合并。
//
// - split // 通道分类
// - merge // 通道合并


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
	//消除red
	
	src_[0]=(src_split[0]);
	src_[1]=(src_split[1]);
	src_[2] = (n);
	merge(src_, dst);
	imshow("not R", dst);
	//src_.clear();

	//消除Green
	src_[0] = (src_split[0]);
	src_[1] = (n);
	src_[2] = (src_split[2]);
	merge(src_, dst);
	imshow("not G", dst);
	

	//消除Blue
	src_[0] = (n);
	src_[1] = (src_split[1]);
	src_[2] = (src_split[2]);
	merge(src_, dst);
	imshow("not B", dst);

	



	



	

}