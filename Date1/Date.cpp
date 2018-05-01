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


