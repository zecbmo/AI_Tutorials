#pragma once

#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <cassert>
#include <iomanip>


inline int RandInt(int x, int y)
{
	return rand() % (y - x + 1) + x;
}

//returns between 0 and 1
inline double RandFloat()
{
	return ((rand()) / (RAND_MAX + 1.0));
}