#include "Date.h"

void main()
{
	setlocale(LC_ALL, "");
	char t[20];
	/*t[0] = '\0';*/
	Date::CurTime(t);
	cout <<"������� ����� - "<< t << endl;
	Date::CurDate(t);
	cout << "�����fz ���� - " << t << endl;
	Date d;
	d.SetDate();
	Date d1;
	d1.SetDate();	
	if (d == d1)cout << "���� �����"<<endl;
	else cout << "���� �� �����" << endl;
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