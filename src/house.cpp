#include <cassert>
#include "house.h"
#include "settings.h"

House::House(int place, int value) {
	assert((place < HOUSE_MAX_PLACE));
	this->place = place;
	this->value = value;
}

bool House::operator<(const House& other) const 
{
	return place < other.place;
}