#pragma once
/*
 * 改文件保存所有的学习过程中编写的练习代码
 * 然后由main调用一下即可
 */

#include <opencv2/opencv.hpp>
#include <iostream>
#include <Windows.h>
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
 void operator_and_xor();
 void split_merge();
 void convert_color();
 void means_stddev();
 void normalize_test();
 void video_read_write();
 void image_flip();
void ImageInterpolation();
void draw_geometry();
void image_roi();