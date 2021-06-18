#pragma once
#include <iostream>
#include <fstream>

#include "Room.h"
#include "Customer.h"
#include "roomTypes.h"
using namespace std;

class hotel {
private:
	room** roomList;
	customer* customerList;

public:
	hotel();
	~hotel();

	static int noOfcustomers;
	static int cinCount, coutCount;

	void addcustomer(const char* curtime, const char* curdate);
	void checkin(string id, char* datenow, char* timenow);
	void checkout(string id, char* datenow, char* timenow);
	void deallocateRooms(const char* curtime, const char* curdate);//deallocate rooms for whoever's time is up
	void showRoomData();
	void showReport();
	void save();
	void load();
};