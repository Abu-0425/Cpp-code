#include <iostream>
#include <vector>
#include <string>
using namespace std;

//字符串通配问题
bool canMatch(const char *wcc, const char *dst)
{
	if (*wcc == '\0' && *dst == '\0') {
		return true;
	}
	if (*wcc == '\0' || *dst == '\0') {
		return false;
	}
	if (*wcc == '?') {
		return canMatch(wcc + 1, dst + 1);
	}
	else if (*wcc == '*') {
		return canMatch(wcc + 1, dst) || canMatch(wcc + 1, dst + 1) || canMatch(wcc, dst + 1);
	}
	else if (*wcc == *dst) {
		return canMatch(wcc + 1, dst + 1);
	}
	else {
		return false;
	}
}

int main()
{
	string wcc, dst;
	while (cin >> wcc >> dst) {
		if (canMatch(wcc.c_str(), dst.c_str())) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
	return 0;
}

//统计每个月兔子的数量(斐波那契数列)
int main()
{
	int m;
	while (cin >> m) {
		vector<int> fib(m);
		fib[0] = 1, fib[1] = 1;
		for (int i = 2; i < m; i++) {
			fib[i] = fib[i - 1] + fib[i - 2];
		}
		cout << fib[m - 1] << endl;
	}
	return 0;
}