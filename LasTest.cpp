// LasTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <opencv2/opencv.hpp>
#include "lasreader.hpp"
using namespace std;
using namespace cv;
int main()
{
	LASreadOpener lasreadopener;
	lasreadopener.set_file_name("E:/vs-projects/LasTest/points.laz");
	LASreader* lasreader = lasreadopener.open();
	while (lasreader->read_point())
		cout << lasreader->point.get_x() << "  " << lasreader->point.get_y() << "  " << lasreader->point.get_z()<<"\n";

}

