#include <iostream>
using namespace std;

bool IsLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	}
	return false;
}

int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int GetDayOfMouth(int year, int mouth)
{
	if (mouth == 2 && IsLeapYear(year)) {
		return 29;
	}
	return days[mouth];
}

bool IsValidDate(int year, int mouth, int day)
{
	if ((year > 0) && (mouth >= 1 && mouth <= 12) &&
		(day <= GetDayOfMouth(year, mouth))) {
		return true;
	}
	return false;
}

int main()
{
	int year, mouth, day;
	while (cin >> year >> mouth >> day) {
		if (!IsValidDate(year, mouth, day)) {
			return -1; //表示日期非法
		}
		int ret = 0;
		for (int i = 1; i < mouth; i++) {
			ret += days[i];
		}
		ret += day;
		if (IsLeapYear(year)) {
			ret += 1;
		}
		cout << ret << endl;
	}
	return 0;
}