#pragma once
/*
 * ���ļ��������е�ѧϰ�����б�д����ϰ����
 * Ȼ����main����һ�¼���
 */

#include <opencv2/opencv.hpp>
#include <iostream>
#include <direct.h>
#include <string>


using namespace cv;
using namespace std;

#define MAX_PATH 80


void read_show();
void convert_write();
void image_object();
void oprational_pixel();

void oprational_pixel_jjcx();
void oprational_pixel_add_by_custom();
void LUT();
void Coustom_LUT();
void Transform();