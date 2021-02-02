#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//쳲�������β
int main()
{
	int n;
	vector<int> fib(100001);
	fib[0] = 1;
	fib[1] = 1;
	for (size_t i = 2; i < fib.size(); i++) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000;
	}
	while (cin >> n) {
		if (n < 30) {
			cout << fib[n] << endl;
		}
		else {
			printf("%06d\n", fib[n]);
		}
	}
	return 0;
}

#if 0
//�Ա�����
bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int days[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool isSu(int m)
{
	return (m == 2 || m == 3 || m == 5 || m == 7 || m == 11);
}

int main()
{
	int y1, m1, d1, y2, m2, d2;
	while(cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2) {
		int money = 0;
		if(y1 == y2 && m1 == m2) {
			money += (isSu(m1) ? 1 : 2) * (d2 - d1 + 1);
			d1 = d2;
		}
		if(d1 != 1 && (y1 != y2 || m1 != m2)) {
			money += (isSu(m1) ? 1 : 2) * days[isLeapYear(y1)][m1] - d1 + 1;
			m1++;
			d1 = days[isLeapYear(y1)][m1];
		}
		while(y1 != y2 || m1 != m2 || d1 != d2) {
			if(m1 == 13) {
				y1++;
				m1 = 1;
			}
			if(y1 != y2 || m1 != m2) {
				money += (isSu(m1) ? 1 : 2) * days[isLeapYear(y1)][m1];
				m1++;
			}
			if(y1 == y2 && m1 == m2) {
				money += (isSu(m1) ? 1 : 2) * d2;
				d1 = d2;
			}
		}
		cout << money << endl;
	}
	return 0;
}

//��������
int getDayOfWeek(int year, int mouth, int cnt, int _week, bool flag)
{
	if (mouth == 1 || mouth == 2) {
		mouth += 12;
		year--;
	}
	int day, week, i = 0;
	for (day = flag ? 1 : 31; day <= flag ? 31 : 1; flag ? (day++) : (day--)) {
		//flag������/����    
		week = (day + 2 * mouth + 3 * (mouth + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;//��ķ����ɭ��ʽ
		if (week + 1 == _week) {
			i++;
		}
		if (i == cnt) {
			break;
		}
	}
	return day;
}

int main()
{
	int year;
	while (cin >> year) {
		cout << year << "-01-01" << endl;
		printf("%d-01-%02d\n", year, getDayOfWeek(year, 1, 3, 1, 1));
		printf("%d-02-%02d\n", year, getDayOfWeek(year, 2, 3, 1, 1));
		printf("%d-05-%02d\n", year, getDayOfWeek(year, 5, 1, 1, 0));
		cout << year << "-07-04" << endl;
		printf("%d-09-%02d\n", year, getDayOfWeek(year, 9, 1, 1, 1));
		printf("%d-11-%02d\n", year, getDayOfWeek(year, 11, 4, 4, 1));
		cout << year << "-12-25" << endl << endl;
	}
	return 0;
}

//�ֽ�����
int main()
{
	int a;
	while (cin >> a) {
		cout << a << " = ";
		int i = 2;
		for (;; i++) {
			if (a % i == 0) {
				cout << i;
				a /= i;
				break;
			}
		}
		while (a >= 2) {
			for (i = 2;; i++) {
				if (a % i == 0) {
					cout << " * " << i;
					a /= i;
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}

//�����Ӹ���
int main()
{
	int n;
	while(cin >> n) {
		int cnt = 0;
		for(int i = 2; i <= sqrt(n); i++) {
			if(n % i == 0) {
				while(n % i == 0) {
					n /= i;
				}
				cnt++;
			}
		}
		if(n > 1) {
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}

//���ѵ�����
int main()
{
	string code;
	while (getline(cin, code)) {
		int len = code.length();
		for (int i = 0; i < len; i++) {
			if (code[i] == ' ') {
				continue;
			}
			if (code[i] > 'E') {
				code[i] -= 5;
			}
			else {
				code[i] = code[i] - 5 + ('Z' - 'A' + 1);
			}
		}
		cout << code << endl;
	}
	return 0;
}

//�мٱ�
int main()
{
	int n;
	while (cin >> n && n) {
		int count = 0;
		while (n > 1) {
			++count;
			if (n % 3) {
				n = n / 3 + 1;
			}
			else {
				n /= 3;
			}
		}
		cout << count << endl;
	}
	return 0;
}

//�������������С������ɺ�
class Solution {
public:
	/**
	*	���������е���С������ɺ�
	*	���룺��������arr
	*	���أ����������е���С������ɺ�
	*/
	int getFirstUnFormedNum(vector<int> arr, int len) {
		int _min = arr[0];
		int _max = 0;
		set<int> s;
		for (int i = 0; i < len; i++) {
			_max += arr[i];
			_min = min(_min, arr[i]);
			vector<int> tmp;
			for (auto it = s.begin(); it != s.end(); ++it) {
				tmp.push_back(*it + arr[i]);
			}
			for (size_t j = 0; j < tmp.size(); j++) {
				s.insert(tmp[j]);
			}
			s.insert(arr[i]);
		}
		for (int i = _min; i <= _max; i++) {
			if (s.find(i) == s.end()) {
				return i;
			}
		}
		return _max + 1;
	}
};

//��arr����������λ�϶�����������ż��λ�϶���ż��
class Solution {
public:
	/**
	*  ����λ�϶�����������ż��λ�϶���ż��
	*  ���룺����arr�����ȴ���2
	*  len��arr�ĳ���
	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
	*/
	bool isEvenNumber(int n)
	{
		return n % 2 == 0;
	}
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0;
		int j = 1;
		while (i < len && j < len) {
			if (isEvenNumber(arr[len - 1])) {
				swap(arr[i], arr[len - 1]);
				i += 2;
			}
			else {
				swap(arr[j], arr[len - 1]);
				j += 2;
			}
		}
	}
};

//���ӷ���
int main()
{
	int n;
	while (cin >> n && n) {
		long a = pow(5, n) - 4;
		long b = pow(4, n) + n - 4;
		cout << a << " " << b << endl;
	}
	return 0;
}

//���üӼ��˳����ӷ�
class Solution {
public:
	int Add(int num1, int num2)
	{
		if (0 == num1 || 0 == num2) {
			return 0 == num1 ? num2 : num1;
		}
		int add = 0, carry = 0;
		while (num2 != 0) {
			add = num1 ^ num2;
			carry = (num1 & num2) << 1;
			num1 = add;
			num2 = carry;
		}
		return num1;
	}
};

//������
bool IsTriangle(double a, double b, double c)
{
	if (a + b <= c || a + c <= b || b + c <= a) {
		return false;
	}
	return true;
}

//�쵽������
int main()
{
	double n, r;
	while (cin >> n >> r) {
		if (2 * 3.14 * r < n) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}
	}
	return 0;
}

//��̬������̨��
class Solution {
public:
	int power2(int k)
	{
		if(k == 0) {
			return 1;
		}
		else {
			return 2 * power2(k - 1);
		}
	}
	int jumpFloorII(int number) {
		return power2(number - 1);
	}
};

//�Ǽ�����
vector<int> a = { 1, 1 };

void fib_init()
{
	for (int i = 2; i < 10001; ++i)
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
}

int main()
{
	int n, i;
	fib_init();
	while (cin >> n)
	{
		while (n--)
		{
			cin >> i;
			printf("%04d", a[i]);
		}
		cout << endl;
	}
	return 0;
}

//����
int getShuGen(int n)
{
	int add = 0;
	if (n > 9) {
		while (n) {
			add += n % 10;
			n /= 10;
		}
		int res = 0;
		if (add > 9) {
			while (add) {
				res += add % 10;
				add /= 10;
			}
			return res;
		}
		else {
			return add;
		}
	}
	return n;
}

int main()
{
	int n;
	while(cin >> n) {
		cout << getShuGen(n) << endl;
	}
	return 0;
}

//�Թ�����
int row, col;
vector<vector<int>> maze;
vector<vector<int>> tmp; //��ǰ·��
vector<vector<int>> best; //���·��

void Track(int i, int j)
{
	maze[i][j] = 1; //��ʾ���߹�
	tmp.push_back({i, j});
	if(i == row - 1 && j == col - 1) {
		if(best.empty() || tmp.size() < best.size()) {
			best = tmp;
		}
	}
	if(i - 1 >= 0 && maze[i - 1][j] == 0) {
		Track(i - 1, j);
	}
	if(i + 1 < row && maze[i + 1][j] == 0) {
		Track(i + 1, j);
	}
	if(j - 1 >= 0 && maze[i][j - 1] == 0) {
		Track(i, j - 1);
	}
	if(j + 1 < col && maze[i][j + 1] == 0) {
		Track(i, j + 1);
	}
	maze[i][j] = 0; //����
	tmp.pop_back();
}

int main()
{
	while(cin >> row >> col) {
		tmp.clear();
		best.clear();
		maze = vector<vector<int>>(row, vector<int>(col, 0));
		for(auto &i : maze) {
			for(auto &j : i) {
				cin >> j;
			}
		}
		Track(0, 0);
		for(auto e : best) {
			cout << '(' << e[0] << ',' << e[1] << ')' << endl;
		}
	}
	return 0;
}

//С�׵�����֮·
int gcd(int n1, int n2)
{
	while(n1 % n2) {
		int tmp = n1 % n2;
		n1 = n2;
		n2 = tmp;
	}
	return n2;
}

int main()
{
	int n, a;
	while(cin >> n >> a) {
		vector<int> v(n);
		for(int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for(int i = 0; i < n; i++) {
			if(a >= v[i]) {
				a += v[i];
			}
			else {
				a += gcd(v[i], a);
			}
		}
		cout << a << endl;
	}
	return 0;
}

//�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
int main()
{
	string s;
	while(cin >> s) {
		int len = s.length();
		vector<int> v(256, 0);
		for(int i = 0; i < len; i++) {
			v[s[i]] += 1;
		}
		int i = 0;
		for(; i < len; i++) {
			if(v[s[i]] == 1) {
				cout << s[i] << endl;
				break;
			}
		}
		if(i == len) {
			cout << -1 << endl;
		}
	}
	return 0;
}

//ϴ��
vector<int> XiPai(vector <int> v, int n)
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i<n; i++)
		v1.push_back(v[i]);     //�����е���
	for (int i = n; i<2 * n; i++)
		v2.push_back(v[i]);      //�����е���
	for (int i = 0; i<n; i++)
	{
		v[i * 2] = v1[i];   //ϴһ���ƺ������Ƶ���λ��
		v[i * 2 + 1] = v2[i];    //ϴһ���ƺ������Ƶ���λ��
	}
	return v;
}

int main()
{
	int T, n, k;
	cin >> T;
	while (T--)    //T������
	{
		vector<int> v;    
		cin >> n >> k;
		for (int i = 0; i < 2 * n; i++)
		{
			int a = 0;
			cin >> a;
			v.push_back(a);    //������洢�ƺ�
		}
		while (k--)     //ϴk����
			v = XiPai(v, n);

		for (int i = 0; i < 2 * n - 1; i++) {
			cout << v[i] << " ";
		}
		cout << v[2 * n - 1] << endl;   //ÿ�����ݺ�Ҫ����
	}

	return 0;
}

//������Ӵ��ĳ���
int getCommonStrLength(const string &s1, const string &s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	vector<vector<int>> vv(len1, vector<int>(len2, 0));
	int resLength = 0;
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (s1[i] == s2[j]) {
				if (i == 0 || j == 0) {
					vv[i][j] = 1;
				}
				else {
					vv[i][j] = vv[i - 1][j - 1] + 1;
				}
			}
			if (vv[i][j] > resLength) {
				resLength = vv[i][j];
			}
		}
	}
	return resLength;
}


int main()
{
	string s1, s2;
	while (cin >> s1 >> s2) {
		cout << getCommonStrLength(s1, s2) << endl;
	}
	return 0;
}

//�ַ�����ת
string ReverseString(string &s)
{
	int len = s.length();
	int start = 0;
	int end = len - 1;
	while (start < end) {
		swap(s[start], s[end]);
		start++, end--;
	}
	return s;
}

int main()
{
	string s;
	while (cin >> s) {
		cout << ReverseString(s) << endl;
	}
	return 0;
}

//���������Ӵ��е�������Ӵ�
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2) {
		if (s1.length() > s2.length()) {
			swap(s1, s2);
		}
		int len1 = s1.length();
		int len2 = s2.length();
		vector<vector<int>> vv(len1, vector<int>(len2, 0));
		int len = 0, start_pos = 0;
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				if (s1[i] == s2[j]) {
					if (i == 0 || j == 0) {
						vv[i][j] = 1;
					}
					else {
						vv[i][j] = vv[i - 1][j - 1] + 1;
					}
				}
				if (vv[i][j] > len) {
					len = vv[i][j];
					start_pos = i - len + 1;
				}
			}
		}
		cout << s1.substr(start_pos, len) << endl;
	}
	return 0;
}

