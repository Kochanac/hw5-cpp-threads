#ifndef __Settings__
#define __Settings__

#include <cassert>
#include <string>

const int HOUSE_MAX_PLACE = 300;
const int HOUSE_MAX_VALUE = 500;

const int MISSILE_PRICE = 3;

struct Settings {
	int first_country_missiles, second_country_missiles;
	int first_home_count, second_home_count;
	bool isOk = false;
	std::string warning_message;
};

Settings parseArgv(const char *argv[], int len);
#endif
