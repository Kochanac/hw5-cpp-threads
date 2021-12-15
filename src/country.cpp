#include <random>
#include <iostream>
#include <unistd.h>

#include "country.h"

Country::Country(std::string countryName, int missiles) {
	houses = std::set<House>();
	this->missiles = missiles;
	this->countryName = countryName;
}

void Country::addHouse(House newHouse) {
	this->houses.insert(newHouse);
}

int Country::attackCountry(Country *another) {
	--this->missiles;
	++this->spentMissiles;

	int missileLanded = rand() % HOUSE_MAX_PLACE;

	int resultValue = 0;
	for (House house : another->houses) {
		if (missileLanded == house.place) {
			resultValue = house.value;
			another->houses.erase(house);
			break;
		}
	}
	if (resultValue > 0)
		std::cout << "Country " << this->countryName << " hit! Value of the lost house: " << resultValue << "\n";

	return resultValue;
}

int Country::getValue() {
	int valueSum = 0;
	for (House house : this->houses) {
		valueSum += house.value;
	}
	return valueSum;
}

void Country::run(Country *another) {
	while (this->missiles > 0 
		&& spentMissiles * MISSILE_PRICE < another->getValue()) {
		// std::cout << "Country " << this->countryName << " shoots\n";
		// std::cout << "value of Country " << this->countryName << ": " << this->getValue() << "\n";
		this->wonValue += this->attackCountry(another);
	}
}
