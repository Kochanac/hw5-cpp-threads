#ifndef __House__
#define __House__

struct House
{
	int place;
	int value;

	House(int place, int value);
	bool operator<(const House& other) const;
};

#endif