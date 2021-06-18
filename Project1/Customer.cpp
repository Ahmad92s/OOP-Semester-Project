#pragma warning( disable : 4996)
#include "Customer.h"

customer::customer() {
	name = "mr. x";
	strcpy(reservedTime, "xx.xx");
	strcpy(reservedDate, "xx.xx.xxxx");
	age = 0;
	gender = 'X';
	IDnumber = "0900-78601";
	balance = 0;
	reservedDays = 0;
	floorNo = 0;
	roomType = 0;
	roomNo = -1;
	strcpy(cinTime, "xx.xx");
	strcpy(cinDate, "xx.xx.xxxx");
	strcpy(coutTime, "xx.xx");
	strcpy(coutDate, "xx.xx.xxxx");
	TimeLeft = 0;
}
istream& operator>>(istream& in, customer& obj)
{
	cout << "Enter Name : ";
	in.ignore();
	getline(in, obj.name, '\n');
	cout << "Enter Age : ";
	in >> obj.age;
	cout << "Enter Gender : ";
	in >> obj.gender;
	cout << "Enter ID Number : ";
	in >> obj.IDnumber;
	/*balance = 0;
	reservedDays = 0;
	floorNo = 0;
	roomType = 0;
	roomNo = 0;*/
	return in;
}

void customer::setName(string n) {
	name = n;
}
void customer::setAge(int a) {
	age = a;
}
void customer::setGender(char g) {
	gender = g;
}
void customer::setID(string ID) {
	IDnumber = ID;
}
void customer::setTimeLeft(const char* currentdate, const char* currenttime) {
	int cday = 0, cmonth = 0, cyear = 0;
	int rday = 0, rmonth = 0, ryear = 0;
	int l = 0;
	for (l = 0; currentdate[l] != '/'; l++) {
		cday = cday * 10 + (currentdate[l] - 48);

	}
	l++;
	for (; currentdate[l] != '/'; l++) {
		cmonth = cmonth * 10 + (currentdate[l] - 48);
	}
	l++;
	for (; currentdate[l] != '\0'; l++) {
		cyear = cyear * 10 + (currentdate[l] - 48);
	}
	l = 0;
	for (l = 0; reservedDate[l] != '/'; l++) {
		rday = rday * 10 + (reservedDate[l] - 48);

	}
	l++;
	for (; reservedDate[l] != '/'; l++) {
		rmonth = rmonth * 10 + (reservedDate[l] - 48);
	}
	l++;
	for (; reservedDate[l] != '\0'; l++) {
		ryear = ryear * 10 + (reservedDate[l] - 48);
	}
	// Code from geeks from geeks
	Date d1 = { cday,cmonth,cyear };
	Date d2 = { rday,rmonth,ryear };

	TimeLeft = getDifference(d2, d1);

	TimeLeft *= 24;

	int ch = 0, cm = 0, rh = 0, rm = 0;

	rh = (reservedTime[0] - '0') * 10;
	rh += reservedTime[1] - '0';
	ch = (currenttime[0] - '0') * 10;
	ch += currenttime[1] - '0';
	rm = (reservedTime[3] - '0') * 10;
	rm += reservedTime[4] - '0';
	cm = (currenttime[3] - '0') * 10;
	cm += currenttime[4] - '0';

	double diff = (rh/1.0 - ch/1.0);
	diff += (rm / 60.0 - cm / 60.0);

	TimeLeft += diff;
}
bool customer::Timeleft() {
	if (TimeLeft <= 0) {
		return false;
	}
	return true;
}

//setters
void customer::setBalance(int b) {
	balance = b;
}
void customer::setreservedDays(int days) {
	reservedDays = days;
}
void customer::setFloorNo(int floor) {
	floorNo = floor;
}
void customer::setRoomType(int type) {
	roomType = type;
}
void customer::setRoomNo(int roomnum) {
	roomNo = roomnum;
}
void customer::setcinTime(const char* time) {
	strcpy(cinTime, time);
}
void customer::setcinDate(const char* date) {
	strcpy(cinDate, date);
}
void customer::setcoutTime(const char* time) {
	strcpy(coutTime, time);
}
void customer::setcoutDate(const char* date) {
	strcpy(coutDate, date);
}
//getters
int customer::getreservedDays() {
	return reservedDays;
}
string customer::getID() {
	return IDnumber;
}
int customer::getroomNo() {
	return roomNo;
}
string customer::getName() {
	return name;
}

void customer::setreservedTime(const char* time) {
	strcpy(reservedTime, time);
}
void customer::setreservedDate(const char* date) {
	strcpy(reservedDate, date);
}

string customer::getFileData() {
	string x;
	x = to_string(age) + " " + gender + " " + IDnumber + " " + to_string(balance) + " " + to_string(reservedDays);
	x += " " + to_string(floorNo) + " " + to_string(roomType) + " " + to_string(roomNo) + " " + reservedTime + " " + reservedDate + " " + cinTime + " " + cinDate + " " + coutTime + " " + coutDate + " " + to_string(TimeLeft) + " " + name;

	return x;
}
void customer::loadCustomer(ifstream& fin) {
	fin >> age >> gender >> IDnumber >> balance >> reservedDays >> floorNo >> roomType >> roomNo >> reservedTime >> reservedDate >> cinTime >> cinDate >> coutTime >> coutDate;
	fin >> TimeLeft;
	fin >> name;
	string surname;
	fin >> surname;
	name += (" " + surname);
}