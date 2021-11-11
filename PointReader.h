#pragma once
#include "BaseReader.h"
#include "LasReader.h"
#include "PcdReader.h"
namespace SIT {
	class PointReader {
	private:
		BaseReader* reader;
	public:
		PointReader() = default;
		void readPoints(string filename);
	};
}