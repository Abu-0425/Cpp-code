#include <iostream>
using namespace std;

class Date{
	friend ostream& operator<<(ostream &output, Date &d);//将运算符重载函数声明为友元函数
public:
	Date(int y, int m, int d) : year(y), mouth(m), day(d)
	{} //构造函数
private:
	int year;
	int mouth;
	int day;
};

ostream& operator<<(ostream &output, Date &d)//实现
{
	output << d.year << "-" << d.mouth << "-" << d.day << endl;
	return output;
}

int main()
{
	Date d(2020, 10, 24);
	cout << d;//编译器将此解释为operator<<(cout, d)

	system("pause");
	return 0;
}


#if 0
//输入年份以及第几天(0-366)，输出具体的时间(年月日)
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

int main()
{
	int year, n;
	int mouth = 1, day = 0;
	while (cin >> year >> n) {
		for (int i = 1; n >= days[i]; i++) {
			if (mouth == 12) {
				break;
			}
			n -= days[i];
			if (IsLeapYear(year) && mouth == 2) {
				n--;//闰年的2月还要多减一天，但也要因此考虑把n减成-1的可能
			}
			mouth++;
		}
		day = n;
		//俩种特殊情况
		if (day == 0) {
			mouth--;
			day = GetDayOfMouth(year, mouth);
		}
		else if (day == -1) {
			mouth--;
			day = GetDayOfMouth(year, mouth) - 1;
		}
		printf("%04d-%02d-%02d\n", year, mouth, day);
		mouth = 1, day = 0;
	}
	return 0;
}

#endif