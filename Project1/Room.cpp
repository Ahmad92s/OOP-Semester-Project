#include "Room.h"

int room::totalReserved = 0;
room::room() {
	price = 0;
	reserved = false;
}
room::room(int price, bool reserved) {
	this->price = price;
	this->reserved = reserved;
}
void room::unreserve() {
	this->reserved = false;
}

void room::setStatus(bool status) {
	reserved = status;
}

int room::getPrice() {
	return price;
}
bool room::getStatus() {
	return reserved;
}