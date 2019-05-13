#include "study_content.h"

/*
 *  Look Up Table(LUT)���ұ�
 *  ֻҪΪ����ɫ�滻������Աȶȡ���ֵ��
 *  
 *  - applyColorMap(src, dst, COLORMAP)
 *  - src ��ʾ����ͼ��
 *  - dst��ʾ���ͼ��
 *  - ƥ�䵽����ɫLUT�� OpenCV֧��13����ɫ���Ĳ��ұ�ӳ��
 */
void LUT()
{
	char current_path[MAX_PATH];
	_getcwd(current_path, MAX_PATH);
	string path = current_path;


	Mat	img_1 = imread(path + string("/image/aero1.jpg"));
	Mat ret = Mat::zeros(img_1.size(), img_1.type());
	applyColorMap(img_1, ret, COLORMAP_HOT);
	imshow("LUT", ret);


}

/*
 * LUT�Ĺؼ��÷�
 * ʵ���Լ���color_map Ȼ���ظ�����
 * �Ҷ�ͼ �� ��ֵ�� �ֶ�ʵ��
 */
void Coustom_LUT()
{
	char current_path[MAX_PATH];
	_getcwd(current_path, MAX_PATH);
	string path = current_path;

	int color_map[256];

	for (int i=0;i<256;i++)
	{
		if (i < 127)
			color_map[i] = 0;
		else
		{
			color_map[i] = 255;
		}
	}
	//��ȡ�Ҷ�ͼ ����� ��ȡ���� IMREAD_GRAYSCALE ����Ĭ���ǲ�ɫͼ��
	Mat	img_1 = imread(path + string("/image/gray.png"), IMREAD_GRAYSCALE);
	Mat img_Ret = Mat::zeros(img_1.size(), img_1.type());
	int h = img_1.rows;
	int w = img_1.cols;
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			int pv = img_1.at<uchar>(row, col);
			//cout << row << "," << col << endl;
			//print("%d,%d",)
			img_Ret.at<uchar>(row, col) =color_map[pv];
		}
	}


	imshow("coustom_color_map", img_Ret);
}