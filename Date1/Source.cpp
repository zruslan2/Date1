#include "Date.h"

void main()
{
	setlocale(LC_ALL, "");
	char t[20];
	/*t[0] = '\0';*/
	Date::CurTime(t);
	cout <<"Текущее время - "<< t << endl;
	Date::CurDate(t);
	cout << "Текущfz дата - " << t << endl;
	Date d;
	d.SetDate();
	Date d1;
	d1.SetDate();	
	if (d == d1)cout << "Даты равны"<<endl;
	else cout << "Даты не равны" << endl;
	d.printDate();
	d += 40;
	d.printDate();
	d -= 40;
	d.printDate();
	d = d + d1;
	d.printDate();
	d = d - d1;
	d.printDate();
}