#pragma once
/*
 * ���ļ��������е�ѧϰ�����б�д����ϰ����
 * Ȼ����main����һ�¼���
 */

#include "opencv_lib.h"
#include <iostream>
#include <Windows.h>
#include <direct.h>
#include <string>


using namespace cv;
using namespace std;

#define MAX_PATH 80

void test();
 void read_show();
 void convert_write();
 void image_object();
 void oprational_pixel();

 void oprational_pixel_jjcx();
 void oprational_pixel_add_by_custom();
 void LUT();
 void Coustom_LUT();
 void Transform_test();
 void operator_and_xor();
 void split_merge();
 void convert_color();
 void means_stddev();
 void normalize_test();
 //void video_read_write();
 void image_flip();
void ImageInterpolation();
void draw_geometry();
void image_roi();

void histogram();
void histogram_equalization();

int stitchTest();


void TransformImageStart();