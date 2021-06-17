#pragma warning( disable : 4996)
#include "Customer.h"

customer::customer() {
	name = "";
	strcpy(reservedTime, "");
	strcpy(reservedDate, "");
	age = 0;
	gender = 'X';
	IDnumber = "0900-78601";
	balance = 0;
	reservedDays = 0;
	floorNo = 0;
	roomType = 0;
	roomNo = 0;
	strcpy(cinTime, "");
	strcpy(cinDate, "");
	strcpy(coutTime, "");
	strcpy(coutDate, "");
	TimeLeft = 0;
}
istream& operator>>(istream& in, customer& obj)
{
	cout << "Enter Name : ";
	in >> obj.name;
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
void customer::setTimeLeft(const char* currentdate) {
	cout << "reserved date : ";
	cin >> reservedDate;
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
	cout << "timeleft : " << TimeLeft << endl;
	// ........
}
bool customer::Timeleft() {
	if (reservedDays <= TimeLeft) {
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
void customer::setreservedTime(const char* time) {
	strcpy(reservedTime, time);
}
void customer::setreservedDate(const char* date) {
	strcpy(reservedDate, date);
}

string customer::getFileData() {
	string x;
	x = name + " " + to_string(age) + " " + gender + " " + IDnumber + " " + to_string(balance);

	return x;
}