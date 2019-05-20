#include "study_content.h"


//VideoCapture ��Ƶ�ļ���ȡ������ͷ��ȡ����Ƶ����ȡ
//VideoWriter ��Ƶд�����ļ����桢
//- CAP_PROP_FRAME_HEIGHT
//- CAP_PROP_FRAME_WIDTH
//- CAP_PROP_FRAME_COUNT
//- CAP_PROP_FPS
//��֧����Ƶ��������뱣�棬����һ������Ƶ����Ŀ⣡��Ҫ�Ƿ����������Ƶ���ݡ������ļ����֧�ֵ����ļ�Ϊ2G


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

	//д��Ƶ
	//CV_FOURCC('D', 'I', 'V', 'X') mp4��ʽ
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
		//���waitKey������� ��Ƶ������ʾ
		waitKey(0);
		writer.write(frame);
	}

	cap.release();
	writer.release();
}