#include <random>
#include <iostream>
#include "generator.h"

std::string generateString() {
	std::string names[] {
		"Анчуария", "Тарантерия", "Россия", "Австралия", "США"
	};

	return names[rand() % 5];
}

House generateHouse() {
	House house = House(
		rand() % HOUSE_MAX_PLACE,
		rand() % HOUSE_MAX_VALUE
	);
	return house;
}

Country* generateCountry(int numMissiles, int numHouses) {
	Country* country = new Country(generateString(), numMissiles);

	for (int i = 0; i < numHouses; ++i)
	{
		country->addHouse(generateHouse());
	}
	return country;
}