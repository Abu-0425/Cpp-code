#include <iostream>
using namespace std;

#include <string>

#if 0
int main()
{
	int T;
	cin >> T;
	while (T--) {
		string s = "";
		cin >> s;
		int len = s.length();
		if (s.find('%') == string::npos || s.find('%') == len - 1) {
			cout << 3 * len + 1 << endl;
			continue;
		}
		int flag = 0;
		int cnt = 1;
		for (int i = 0; i < len; i++) {
			if (!flag && s[i] == '%') {
				flag = 1;
				cnt += 3;
			}
			else if (flag && s[i] == '%') {
				flag = 0;
				cnt += 9;
			}
			else if (flag && s[i] >= '0' && s[i] <= '9'){
				cnt += 8;
			}
			else if (flag) {
				switch (s[i]) {
				case 's':
					flag = 0;
					cnt += 3;
					break;
				case 'd':
					flag = 0;
					cnt += 4;
					break;
				case 'u':
					flag = 0;
					cnt += 5;
					break;
				case 'p':
					flag = 0;
					cnt += 6;
					break;
				case 'f':
					flag = 0;
					cnt += 7;
					break;
				default:
					flag = 0;
					cnt += 9;
					break;
				}
			}
			else {
				cnt += 3;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
#endif

int Solution(int m, int n, int x, int y, int p)
{
	int day = 0;
	int yo = 0, ko = 0;
	int po = 100000;
	for (int i = 0; i < m; i++) {
		po += x;
		yo += x;
		day++;
		if (po >= p) {
			return day;
		}
	}

	po -= n * y;
	ko += n * y;
	day += n;

	if (yo <= ko) {
		return -1;
	}
	int f = yo - ko;
	int px = p - po;
	if (yo < px) {
		int l = px / f;
		day += (l - 1) * (m + n);
	}
	for (int i = 0; i < m; i++) {
		po += x;
		day++;
		if (po >= p) {
			return day;
		}
	}
	return day;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int m, n, x, y, p;
		cin >> m >> n >> x >> y >> p;

		cout << Solution(m, n, x, y, p) << endl;

	}
	return 0;
}