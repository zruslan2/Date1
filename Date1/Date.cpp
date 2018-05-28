#include "Date.h"

Date::Date(int day, int month, int year)
{
	if (day>0 && day<32)
		this->day = day;
	else cout << "Вы не правильно указали день\n";
	if (month>0 && month<13)
		this->month = month;
	else cout << "Вы не правильно указали месяц\n";
	/*if (year<2019)*/
		this->year = year;
}

void Date::SetDate()
{
	cout << "Введите день: "; cin >> day;
	cout << "Введите номер месяца: "; cin >> month;
	cout << "Введите год: "; cin >> year;
}

void Date::printDate()
{
	cout <<"Дата: "<< this->day << ":" << this->month << ":" << this->year << endl;
}

bool Date::operator==(Date & d)
{
	if(this->day==d.day&&this->month==d.month&&this->year==d.year)
		return true;
	else
		return false;	
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
		this->month += d / 30;
		if (this->month > 12)
		{
			this->month = this->month % 12;
			this->year += 1;
		}
	}
	if (this->month - 1 == 2 && IsLeap(this->year))
		d = d % 29;
	else if (this->month - 1 == 2 && !(IsLeap(this->year)))
		d = d % 28;
	else if (this->month - 1 == 1 || this->month - 1 == 3 || this->month - 1 == 5 || this->month - 1 == 7 || this->month - 1 == 8 || this->month - 1 == 10 || this->month - 1 == 0)
		d = d % 31;
	else if (this->month - 1 == 4 || this->month - 1 == 6 || this->month - 1 == 9 || this->month - 1 == 11)
		d = d % 30;
	this->day += d;
	if (this->month == 2 && IsLeap(this->year))
	{
		if (this->day > 29)
		{
			this->day = this->day % 29;
			this->month += 1;
			if (this->month > 12)
			{
				this->month = this->month % 12;
				this->year += 1;
			}
		}			
	}
	else if (this->month == 2 && !(IsLeap(this->year)))
	{
		if (this->day > 28)
		{
			this->day = this->day % 28;
			this->month += 1;
			if (this->month > 12)
			{
				this->month = this->month % 12;
				this->year += 1;
			}
		}
	}
	else if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12)
	{
		if (this->day > 31)
		{
			this->day = this->day % 31;
			this->month += 1;
			if (this->month > 12)
			{
				this->month = this->month % 12;
				this->year += 1;
			}
		}
	}
	else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
	{
		if (this->day > 30)
		{
			this->day = this->day % 30;
			this->month += 1;
			if (this->month > 12)
			{
				this->month = this->month % 12;
				this->year += 1;
			}
		}
	}
}

void Date::operator-=(int day)
{
	int d;
	if (day > 365)
	{
		this->year += day / 365;
	}
	d = day % 365;
	if (d > 30)
	{
		this->month -= d / 30;
		if (this->month < 1)
		{
			this->month = 12+this->month;
			this->year -= 1;
		}
	}
	if (this->month == 2 && IsLeap(this->year))
		d = d % 29;
	else if (this->month  == 2 && !(IsLeap(this->year)))
		d = d % 28;
	else if (this->month == 1 || this->month == 3 || this->month  == 5 || this->month  == 7 || this->month == 8 || this->month == 10 || this->month == 0)
		d = d % 31;
	else if (this->month == 4 || this->month  == 6 || this->month  == 9 || this->month  == 11)
		d = d % 30;
	this->day -= d;
	if (this->month == 1|| this->month == 2 || this->month == 4 || this->month == 6 || this->month == 8 || this->month == 9 || this->month == 11)
	{
		if (this->day < 1)
		{
			this->day = 31+this->day;
			this->month -= 1;
			if (this->month < 1)
			{
				this->month = 12+this->month;
				this->year -= 1;
			}
		}
	}
	else if (this->month == 3 && !(IsLeap(this->year)))
	{
		if (this->day < 1)
		{
			this->day = 28 + this->day;
			this->month -= 1;
			if (this->month < 1)
			{
				this->month = 12 + this->month;
				this->year -= 1;
			}
		}
	}	
	else if (this->month == 3 && IsLeap(this->year))
	{
		if (this->day < 1)
		{
			this->day = 29 + this->day;
			this->month -= 1;
			if (this->month < 1)
			{
				this->month = 12 + this->month;
				this->year -= 1;
			}
		}
	}
	else if (this->month == 5 || this->month == 7 || this->month == 10 || this->month == 12)
	{
		if (this->day < 1)
		{
			this->day = 30 + this->day;
			this->month -= 1;
			if (this->month < 1)
			{
				this->month = 12 + this->month;
				this->year -= 1;
			}
		}
	}	
}

