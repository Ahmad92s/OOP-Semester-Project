#include "roomTypes.h"

//constructors
standard::standard() {
	price = 300;
	reserved = false;
}
moderate::moderate() {
	price = 500;
	reserved = false;
}
superior::superior() {
	price = 1000;
	reserved = false;
}
juniorSuite::juniorSuite() {
	price = 2000;
	reserved = false;
}
suite::suite() {
	price = 5000;
	reserved = false;
}

//functions
bool standard::reserve() {
	if (!this->reserved) {
		reserved = true;
		totalReserved++;
		cout << "Standard room succesfully reserved\n";
		return true;//signalling that room allocation was a success
	}
	return false;//signalling that room isn't available
}
bool moderate::reserve() {
	if (!this->reserved) {
		reserved = true;
		totalReserved++;
		cout << "Moderate room succesfully reserved\n";
		return true;//signalling that room allocation was a success
	}
	return false;//signalling that room isn't available
}
bool superior::reserve() {
	if (!this->reserved) {
		reserved = true;
		totalReserved++;
		cout << "Superior room succesfully reserved\n";
		return true;//signalling that room allocation was a success
	}
	return false;//signalling that room isn't available
}
bool juniorSuite::reserve() {
	if (!this->reserved) {
		reserved = true;
		totalReserved++;
		cout << "Junior Suite succesfully reserved\n";
		return true;//signalling that room allocation was a success
	}
	return false;//signalling that room isn't available
}
bool suite::reserve() {
	if (!this->reserved) {
		reserved = true;
		totalReserved++;
		cout << "Suite succesfully reserved\n";
		return true;//signalling that room allocation was a success
	}
	return false;//signalling that room isn't available
}