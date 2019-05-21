#include "study_content.h"


// 几何形状绘制
// 1.绘制几何形状
// - 绘制直线
// - 绘制圆
// - 绘制矩形
// - 绘制椭圆
// 2.填充几何形状
//
// OpenCV没有专门的填充方法，只是把绘制几何形状时候的线宽 - thickness参数值设置为负数即表示填充该几何形状或者使用参数CV_FILLED
//
// 随机数方法：
// RNG 表示OpenCV C++版本中的随机数对象，rng.uniform(a, b)生成[a, b)之间的随机数，包含a，但是不包含b。
//
// np.random.rand() 表示numpy中随机数生成，生成浮点数0～1的随机数, 包含0，不包含1。


void draw_geometry()
{
	Mat image = Mat::zeros(Size(512, 512), CV_8UC3);
	Rect rect(100, 100, 200, 200);
	// rectangle(image, rect, Scalar(255, 0, 0), 2, LINE_8, 0);
	// circle(image, Point(256, 256), 50, Scalar(0, 0, 255), 2, LINE_8, 0);
	// ellipse(image, Point(256, 256), Size(150, 50), 360, 0, 360, Scalar(0, 255, 0), 2, LINE_8, 0);
	// imshow("image", image);
	// waitKey(0);

	RNG rng(0xFFFFFF);
	//image.setTo(Scalar(0, 0, 0));

	for (int i = 0; i < 100000; i++) {
		image.setTo(Scalar(0, 0, 0));
		int x1 = rng.uniform(0, 512);
		int y1 = rng.uniform(0, 512);
		int x2 = rng.uniform(0, 512);
		int y2 = rng.uniform(0, 512);

		int b = rng.uniform(0, 256);
		int g = rng.uniform(0, 256);
		int r = rng.uniform(0, 256);
		line(image, Point(x1, y1), Point(x2, y2), Scalar(b, g, r), 1, LINE_AA, 0);
		rect.x = x1;
		rect.y = y1;
		rect.width = x2 - x1;
		rect.height = y2 - y1;
		rectangle(image, rect, Scalar(b, g, r), 1, LINE_AA, 0);
		imshow("image", image);
		char c = waitKey(20);
		if (c == 27)
			break;

		imshow("image", image);
	}
	waitKey(0);
}