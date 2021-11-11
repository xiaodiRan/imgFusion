#pragma once
#include "defs.h"
#include "BaseReader.h"
#include "lasreader.hpp"
namespace SIT {
	class LasReader :public BaseReader {
	public:
		LasReader() = default;
		void readPoints(string filename) override;
		~LasReader() = default;
	};
}
