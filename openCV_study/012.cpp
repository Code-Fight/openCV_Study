#include "study_content.h"


//VideoCapture 视频文件读取、摄像头读取、视频流读取
//VideoWriter 视频写出、文件保存、
//- CAP_PROP_FRAME_HEIGHT
//- CAP_PROP_FRAME_WIDTH
//- CAP_PROP_FRAME_COUNT
//- CAP_PROP_FPS
//不支持音频编码与解码保存，不是一个音视频处理的库！主要是分析与解析视频内容。保存文件最大支持单个文件为2G


void video_read_write()
{
	char current_path[MAX_PATH];
	_getcwd(current_path, MAX_PATH);
	string path = current_path;
	VideoCapture cap;
	cap.open("e:\\1.mp4");
	int height = (int)cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	int width = (int)cap.get(CV_CAP_PROP_FRAME_WIDTH);
	int fps = (int)cap.get(CV_CAP_PROP_FPS);
	cout<<"CV_CAP_PROP_FRAME_HEIGHT:"<<height<<endl;
	cout << "CV_CAP_PROP_FRAME_WIDTH:" << width<<endl;
	cout << "CV_CAP_PROP_FPS:" << fps<<endl;

	//写视频
	//CV_FOURCC('D', 'I', 'V', 'X') mp4格式
	VideoWriter writer("out.mp4", CV_FOURCC('D', 'I', 'V', 'X'), fps, Size(width, height), true);

	Mat frame;
	namedWindow("cshow", CV_WINDOW_AUTOSIZE);
	while(cap.read(frame))
	{
		if (frame.empty())
		{
			continue;
		}
		imshow("cshow", frame);
		//这个waitKey如果不加 视频不会显示
		waitKey(0);
		writer.write(frame);
	}

	cap.release();
	writer.release();
}