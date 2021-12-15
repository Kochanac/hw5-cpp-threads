#ifndef __Country__
#define __Country__

#include <set>
#include <string>

#include "house.h"
#include "settings.h"

class Country
{
public:
	Country(std::string countryName, int missiles);
	void addHouse(House newHouse);
	
	std::set<House> houses; // позиции, на которых стоят дома
	int missiles; // количество ракет
	int spentMissiles; // количество ракет
	std::string countryName;

	int wonValue;

	int attackCountry(Country *another);
	int getValue();
	void run(Country *another);
};

#endif