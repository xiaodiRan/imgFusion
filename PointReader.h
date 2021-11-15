//#define PCL_NO_PRECOMPILE
#define NOMINMAX
#include <string>
#include <stddef.h>

#include "lasreader.hpp"
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

using namespace std;

namespace SIT {
	class PointReader {
	public:
		pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud;
		PointReader() {
			cloud = pcl::PointCloud<pcl::PointXYZRGB>::Ptr(new pcl::PointCloud<pcl::PointXYZRGB>);
		}
		void readPoints(string filename);
		void downSamplingPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double length, double width, double height);
		~PointReader() { }
	};
}