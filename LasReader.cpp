#include "LasReader.h"

namespace SIT {
	void LasReader::readPoints(string filename) {
		LASreadOpener lasreadopener;
		lasreadopener.set_file_name(filename.c_str());
		LASreader* lasreader = lasreadopener.open();
		while (lasreader->read_point()) {
			if (lasreader->point.have_rgb) points.push_back({ lasreader->point.X,lasreader->point.Y,lasreader->point.Z,\
				lasreader->point.rgb[0],lasreader->point.rgb[1],lasreader->point.rgb[2] });
			else points.push_back({ lasreader->point.X,lasreader->point.Y,lasreader->point.Z });
		}
	}
}