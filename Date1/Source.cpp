#include "Date.h"

void main()
{
	setlocale(LC_ALL, "");
	Date d;
	d.SetDate();
	Date d1;
	d1.SetDate();	
	if (d == d1)cout << "���� �����"<<endl;
	else cout << "���� �� �����" << endl;
	d.printDate();
	d += 40;
	d.printDate();
}