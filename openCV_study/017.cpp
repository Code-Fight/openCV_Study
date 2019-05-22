#include "study_content.h"

//ͼ��ֱ��ͼ
//
//ͼ��ֱ��ͼ�Ľ���
//ͼ��ֱ��ͼ��ͼ������ֵ��ͳ��ѧ������������۽�С������ͼ��ƽ�ơ���ת�����Ų����Ե��ڶ��ŵ㣬
//�㷺��Ӧ����ͼ����ĸ��������ر��ǻҶ�ͼ�����ֵ�ָ������ɫ��ͼ������Լ�ͼ����ࡢ����ͶӰ���١������ķ�Ϊ
//- �Ҷ�ֱ��ͼ
//- ��ɫֱ��ͼ
//
// ͨ�׾�����ɫֵ��ͳ��
//
//Bins��ֱָ��ͼ�Ĵ�С��Χ�� ��������ֵȡֵ��0��255֮��ģ�������256��bin�����⻹������16��32��48��128�ȣ�256����bin�Ĵ�СӦ������������
//
//OpenCV�����API
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
	// ��ͨ������
	vector<Mat> bgr_plane;
	split(src, bgr_plane);
	// �����������
	const int channels[1] = { 0 };
	const int bins[1] = { 256 };
	float hranges[2] = { 0,255 };
	const float* ranges[1] = { hranges };
	Mat b_hist;
	Mat g_hist;
	Mat r_hist;
	// ����Blue, Green, Redͨ����ֱ��ͼ
	calcHist(&bgr_plane[0], 1, 0, Mat(), b_hist, 1, bins, ranges);
	calcHist(&bgr_plane[1], 1, 0, Mat(), g_hist, 1, bins, ranges);
	calcHist(&bgr_plane[2], 1, 0, Mat(), r_hist, 1, bins, ranges);
	// ��ʾֱ��ͼ
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / bins[0]);
	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
	// ��һ��ֱ��ͼ����
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	// ����ֱ��ͼ����
	for (int i = 1; i < bins[0]; i++) {
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, 8, 0);
	}
	// ��ʾֱ��ͼ
	namedWindow("Histogram Demo", WINDOW_AUTOSIZE);
	imshow("Histogram Demo", histImage);
}