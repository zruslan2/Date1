#pragma once
#include "Library.h"

class Date
{
private:
	int day;
	int month;
	int year;
	
public:
	Date() = default;
	Date(int day, int month, int year);

	void SetDate();
	void printDate();

	bool operator==(Date &d);
	void operator+=(int day);
	void operator-=(int day);
	Date operator+(Date &d);
	Date operator-(Date &d);

	static void CurTime(char *ct);
	static void CurDate(char *ct);

	virtual ~Date();
};

bool IsLeap(int year);