#pragma once

#include <vector>
#include <fstream>
#include <nfd.h>

#include "Sector.h"
#include "RaycastInfo.h"

class Utils
{
public:

	static RaycastInfo cast_ray();
	static void load_map(std::vector<Sector>& sectors);
private:
};

