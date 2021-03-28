#include <iostream>
#include <algorithm>
using namespace std;

void ShellSort(int *arr, int n)
{
	int dk = n;
	while (dk > 1) {
		dk = dk / 3 + 1;
		for (int i = dk; i < n; i++) {
			if (arr[i] < arr[i - dk]) {
				int tmp = arr[i];
				int end = i - dk;
				while (end >= 0 && tmp < arr[end]) {
					arr[end + dk] = arr[end];
					end -= dk;
				}
				arr[end + dk] = tmp;
			}
		}
	}
}

int partition_1(int *arr, int left, int right)
{
	int key = arr[left];
	while (left < right) {
		while (left < right && arr[right] >= key) {
			right--;
		}
		arr[left] = arr[right];
		while (left < right && arr[left] < key) {
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = key;
	return left;
}

int partition_2(int *arr, int left, int right)
{
	int key = arr[left];
	int front = left;
	for (int back = front + 1; back <= right; back++) {
		if (arr[back] < key) {
			if (front++ != back) {
				int tmp = arr[front];
				arr[front] = arr[back];
				arr[back] = tmp;
			}
		}
	}
	int tmp = arr[left];
	arr[left] = arr[front];
	arr[front] = tmp;
	return front;
}


void QuickSort(int *arr, int left, int right)
{
	if (left >= right - 1) {
		return;
	}
	int pos = partition_2(arr, left, right - 1);
	QuickSort(arr, left, pos);
	QuickSort(arr, pos + 1, right);
}

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
	memcpy(arr + left, tmp, sizeof(int)* (right - left + 1));
}

void MergeSort(int *arr, int left, int right)
{
	int *tmp = new int[right];
	_MergeSort(arr, left, right - 1, tmp);
	delete[]tmp;
	tmp = nullptr;
}

int main()
{
	int arr[] = { 6, 5, 8, 2, 3, 9, 1, 7, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//ShellSort(arr, n);
	//QuickSort(arr, 0, n);
	MergeSort(arr, 0, n);
	for (int n : arr) {
		cout << n << " ";
	}
	cout << endl;
	return 0;
}


#if 0
bool isSame(int num)
{
	if (num < 11) {
		return false;
	}
	int m = 0, n = 0;
	int tmp = num;
	while (tmp) {
		m += tmp % 10;
		tmp /= 10;
		if (tmp) {
			n += tmp % 10;
			tmp /= 10;
		}
	}
	return m == n;
}

int main()
{
	int left, right;
	while (cin >> left >> right) {
		int count = 0;
		for (int i = left; i <= right; i++) {
			if (isSame(i)) {
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> time(n, 0);
		vector<int> point(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> time[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> point[i];
		}
		int ans = 0;
		map<int, int> kv;
		for (int i = 0; i < n; i++) {
			if (!kv.count(time[i])) {
				kv[time[i]] = point[i];
				ans += point[i];
			}
			else {
				if (point[i] > kv[time[i]]) {
					ans -= 2 * kv[time[i]];
					ans += point[i];
					kv.erase(time[i]);
					kv[time[i]] = point[i];
				}
				else {
					ans -= point[i];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
#endif