#include "study_content.h"

/*
 *  Look Up Table(LUT)查找表
 *  只要为做颜色替换，比如对比度、二值化
 *  
 *  - applyColorMap(src, dst, COLORMAP)
 *  - src 表示输入图像
 *  - dst表示输出图像
 *  - 匹配到的颜色LUT， OpenCV支持13种颜色风格的查找表映射
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
 * LUT的关键用法
 * 实现自己的color_map 然后重复利用
 * 灰度图 到 二值化 手动实现
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
	//读取灰度图 必须加 读取参数 IMREAD_GRAYSCALE 否则默认是彩色图像
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