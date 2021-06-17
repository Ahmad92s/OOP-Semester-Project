#pragma once
#include "daysCounting.h"
#include <string>
#include <iostream>
using namespace std;

class customer
{
public:
    customer();

    void setBalance(int b);
    void setreservedDays(int days);
    void setFloorNo(int floor);
    void setRoomType(int type);
    void setRoomNo(int roomnum);
	void setTimeLeft(const char* currentdate);
    void setcinTime(const char* time);
    void setcinDate(const char* date);
    void setcoutTime(const char* time);
    void setcoutDate(const char* date);
	void setreservedTime(const char* time);
	void setreservedDate(const char* date);

    string getID();
    int getreservedDays();
    int getroomNo();
	string getFileData();

	bool Timeleft();
	friend istream& operator>>(istream& in, customer& obj);
private:
	string name;
	int age;
	char gender;
	string IDnumber;
	int balance;
	int reservedDays;
	int floorNo;
	int roomType;
	int roomNo;
	char reservedTime[6];
	char reservedDate[11];
	char cinTime[6];
	char cinDate[11];
	char coutTime[6];
	char coutDate[11];
	int TimeLeft;
};