#ifndef STRING_H
#define STRING_H

#include "WaterTest.h"
#include <string>
#include <vector>
using namespace std;

string classifyWater(double pH, int colorCode);
string getTip(double pH, int colorCode, const string &status);

#endif
