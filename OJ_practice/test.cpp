#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


//ʮ����ת�������
int main()
{
	int M, N;
	cin >> M >> N;
	string s = "ABCDEF"; //���ڴ���ʮ�������Ĵ洢
	if(N == 10 || M == 0) {
		cout << M << endl;
		return 0;
	}
	//�������
	if(M < 0) {
		M = - M;
		cout << "-";
	}
	string retStr;
	while(M) {
		int rem = M % N; //����
		if(rem >= 10) {
			retStr.push_back(s[rem - 10]);
		}
		else {
			retStr.push_back(rem + '0');
		}
		M /= N; //����M����������
	}
	//���Ӧ��ת
	reverse(retStr.begin(), retStr.end());
	cout << retStr << endl;

	return 0;
}

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
	int sub_len = 0; //Ŀ���Ӵ��ĳ���
	int sub_index = 0; //Ŀ���Ӵ�����ʼ�±�
	int tmp_len = 0; //��ʱ�Ӵ��ĳ���
	int tmp_index = 0; //��ʱ�Ӵ�����ʼ�±�
	for (int i = 0; i < n; i++) {
		while (i < n && (s[i] >= '0' && s[i] <= '9')) {
			tmp_len++;
			if (tmp_len == 1) {
				tmp_index = i;
			}
			i++;
		}
		if (sub_len < tmp_len) {
			// ������Ϣ
			sub_len = tmp_len;
			sub_index = tmp_index;
		}
		// ������ʱ�Ӵ��ĳ���
		tmp_len = 0;
	}
	//��ȡĿ���Ӵ�
	string sub_string = s.substr(sub_index, sub_len);
	cout << sub_string << endl;
	return 0;
}
#endif


#if 0 
//����������
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

	int start , end = 0; //��¼ÿ�����ʵ���ʼλ��
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
//ɾ��s1��������s2�г��ֵ��ַ�������ɾ������ַ���
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
//ţţ�����
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