Date Date::operator+(Date & d)
{
	Date nd;
	nd.year = this->year + d.year;
	nd.month = this->month + d.month;
	if (nd.month > 12)
	{
		nd.month = nd.month % 12;
		nd.year += 1;
	}
	nd.day = this->day + d.day;
	if (nd.month == 2 && IsLeap(nd.year))
	{
		if (nd.day > 29)
		{
			nd.day = nd.day % 29;
			nd.month += 1;
			if (nd.month > 12)
			{
				nd.month = nd.month % 12;
				nd.year += 1;
			}
		}
	}
	else if (nd.month == 2 && !(IsLeap(nd.year)))
	{
		if (nd.day > 28)
		{
			nd.day = nd.day % 28;
			nd.month += 1;
			if (nd.month > 12)
			{
				nd.month = nd.month % 12;
				nd.year += 1;
			}
		}
	}
	else if (nd.month == 1 || nd.month == 3 || nd.month == 5 || nd.month == 7 || nd.month == 8 || nd.month == 10 || nd.month == 12 )
	{
		if (nd.day > 31)
		{
			nd.day = nd.day % 31;
			nd.month += 1;
			if (nd.month > 12)
			{
				nd.month = nd.month % 12;
				nd.year += 1;
			}
		}
	}
	else if (nd.month == 4 || nd.month == 6 || nd.month == 9 || nd.month == 11)
	{
		if (nd.day > 30)
		{
			nd.day = nd.day % 30;
			nd.month += 1;
			if (nd.month > 12)
			{
				nd.month = nd.month % 12;
				nd.year += 1;
			}
		}
	}
	return nd;
}

Date Date::operator-(Date & d)
{
	Date nd;
	nd.year = this->year - d.year;
	nd.month = this->month - d.month;
	if (nd.month < 1)
	{
		nd.month = 12 + nd.month;
		nd.year -= 1;
	}
	nd.day = this->day - d.day;
	if (nd.month == 1 || nd.month == 3 || nd.month == 5 || nd.month == 7 || nd.month == 8 || nd.month == 10 || nd.month == 12)
	{
		if (nd.day < 1)
		{
			nd.day = 31 + nd.day;
			nd.month -= 1;
			if (nd.month < 1)
			{
				nd.month = 12 + nd.month;
				nd.year -= 1;
			}
		}
	}
	else if (nd.month == 2 && !(IsLeap(nd.year)))
	{
		if (nd.day < 1)
		{
			nd.day = 28 + nd.day;
			nd.month -= 1;
			if (nd.month < 1)
			{
				nd.month = 12 + nd.month;
				nd.year -= 1;
			}
		}
	}
	else if (nd.month == 2 && IsLeap(nd.year))
	{
		if (nd.day < 1)
		{
			nd.day = 29 + nd.day;
			nd.month -= 1;
			if (nd.month < 1)
			{
				nd.month = 12 + nd.month;
				nd.year -= 1;
			}
		}
	}
	else if (nd.month == 4 || nd.month == 6 || nd.month == 9 || nd.month == 11)
	{
		if (nd.day < 1)
		{
			nd.day = 30 + nd.day;
			nd.month -= 1;
			if (nd.month < 1)
			{
				nd.month = 12 + nd.month;
				nd.year -= 1;
			}
		}
	}
	return nd;
}

void Date::CurTime(char *ct)
{
	int h, m, s;
	char tmp[4];
	ct[0] = '\0';
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	h = timeinfo->tm_hour;
	m = timeinfo->tm_min;
	s = timeinfo->tm_sec;
	itoa(h, tmp, 10);
	strcat(ct, tmp);
	strcat(ct, ":");
	tmp[0] = '\0';
	itoa(m, tmp, 10);
	strcat(ct, tmp);
	strcat(ct, ":");
	tmp[0] = '\0';
	itoa(s, tmp, 10);
	strcat(ct, tmp);
	strcat(ct, "\0");	
}

void Date::CurDate(char * ct)
{
	int y, m, d;
	char tmp[6];
	ct[0] = '\0';
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	y = 1900 + timeinfo->tm_year;
	m = timeinfo->tm_mon+1;
	d = timeinfo->tm_mday;
	itoa(d, tmp, 10);
	strcat(ct, tmp);
	strcat(ct, ":");
	tmp[0] = '\0';
	itoa(m, tmp, 10);
	strcat(ct, tmp);
	strcat(ct, ":");
	tmp[0] = '\0';
	itoa(y, tmp, 10);
	strcat(ct, tmp);
	strcat(ct, "\0");
}

bool IsLeap(int year)
{
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		return true;
	else
		return false;
}

Date::~Date()
{
}


