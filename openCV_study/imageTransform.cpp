#include "study_content.h"



cv::Mat get_perspective_mat()
{
	// cv::Point2f src_points[] = {
	// 	cv::Point2f(208, 1080),
	// 	cv::Point2f(1594, 1080),
	// 	cv::Point2f(837, 425),
	// 	cv::Point2f(1219, 425) };
	//
	// cv::Point2f dst_points[] = {
	// 	cv::Point2f(208, 1080),
	// 	cv::Point2f(1594, 1080),
	// 	cv::Point2f(208, 0),
	// 	cv::Point2f(1594, 0) };


	cv::Point2f src_points[] = {
		cv::Point2f(158, 1080),
		cv::Point2f(1632, 1080),
		cv::Point2f(715, 542),
		cv::Point2f(1075, 542) };

	cv::Point2f dst_points[] = {
		cv::Point2f(600, 1080),
		cv::Point2f(1075, 1080),
		cv::Point2f(715, 0),
		cv::Point2f(1075, 0) };

	cv::Mat M = cv::getPerspectiveTransform(src_points, dst_points);

	return M;

}

void Transform()
{
	char current_path[MAX_PATH];
	_getcwd(current_path, MAX_PATH);
	string path = current_path;


	
	Mat image = imread(path + string("/image/video_image_3.jpg"));
	if (image.empty())
	{
		cout << "image empty" << endl;
	}
	cv::Mat perspective;
	Mat M = get_perspective_mat();
	cv::warpPerspective(image, perspective, M, cv::Size(1920, 1080), cv::INTER_LINEAR);

	//imshow("show",perspective);
	imwrite("test2.jpg",perspective);
}
