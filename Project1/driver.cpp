#pragma warning( disable : 4996)
#include <iostream>
#include <fstream>

#include "Hotel.h"
#include "Customer.h"

using namespace std;

int main() {
	char datenow[11], timenow[6];
	cout << "Initializing program.\nEnter today's date (dd.mm.yyyy): ";
	cin.ignore(0);
	cin.getline(datenow, 11);
	cout << "Enter current time in 24h format (hh.mm): ";
	cin.ignore(0);
	cin.getline(timenow, 6);
	system("CLS");

	//formatting date if entered incorrectly
	datenow[2] = '/';
	datenow[5] = '/';

	hotel hotel;
	hotel.load();
	hotel.deallocateRooms(timenow, datenow);

	cout << "\tDate: " << datenow << ", Time: " << timenow << endl << endl;
	cout << "[ Hotel Grand Mangement Legendary Software - Menu ]\n";
	cout << "\t1: Reserve a room\n\t2: Check In\n\t3: Check Out\n\t4: View Reserved Rooms\n\t";
	cout << "5: See Detail Report\n\t6: Fast Forward Time\n\t7: Exit\nEnter choice: ";
	int choice = 0;
	cin >> choice;

	while (true) {
		if (choice == 1) {
			hotel.addcustomer(timenow, datenow);
		}
		else if (choice == 2) {
			cout << "Enter your ID: ";
			string id;
			cin >> id;
			hotel.checkin(id, datenow, timenow);
		}
		else if (choice == 3) {
			cout << "Enter your ID: ";
			string id;
			cin >> id;
			hotel.checkout(id, datenow, timenow);
		}
		else if (choice == 4) {
			hotel.showRoomData();
		}
		else if (choice == 5) {
			hotel.showReport();
		}
		else if (choice == 6) {
			cout << "Date to jump into: ";
			cin.ignore();
			cin.getline(datenow, 11);
			cout << "Time to jump into: ";
			cin.ignore(0);
			cin.getline(timenow, 6);

			hotel.deallocateRooms(timenow, datenow);
		}
		else if (choice == 7) {
			hotel.save();
			break;
		}
		cout << "\nEnter choice: ";
		cin >> choice;
	}

	return 0;
}