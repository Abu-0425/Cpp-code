#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Data{
public:
	Data() {}
	Data(int n) : data(n) {}
private:
	int data;
};

template<class T> 
class BigNumber{
	long n;
public:
	BigNumber(T i) :n(i){}
	BigNumber operator+(BigNumber b){
		return BigNumber(n + b.n);
	}
};

int main()
{
	BigNumber<long> d1(1), d2(2);
	d1 + d2;
	d1 + 3;
	3 + 3;
	//3 + d1;
	//Data d[3] = {1, 2, 3};
	//d[1] = 10;
	//int arr[][4] = { { 1 }, { 3, 2 }, { 4, 5, 6 }, { 0 } };
	//printf("%d\n", arr[1][2]);
	return 0;
}


//数组中相加和为0的三元组
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> v;
		int n = num.size();
		if(n < 3) {
			return v;
		}
		sort(num.begin(), num.end()); //排序
		for(int i = 0; i < n - 2; i++) {
			int front = i + 1;
			int back = n - 1;
			int add = -num[i]; //后俩者的目标和
			while(front < back) {
				if(num[front] + num[back] > add) {
					back--; //back需往前移动寻找
				} 
				else if(num[front] + num[back] < add) {
					front++; //front需往后移动查找
				}
				else {
					//找到一组符合要求的数据，保存
					vector<int> tmp = {num[i], num[front], num[back]};
					v.push_back(tmp);
					//去重
					while(front+1 < back && num[front] == num[front+1]) {
						front++;
					}
					while(back-1 > front && num[back] == num[back-1]) {
						back--;
					}
					front++, back--;
				}
			}
			//去重
			while(i + 1 < n - 2 && num[i] == num[i+1]) {
				i++;
			}
		}
		return v;
	}
};

