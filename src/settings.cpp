#include "settings.h"

Settings parseArgv(const char *argv[], int len) {
	Settings parsed;
	if (len == 5) {
		parsed.isOk = true;
		parsed.first_country_missiles = atoi(argv[1]);
		parsed.first_home_count = atoi(argv[2]);
		parsed.second_country_missiles = atoi(argv[3]);
		parsed.second_home_count = atoi(argv[4]);
	} else {
		parsed.isOk = false;
		std::string argv0 = argv[0];
		parsed.warning_message = "Usage: " + argv0 + " <first country missile count> <first country home count> <second country missile count> <second country home count>\n";
	}
	return parsed;
}
