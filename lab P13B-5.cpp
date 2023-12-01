#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

//function prototypes
bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);


int main() {
	cout << "Enter a date or Q to quit: ";
	int year;
	int month;
	int day;
	cin >> month >> day >> year;
	if (month == 0) {
		return 0;
	}

	//array calender from P13B-4
	//							 Sa Fr Th We Tu Mo Su
	//returned by DoW function:  00 01 02 03 04 05 06 07 08 09 10 11 12
	//character positions:		 012345678901234567890123456789012345678
	/*
	const string CALENDAR[] =  {"                   1  2  3  4  5  6  7 ",
								" 2  3  4  5  6  7  8  9 10 11 12 13 14 ",
								" 9 10 11 12 13 14 15 16 17 18 19 20 21 ",
								"16 17 18 19 20 21 22 23 24 25 26 27 28 ",
								"23 24 25 26 27 28 29 30 31		        ",
								"30, 31						   		    "};
	*/


	int days = daysInMonth(month, year);

	if (isLeapYear(year) == true) {
		if (month == 2) {
			days += 1;
		}
	}

	const string MONTHS[] = { "blank", "January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	string month_word = MONTHS[month];

	const string WKDAY[] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

	cout << WKDAY[dayOfWeek(month, day, year)] << ", " << month_word << " " << day << ", " << year;



}

//funcitons

int dayOfWeek(int month, int day, int year) {
	int weekDay;
	const int MODMONTH[] = { 0, 13, 14, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int mod_year;
	if (month > 2 && month < 13) {
		mod_year = year;
	}
	else if (month < 3) {
		mod_year = year - 1;
	}
	//Zeller Congruence
	int zeller1 = (((MODMONTH[month] + 1) * 26) / 10);
	int formula = (day + zeller1 + mod_year + (mod_year / 4) + 6 * (mod_year / 100) + (mod_year / 400));

	//using the mod 7 to get day
	int mod_seven = formula % 7;
	return mod_seven;
}

int daysInMonth(int month, int year) {
	const int MONTHDAYS[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int month_fix = month - 1;
	int days = MONTHDAYS[month_fix];
	//if (isLeapYear(month) == true) {
	//	days = days + 1;
	//	return days;
	//}
	//else { return days; }
	return days;
}

//isLeapYear - determines whether a given year is a leap year
bool isLeapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			}
			else { return false; }
		}
		else { return true; }
	}
	else { return false; }
}
