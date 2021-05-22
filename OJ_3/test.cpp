#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

//整数的平方根
class Solution {
public:
	int mySqrt(int x) {
		int left = 0, right = x, ans = -1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if ((long long)mid * mid <= x) {
				ans = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return ans;
	}
};

//归并排序
void _MergeSort(int *arr, int left, int right, int *tmp)
{
	if (left >= right) {
		return;
	}
	int mid = (left + right) / 2;

	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);

	int begin1, end1, begin2, end2;
	begin1 = left, end1 = mid, begin2 = mid + 1, end2 = right;
	int i = 0;
	while (begin1 <= end1 && begin2 <= end2) {
		if (arr[begin1] <= arr[begin2]) {
			tmp[i++] = arr[begin1++];
		}
		else {
			tmp[i++] = arr[begin2++];
		}
	}
	while (begin1 <= end1) {
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end2) {
		tmp[i++] = arr[begin2++];
	}
	memcpy(arr + left, tmp, (right - left + 1) * sizeof(int));
}

void MergeSort(int *arr, int n)
{
	int *tmp = (int *)malloc(sizeof(int)* n);
	if (tmp == NULL) {
		return;
	}

	_MergeSort(arr, 0, n - 1, tmp);

	free(tmp);
	tmp = nullptr;
}

int main()
{
	int arr[] = {6, 3, 9, 5, 2, 4, 1, 8, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	MergeSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
}

#if 0
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
#endif