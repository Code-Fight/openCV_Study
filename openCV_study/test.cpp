#include "study_content.h"


void test()
{
	Mat A = Mat::ones(3, 3, CV_32FC1);
	Mat B = Mat::ones(3, 1, CV_32FC1);
	Mat AB;

	A.at<float>(0, 0) = 1;
	A.at<float>(0, 1) = 2;
	A.at<float>(0, 2) = 3;
	A.at<float>(1, 0) = 4;
	A.at<float>(1, 1) = 5;
	A.at<float>(1, 2) = 6;
	A.at<float>(2, 0) = 4;
	A.at<float>(2, 1) = 5;
	A.at<float>(2, 2) = 6;

	B.at<float>(0, 0) = 1;
	B.at<float>(1, 0) = 2;
	B.at<float>(2, 0) = 3;

	AB = A*B;

	cout << "A=\n" << A << endl << endl;
	cout << "B=\n" << B << endl << endl;

	cout << "AB-X'=\n" << AB.row(0) << endl << endl;
	cout << "AB-Y'=\n" << AB.row(1) << endl << endl;
	cout << "AB-Z'=\n" << AB.row(2) << endl << endl;
}