//����ˮ����
int drink(int n)
{
	int empty = n;
	int ret = 0;
	while (empty >= 3) {
		ret += empty / 3;
		empty = empty / 3 + empty % 3;
	}
	if (empty == 2) {
		ret += 1;
	}
	return ret;
}

int main()
{
	int n;
	while (cin >> n && n) {
		cout << drink(n) << endl;
	}
	return 0;
}

//������Ӵ�
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n));
		string ans;
		for (int l = 0; l < n; ++l) {
			for (int i = 0; i + l < n; ++i) {
				int j = i + l;
				if (l == 0) {
					dp[i][j] = 1;
				}
				else if (l == 1) {
					dp[i][j] = (s[i] == s[j]);
				}
				else {
					dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
				}
				if (dp[i][j] && l + 1 > ans.size()) {
					ans = s.substr(i, l + 1);
				}
			}
		}
		return ans;
	}
};

//��ʲ��������
int main()
{
	int n, m, Case;
	cin >> Case;
	while (Case--) {
		cin >> n >> m;
		cout << (n % (m + 1) ? "Win" : "Lose") << endl;
	}
	return 0;
}

//����֮��
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int size = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		for(int first = 0; first < size - 2; first++) {
			if(first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}
			int third = size - 1;
			int tatget = -nums[first];
			for(int second = first + 1; second < size - 1; second++) {
				if(second > first + 1 && nums[second] == nums[second - 1]) {
					continue;
				}
				while(second < third && nums[second] + nums[third] > tatget) {
					third--;
				}
				if(second == third) {
					break;
				}
				if (nums[second] + nums[third] == tatget) {
					res.push_back({ nums[first], nums[second], nums[third] });
				}
			}
		}
		return res;
	}
};

//������ת
class Solution {
public:
	int reverse(int x) {
		int res = 0;
		while (x) {
			int pop = x % 10;
			x /= 10;
			if (res > INT_MAX / 10) {
				return 0;
			}
			else if (res < INT_MIN / 10) {
				return 0;
			}
			res = res * 10 + pop;
		}
		return res;
	}
};
#endif