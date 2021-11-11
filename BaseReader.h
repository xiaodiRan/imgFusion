#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stddef.h>
using namespace std;
namespace SIT {
	struct PointInfo {
		double x;
		double y;
		double z;
		uint16_t r;
		uint16_t g;
		uint16_t b;
		PointInfo(double _x, double _y, double _z, int _r = -1, int _g = -1, int _b = -1) :x(_x), y(_y), z(_z), r(_r), g(_g), b(_b) {};
		friend ostream& operator<<(ostream& os, const PointInfo& p) {
			os << p.x << "\t" << p.y << "\t" << p.z << "\t" << p.r << "\t" << p.g << "\t" << p.b << "\n";
			return os;
		}
	};
	class BaseReader {
	public:
		vector<PointInfo> points;
		BaseReader() = default;
		uint64_t numberOfPoints() const { return points.size(); }
		virtual void readPoints(string filname) = 0;
		virtual PointInfo operator[](int i) { return points[i]; }
		virtual ~BaseReader() = default;
	};

}

