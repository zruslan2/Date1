#pragma once
#include "Library.h"

class Date
{
private:
	int day;
	int mounth;
	int year;
	
public:
	Date() = default;
	Date(int day, int mounth, int year);

	bool operator==(Date &d);

	void operator+=(int day);

	virtual ~Date();
};