#if 0
//不要2！
//分蛋糕问题
int main()
{
	//遍历，用0表示当前位置可以放蛋糕，-1表示不能
	vector<vector<int>> v;
	int w, h = 0;
	while (cin >> w >> h) {
		v.resize(h);
		for (int i = 0; i < h; i++) {
			v[i].resize(w, 0); //初始化为全0
		}
		int count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				//表示可以放蛋糕
				if (v[i][j] == 0) {
					count++;
					//将欧几里得距离为2的点设为-1，表示不能放蛋糕
					if (j - 2 >= 0) {
						v[i][j - 2] = -1;
					}
					if (j + 2 <= w - 1) {
						v[i][j + 2] = -1;
					}
					if (i - 2 >= 0) {
						v[i - 2][j] = -1;
					}
					if (i + 2 <= h - 1) {
						v[i + 2][j] = -1;
					}
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}
#endif

/*将字符串转成整形*/
class Solution1 {
public:
	int StrToInt(string str) {
		int n = str.size();
		int i = 0;
		if (str[i] == '+') {
			i++;
		}
		int flag = 1;
		if (str[i] == '-') {
			flag = -flag;
			i++;
		}
		int res = 0;
		while (i < n) {
			if (isdigit(str[i])) {
				res = res * 10 + flag * (str[i] - '0');
			}
			else {
				return 0;
			}
			i++;
		}
		return res;
	}
};



#if 0
//判断将回文串B插入至回文串A中仍然回文有几种办法
bool isHui(string &s)
{
	int n = s.size();
	int begin = 0, end = n - 1;
	while (begin < end) {
		if (s[begin] != s[end]) {
			return false;
		}
		begin++;
		end--;
	}
	return true;
}

int main()
{
	string A, B;
	cin >> A >> B;
	int n = A.size();
	int count = 0;
	string tmp(A);
	for (int i = 0; i < n; i++) {
		tmp.insert(i, B);
		if (isHui(tmp)) {
			count++;
		}
		tmp = A;
	}
	cout << count << endl;

	return 0;
}
#endif

#if 0
//十进制转任意进制
int main()
{

	int M, N;
	cin >> M >> N;
	string s = "ABCDEF"; //用于大于十进制数的存储
	if(N == 10 || M == 0) {
		cout << M << endl;
		return 0;
	}
	//负数情况
	if(M < 0) {
		M = - M;
		cout << "-";
	}
	string retStr;
	while(M) {
		int rem = M % N; //余数
		if(rem >= 10) {
			retStr.push_back(s[rem - 10]);
		}
		else {
			retStr.push_back(rem + '0');
		}
		M /= N; //更新M，继续求余
	}
	//结果应反转
	reverse(retStr.begin(), retStr.end());
	cout << retStr << endl;

	return 0;
}
#endif

#if 0
int main()
{
	int A, B, C = 0;
	int n1, n2, n3, n4 = 0;
	cin >> n1 >> n2 >> n3 >> n4;
	A = (n1 + n3) / 2;
	B = -(n1 - n3) / 2;
	C = -(n2 - n4) / 2;
	if ((n1 == A - B) && (n2 == B - C) && (n3 == A + B) && (n4 == B + C)) {
		cout << A << " " << B << " " << C << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
#endif

#if 0
int main()
{
	string s = "";
	getline(cin, s);
	int n = s.size();
	int sub_len = 0; //目标子串的长度
	int sub_index = 0; //目标子串的起始下标
	int tmp_len = 0; //临时子串的长度
	int tmp_index = 0; //临时子串的起始下标
	for (int i = 0; i < n; i++) {
		while (i < n && (s[i] >= '0' && s[i] <= '9')) {
			tmp_len++;
			if (tmp_len == 1) {
				tmp_index = i;
			}
			i++;
		}
		if (sub_len < tmp_len) {
			// 更新信息
			sub_len = tmp_len;
			sub_index = tmp_index;
		}
		// 更新临时子串的长度
		tmp_len = 0;
	}
	//截取目标子串
	string sub_string = s.substr(sub_index, sub_len);
	cout << sub_string << endl;
	return 0;
}
#endif


#if 0 
//排序子序列
int main()
{
	int n = 0;
	cin >> n;
	if (n <= 2) {
		cout << 1 << endl;
		return 0;
	}
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int count = 1;
	for (int i = 1; i < n - 1; i++) {
		if (v[i] == v[i + 1]) {
			continue;
		}
		if ((v[i] > v[i - 1] && v[i] > v[i + 1]) ||
			(v[i] < v[i - 1] && v[i] < v[i + 1])) {
			count++;
			if (i != n - 3) {
				i++;
			}
		}
	}
	cout << count << endl;

	return 0;
}
#endif


#if 0
//I like beijing.
//beijing. like I
int main()
{
	string s = "";
	getline(cin, s);
	int length = s.size();
	std::reverse(s.begin(), s.end());

	int start , end = 0; //记录每个单词的起始位置
	int i = 0;
	while (i < length) {
		start = i;
		while (i < length && s[i] != ' ') {
			i++;
		}
		end = i - 1;
		while (start < end) {
			swap(s[start], s[end]);
			start++;
			end--;
		}
		if (i < length && s[i] == ' ') {
			i++;
		}
	}
	cout << s << endl;

	return 0;
}
#endif

#if 0
//删除s1中所有在s2中出现的字符，返回删除后的字符串
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	string res;
	int length1 = s1.size();
	int length2 = s2.size();
	res.resize(length1 + 1, 0);
	int k = 0;
	for (int i = 0; i < length1; i++) {
		bool flag = false;
		for (int j = 0; j < length2; j++) {
			if (s1[i] == s2[j]) {
				flag = true;
			}
		}
		if (flag == false) {
			res[k] = s1[i];
			k++;
		}
	}
	res.resize(k);
	cout << res << endl;

	return 0;
}
#endif

#if 0
//牛牛编程赛
int main()
{
	int n = 0;
	cin >> n;
	long long max = 0;
	vector<int> v(3 * n);
	for (int a_i = 0; a_i < 3 * n; a_i++) {
		cin >> v[a_i];
	}
	std::sort(v.begin(), v.end());
	for (int i = n; i < 3 * n; i += 2) {
		max += v[i];
	}
	cout << max << endl;

	return 0;
}
#endif