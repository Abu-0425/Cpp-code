#include <iostream>
using namespace std;

class Date{
	friend ostream& operator<<(ostream &output, Date &d);//����������غ�������Ϊ��Ԫ����
public:
	Date(int y, int m, int d) : year(y), mouth(m), day(d)
	{} //���캯��
private:
	int year;
	int mouth;
	int day;
};

ostream& operator<<(ostream &output, Date &d)//ʵ��
{
	output << d.year << "-" << d.mouth << "-" << d.day << endl;
	return output;
}

int main()
{
	Date d(2020, 10, 24);
	cout << d;//���������˽���Ϊoperator<<(cout, d)

	system("pause");
	return 0;
}


#if 0
//��������Լ��ڼ���(0-366)����������ʱ��(������)
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
				n--;//�����2�»�Ҫ���һ�죬��ҲҪ��˿��ǰ�n����-1�Ŀ���
			}
			mouth++;
		}
		day = n;
		//�����������
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