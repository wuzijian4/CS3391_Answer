#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class personInfo
{
public:
	personInfo(string, int, int, int);
	int compare(personInfo that);
	string getName();
private:
	string name;
	int day;
	int month;
	int year;
};

personInfo::personInfo(string n, int d, int m, int y)
{
	name = n;
	day = d;
	month = m;
	year = y;
}

int personInfo::compare(personInfo that)
{
	if (this->year < that.year)
		return 1;  // this is older
	else if (this->year > that.year)
		return -1;	//this is younger
	else if (this->month < that.month)
		return 1;
	else if (this->month > that.month)
		return -1;
	else if (this->day < that.day)
		return 1;
	else if (this->day > that.day)
		return -1;

	return 0; // same birthday not supposed to happen
}

string personInfo::getName()
{
	return name;
}

int main() {
	string name;
	int day; int month; int year;
	int numOfCases;
	
	cin >> numOfCases;
	cin >> name >> day >> month >> year;
	numOfCases--;
	
	personInfo oldest(name, day, month, year);
	personInfo youngest(name, day, month, year);
	
	while (numOfCases>0)
	{
		cin >> name >> day >> month >> year;
		personInfo newOne(name, day, month, year);
		if (oldest.compare(newOne) < 0)
			oldest = newOne; // new one is older

		if (youngest.compare(newOne) > 0)
			youngest = newOne; // new one is younger
		numOfCases--;
	}

	cout << youngest.getName() << endl;
	cout << oldest.getName() << endl;;

	return 0; 
}
