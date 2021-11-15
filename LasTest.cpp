// LasTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>

#include "PointReader.h"
#include <pcl/visualization/cloud_viewer.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	string filename = "01.ply";
	SIT::PointReader* pointCloud = new SIT::PointReader;
	pointCloud->readPoints(filename);

	pcl::visualization::CloudViewer viewer1("Cloud Viewer1");
	viewer1.showCloud(pointCloud->cloud);

	pcl::visualization::CloudViewer viewer2("Cloud Viewer2");
	pointCloud->downSamplingPointCloud(pointCloud->cloud, 0.01, 0.01, 0.01);
	viewer2.showCloud(pointCloud->cloud);

	system("pause");
	return 0;
}

