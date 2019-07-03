#include "study_content.h"

#include <io.h>
#include <stdio.h>
char dir[100];
char out_dir[100];


void TransformImage(char *filename, Mat M,Rect R)
{
	char current_path[MAX_PATH];
	_getcwd(current_path, MAX_PATH);
	string path = current_path;

	string input_dir = dir;
	string out_dir = ::out_dir;
	string _filename = filename;
	
	Mat image = imread(input_dir + _filename);
	if (image.empty())
	{
		cout << "image empty." << endl;
		return;
	}
	
	cv::Mat perspective;
	cv::warpPerspective(image, perspective, M, cv::Size(1920, 1080), cv::INTER_LINEAR);

	//cut
	Mat perspective_cut = perspective(R);
	imwrite(out_dir+ _filename, perspective_cut);
}




void TransformImageStart()
{
	char current_path[MAX_PATH];
	_getcwd(current_path, MAX_PATH);
	string path = current_path;
	cout << "��ǰ����Ŀ¼��" << path << endl;
	// ����Ŀ¼�µ������ļ�
	
	char channel[100];
	cout << "����Ŀ¼: ";
	cin.getline(dir, 100);
	cout << "����Ŀ¼: ";
	cin.getline(out_dir, 100);
	cout << "ͨ����: ";
	cin.getline(channel, 100);

	strcat_s(dir, "\\");
	strcat_s(out_dir, "\\");


	char temp_dir[100];

	strcpy_s(temp_dir, dir);
	strcat_s(temp_dir, "*.*");    // ��Ҫ��Ŀ¼�������*.*��ʾ�����ļ�/Ŀ¼
	


	HANDLE hFind;
	WIN32_FIND_DATA findData;
	LARGE_INTEGER size;
	hFind = FindFirstFile(temp_dir, &findData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		cout << "Failed to find first file!\n";
		return;
	}


	//���ر任����ͽ�ͼ��roi
	cv::Mat M;
	Rect R;
	
	FileStorage fs(current_path+ string("/TransformMatrix.xml"), FileStorage::READ);
	string channel_str = channel;
	fs["T-"+ channel_str] >> M;
	fs["C-"+ channel_str] >> R;
	fs.release();
	if (M.empty())
	{
		cout << "δ�ҵ�͸�ӱ任����." << endl;
		return;
	}


	do
	{
		// ����"."��".."������� 
		if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0)
			continue;
		if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)    // �Ƿ���Ŀ¼ 
		{
			cout << findData.cFileName <<endl;
			continue;
		}
		else
		{
			TransformImage(findData.cFileName,M,R);
			cout << findData.cFileName <<endl;
		}
	} while (FindNextFile(hFind, &findData));
	cout << "Done!\n";
}


void Test(uchar *pIn, int lenIn, uchar* pOut, int &lenOut)
{
	cv::Mat mat;
	vector<uchar> vectorOut;
	cv::imencode("bmp", mat, vectorOut);
	memcpy(pOut, &vectorOut[0], vectorOut.size());
	lenOut = vectorOut.size();
}