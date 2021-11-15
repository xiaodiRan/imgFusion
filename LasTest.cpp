// LasTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "PointReader.h"
#include <pcl/visualization/cloud_viewer.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	string filename = "points.laz";
	SIT::PointReader* pointCloud = new SIT::PointReader;
	pointCloud->readPoints(filename);

	pcl::visualization::PCLVisualizer viewer1("Cloud Viewer1");
	viewer1.addPointCloud(pointCloud->cloud);
	viewer1.setBackgroundColor(0, 0, 0);

	pcl::visualization::PCLVisualizer viewer2("Cloud Viewer2");
	pointCloud->downSamplingPointCloud(pointCloud->cloud, 1, 1, 1);
	viewer2.addPointCloud(pointCloud->cloud);
	viewer2.setBackgroundColor(0, 0, 0);

	system("pause");
	return 0;
}

