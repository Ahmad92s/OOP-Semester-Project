#pragma once
#include "Room.h"
#include <iostream>
using namespace std;

class standard :public room {
public:
	standard();
	bool reserve();
};
class moderate :public room {
public:
	moderate();
	bool reserve();
};
class superior :public room {
public:
	superior();
	bool reserve();
};
class juniorSuite :public room {
public:
	juniorSuite();
	bool reserve();
};
class suite :public room {
public:
	suite();
	bool reserve();
};