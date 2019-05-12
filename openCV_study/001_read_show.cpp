#include "study_content.h"

/*
 *
 */
void read_show()
{
	Mat image = imread("test.jpg");
	namedWindow("test show", WINDOW_AUTOSIZE);
	imshow("test show", image);

}