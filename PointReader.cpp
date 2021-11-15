#include "PointReader.h"

namespace SIT {
	void PointReader::readPoints(string filename)
	{
		string filenameSubfix = filename.substr(filename.size() - 3, 3);
		if (filename.empty() || (filenameSubfix != "las" && filenameSubfix != "laz" \
			&& filenameSubfix != "pcd" && filenameSubfix != "ply")) {
			PCL_ERROR("This file CANNOT BE READ, please check the type!");
			return;
		}

		if (filenameSubfix == "las" || filenameSubfix == "laz") {
			LASreadOpener lasreadopener;
			lasreadopener.set_file_name(filename.c_str());
			LASreader* lasreader = lasreadopener.open();
			size_t count = lasreader->header.number_of_point_records;
			this->cloud->resize(count);
			this->cloud->width = 1;
			this->cloud->height = count;
			this->cloud->is_dense = false;
			size_t i = 0;
			while (lasreader->read_point() && i < count) {
				if (!lasreader->point.have_rgb) {
					PCL_ERROR("This file has NO COLOR, please check the type!");
					return;
				}
				this->cloud->points[i].x = lasreader->point.get_x();
				this->cloud->points[i].y = lasreader->point.get_y();
				this->cloud->points[i].z = lasreader->point.get_z();
				++i;
			}
		}
		else if (filenameSubfix == "pcd") {
			if (pcl::io::loadPCDFile<pcl::PointXYZRGB>(filename, *(this->cloud)) == -1) {
				PCL_ERROR("read pcd file failed!");
				return;
			}
		}
		else if (filenameSubfix == "ply") {
			if (pcl::io::loadPLYFile<pcl::PointXYZRGB>(filename, *(this->cloud)) == -1) {
				PCL_ERROR("read ply file failed!");
				return;
			}
		}
	}
	void PointReader::downSamplingPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double length, double width, double height)
	{
		pcl::VoxelGrid<pcl::PointXYZRGB> filter;
		filter.setInputCloud(cloud);
		filter.setLeafSize(length, width, height);
		filter.filter(*cloud);
	}
}