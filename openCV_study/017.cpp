#include "study_content.h"

//图像直方图
//
//图像直方图的解释
//图像直方图是图像像素值的统计学特征、计算代价较小，具有图像平移、旋转、缩放不变性等众多优点，
//广泛地应用于图像处理的各个领域，特别是灰度图像的阈值分割、基于颜色的图像检索以及图像分类、反向投影跟踪。常见的分为
//- 灰度直方图
//- 颜色直方图
//
// 通俗就是颜色值的统计
//
//Bins是指直方图的大小范围， 对于像素值取值在0～255之间的，最少有256个bin，此外还可以有16、32、48、128等，256除以bin的大小应该是整数倍。
//
//OpenCV中相关API
//calcHist(&bgr_plane[0], 1, 0, Mat(), b_hist, 1, bins, ranges);
//cv.calcHist([image], [i], None, [256], [0, 256])


void histogram()
{
	Mat src = imread("home.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return;
	}
	namedWindow("input image", WINDOW_AUTOSIZE);
	imshow("input image", src);
	// 三通道分离
	vector<Mat> bgr_plane;
	split(src, bgr_plane);
	// 定义参数变量
	const int channels[1] = { 0 };
	const int bins[1] = { 256 };
	float hranges[2] = { 0,255 };
	const float* ranges[1] = { hranges };
	Mat b_hist;
	Mat g_hist;
	Mat r_hist;
	// 计算Blue, Green, Red通道的直方图
	calcHist(&bgr_plane[0], 1, 0, Mat(), b_hist, 1, bins, ranges);
	calcHist(&bgr_plane[1], 1, 0, Mat(), g_hist, 1, bins, ranges);
	calcHist(&bgr_plane[2], 1, 0, Mat(), r_hist, 1, bins, ranges);
	// 显示直方图
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / bins[0]);
	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
	// 归一化直方图数据
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	// 绘制直方图曲线
	for (int i = 1; i < bins[0]; i++) {
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, 8, 0);
	}
	// 显示直方图
	namedWindow("Histogram Demo", WINDOW_AUTOSIZE);
	imshow("Histogram Demo", histImage);
}