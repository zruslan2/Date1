#include "Date.h"

Date::Date(int day, int mounth, int year)
{
	if (day>0 && day<32)
		this->day = day;
	else cout << "Вы не правильно указали день\n";
	if (mounth>0 && mounth<13)
		this->mounth = mounth;
	else cout << "Вы не правильно указали месяц\n";
	if (year<2019)
		this->year = year;
}

bool Date::operator==(Date & d)
{
	if(this->day==d.day&&this->mounth==d.mounth&&this->year==d.year)
		return true;
}

void Date::operator+=(int day)
{
	int d;
	if (day > 365)
	{
		this->year += day / 365;
	}
	d = day % 365;
	if (d > 30)
	{
		this->mounth += d / 30;
		if (this->mounth > 12)
			this->mounth = this->mounth % 12;
	}
	d = d % 12;
	this->day += d;
	
}


Date::~Date()
{
}


