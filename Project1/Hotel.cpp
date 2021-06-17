#include "Hotel.h"
#include <fstream>

int hotel::noOfcustomers = 0;
int hotel::cinCount = 0;
int hotel::coutCount = 0;
hotel::hotel() {
	roomList = new room * [250];
	int s = 0, e = 50;
	for (int k = 0; k < 5; k++, s+=50, e+=50)
	{
		for (int i = s; i < e; i++)
		{
			if (k == 0) {
				roomList[i] = new standard;
			}
			else if (k == 1) {
				roomList[i] = new moderate;
			}
			else if (k == 2) {
				roomList[i] = new superior;
			}
			else if (k == 3) {
				roomList[i] = new juniorSuite;
			}
			else if (k == 4) {
				roomList[i] = new suite;
			}
		}
	}
	customerList = new customer;

}
hotel::~hotel() {
	for (int i = 0; i < 250; i++)
	{
		delete[] roomList[i];
	}
	delete[] roomList;
	delete[] customerList;
}

void hotel::addcustomer(const char* curtime, const char* curdate) {
	customer* tempList;
	noOfcustomers++;
	tempList = new customer[noOfcustomers];
	for (int i = 0; i < noOfcustomers - 1; i++)
	{
		tempList[i] = customerList[i];
	}
	customerList = tempList;
	/*delete[] tempList;*/

	char c;
	cout << "Are you a new or old customer? Enter ('N'/'O'): ";
	cin >> c;

	bool found = false;
	int customer_index = noOfcustomers - 1;
	if (c == 'N' || c == 'n') {
		cin >> customerList[noOfcustomers - 1];
	}
	else if (c == 'O' || c == 'o') {
		cout << "Enter your ID number: ";
		string id;
		cin >> id;
		for (int i = 0; i < noOfcustomers; i++)
		{
			if (customerList[i].getID() == id) {
				found = true;
				customer_index = i;
				break;
			}
		}
		if (!found) {
			cout << "Customer not found.\n";
			return;
		}
	}
	cout << "Which type of hotel do you want to reserve [1,2,3,4,5]: ";
	int type = 0;
	cin >> type;
	customerList[noOfcustomers - 1].setRoomType(type);
	for (int i = (type * 50 - 50); i < (type * 50); i++)
	{
		if (roomList[i][0].reserve()) {
			cout << "Your Room number is: #" << i << endl;
			customerList[customer_index].setRoomNo(i);
			customerList[customer_index].setFloorNo((i - (type * 50)) / 10 + 1);
			cout << "Number of days to reserve for: ";
			int days;
			cin >> days;
			customerList[customer_index].setreservedDays(days);
			cout << "Do you want to pay now? (Y/N): ";
			char c;
			cin >> c;
			if (c == 'Y' || c == 'y') {
				cout << roomList[i][0].getPrice() * customerList[customer_index].getreservedDays() << " paid succesfully.\n";
			}
			else if (c == 'N' || c == 'n') {
				cout << roomList[i][0].getPrice() * customerList[customer_index].getreservedDays() << " to be paid later.\n";
				customerList[customer_index].setBalance(roomList[i][0].getPrice() * customerList[customer_index].getreservedDays());
			}
			customerList[customer_index].setreservedTime(curtime);
			customerList[customer_index].setreservedDate(curdate);
			break;
		}
	}
}
void hotel::checkin(string id, char* datenow, char* timenow) {
	for (int i = 0; i < noOfcustomers; i++)
	{
		if (customerList[i].getID() == id) {

			customerList[i].setcinTime(timenow);
			customerList[i].setcinDate(datenow);
			cinCount++;
		}
	}
}
void hotel::checkout(string id, char* datenow, char* timenow) {
	for (int i = 0; i < noOfcustomers; i++)
	{
		if (customerList[i].getID() == id) {

			customerList[i].setcoutTime(timenow);
			customerList[i].setcoutDate(datenow);

			roomList[customerList[i].getroomNo()][0].unreserve();

			coutCount++;
		}
	}
}
void hotel::showRoomData() {
	int type = 1;

	cout << "Reserved Rooms List: \n";
	for (int n = 0; n < 5; n++)
	{
		int reservedcount = 0, freecount = 50;
		if (type == 1) {
			cout << "Standard: \n";
		}
		else if (type == 2) {
			cout << "Moderate: \n";
		}
		else if (type == 3) {
			cout << "Superior: \n";
		}
		else if (type == 4) {
			cout << "Junior Suite: \n";
		}
		else if (type == 5) {
			cout << "Suite: \n";
		}
		for (int i = (type * 50 - 50); i < (type * 50); i++) {
			if (roomList[i][0].getStatus()) {
				cout << "\t#" << i << endl;
			}
		}
		type++;
	}
}
void hotel::showReport() {
	//no of check ins
	cout << "Total Customers who checked in today: " << cinCount;
	//no of check outs
	cout << "\nTotal Customers who checked out today: " << coutCount << endl;
	//show count of reserved/free
	int type = 1;

	for (int n = 0; n < 5; n++)
	{
		int reservedcount = 0, freecount = 50;
		for (int i = (type * 50 - 50); i < (type * 50); i++) {
			if (roomList[i][0].getStatus()) {
				reservedcount++;
				freecount--;
			}
		}
		if (type == 1) {
			cout << "Standard: \t";
		}
		else if (type == 2) {
			cout << "Moderate: \t";
		}
		else if (type == 3) {
			cout << "Superior: \t";
		}
		else if (type == 4) {
			cout << "Junior Suite: \t";
		}
		else if (type == 5) {
			cout << "Suite: \t\t";
		}
		cout << "[reverved: " << reservedcount << ", free: " << freecount << "]\n";
		type++;
	}
}

void hotel::save() {
	ofstream fout;
	remove("Customers.dat");
	remove("Rooms.dat");

	fout.open("Customers.dat");
	fout.open("Rooms.dat");
	fout << noOfcustomers << endl;
	for (int i = 0; i < noOfcustomers; i++)
	{
		string x;
		x = customerList[i].getFileData();
	}
}
void hotel::load() {

}