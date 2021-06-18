#pragma once
#include <iostream>
using namespace std;

class room {
protected:
	int price;
	bool reserved;
public:
	static int totalReserved;
	room();
	room(int price, bool reserved);
	void unreserve();
	virtual bool reserve() = 0;

	void setStatus(bool status);

	int getPrice();
	bool getStatus();
};