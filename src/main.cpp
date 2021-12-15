#include <iostream>
#include <thread>

#include "country.h"
#include "settings.h"
#include "generator.h"

int main(int argc, char const *argv[])
{
	srand(time(0));
	Settings settings = parseArgv(argv, argc);

	if (!settings.isOk) {
		std::cout << settings.warning_message;
		return 0;
	}

	Country* first = generateCountry(settings.first_country_missiles, settings.first_home_count);
	Country* second = generateCountry(settings.second_country_missiles, settings.second_home_count);

	std::cout << first->countryName << " vs " << second->countryName << "\n";

	std::thread thread_country_1(&Country::run, first, second);
	std::thread thread_country_2(&Country::run, second, first);
	
	thread_country_1.join();
	thread_country_2.join();

	return 0;
}
