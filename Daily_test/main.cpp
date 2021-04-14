#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class B {
public: 
	virtual void Test() = 0;
};

class D : public B{
public:
	virtual void Test() {
		cout << "OK!!" << endl;
	}
};

int main()
{
	B *d = new D;
	d->Test();
	return 0;
}

#if 0
int getTwoN(int n)
{
	if (n == 0) {
		return 1;
	}
	return 2 * getTwoN(n - 1);
}

void ReverseCup(vector<int> &cup, int left, int right)
{
	while (left < right) {
		swap(cup[left], cup[right]);
		left++;
		right--;
	}
}

int getNCnt(vector<int> &cup)
{
	int cnt = 0;
	for (size_t i = 0; i < cup.size(); i++) {
		for (size_t j = i + 1; j < cup.size(); j++) {
			if (cup[i] > cup[j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	int n, m;
	while (cin >> n >> m) {
		vector<int> t(m);
		for (int &num : t) {
			cin >> num;
		}
		int cup_cnt = getTwoN(n);
		vector<int> cup(cup_cnt);
		for (int i = 0; i < cup_cnt; i++) {
			cup[i] = i + 1;
		}
		for (int i = 0; i < m; i++) {
			int f_cup_cnt = getTwoN(t[i]);
			int f_cnt = getTwoN(n - t[i]);
			int index = 0;
			for (int j = 0; j < f_cnt; j++) {
				ReverseCup(cup, index, index + f_cup_cnt - 1);
				index += f_cup_cnt;
			}
			cout << getNCnt(cup) << endl;
		}
	}
	return 0;
}

//特殊的下标集合
int main()
{
	string s;
	while (cin >> s) {
		int len = s.size();
		int cnt = 0;
		unordered_set<char> word;
		for (int i = 0; i < len; i++) {
			if (islower(s[i])) {
				word.insert(s[i]);
			}
		}
		cout << word.size() << endl;
	}
	return 0;
}


struct ListNode {
	ListNode(char v = '\0')
	: next(nullptr)
	, val(v)
	{}
	ListNode *next;
	char val;
};

ListNode* CreateList(string &list) {
	ListNode *head = new ListNode(list[0]);
	ListNode* cur = head;
	for (size_t i = 3; i < list.size(); i += 3) {
		cur->next = new ListNode(list[i]);
		cur = cur->next;
	}
	return head;
}

ListNode* ReverseList(ListNode *head) {
	if (!head || !head->next) {
		return head;
	}
	ListNode *p = head;
	ListNode *q = head->next;
	p->next = nullptr;
	while (q) {
		p = q;
		q = q->next;
		p->next = head;
		head = p;
	}
	return head;
}

int main()
{
	string list;
	while (cin >> list) {
		ListNode *l = CreateList(list);
		l = ReverseList(l);
		ListNode *cur = l;
		while (cur) {
			if (cur->next) {
				cout << cur->val << "->";
			}
			else {
				cout << cur->val;
			}
			cur = cur->next;
		}
		cout << endl;
	}
	return 0;
}

bool isKeyString(string &s, int len)
{
	int cnt[256] = { 0 };
	for (int i = 0; i < len; i++) {
		cnt[s[i]]++;
	}
	for (int i = 0; i < len; i++) {
		if (cnt[s[i]] > len / 2) {
			return true;
		}
	}
	return false;
}

int main()
{
	int n;
	while (cin >> n) {
		string s;
		cin >> s;
		int cnt = n;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= n - i; j++) {
				if (isKeyString(s.substr(j, i), i)) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

int main()
{
	int n, k;
	while (cin >> n >> k) {
		vector<int> prices(n);
		for (int &p : prices) {
			cin >> p;
		}
		int len = 1, min_len = 100, index = -1;
		bool flag = false;
		int ans = -1;
		for (size_t i = 0; i < prices.size(); i++) {
			if (prices[i] == 0) {
				continue;
			}
			if (prices[i] <= k) {
				len = 1;
				if (!flag) {
					index = i;
					flag = true;
				}
			}
			else {
				flag = false;
				len++;
			}
			if (len < min_len) {
				min_len = len;
				ans = index + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

struct ListNode {
	ListNode(int val = -1)
	: _next(nullptr)
	, _val(val)
	{}
	ListNode *_next;
	int _val;
};

ListNode * CreateList(ListNode *l) {
	int val;
	cin >> val;
	ListNode *head = new ListNode(val);
	ListNode *cur = head;
	while (cin >> val && val != -1) {
		ListNode *node = new ListNode(val);
		cur->_next = node;
		cur = node;
	}
	return head;
}


ListNode *AddList(ListNode *l1, ListNode *l2) {
	ListNode *head = nullptr, *tail = nullptr;
	int power = 0; //进位
	while (l1 || l2) {
		int n1 = l1 ? l1->_val : 0;
		int n2 = l2 ? l2->_val : 0;
		int add = n1 + n2 + power;
		if (!head) {
			head = tail = new ListNode(add % 10);
		}
		else {
			tail->_next = new ListNode(add % 10);
			tail = tail->_next;
		}
		power = add / 10;
		if (l1) {
			l1 = l1->_next;
		}
		if (l2) {
			l2 = l2->_next;
		}
	}
	if (power > 0) { //还有进位
		tail->_next = new ListNode(power);
	}
	return head;
}

int main() {
	//int a;
	//cin >> a;
	ListNode *l1 = nullptr, *l2 = nullptr;
	l1 = CreateList(l1);
	l2 = CreateList(l2);
	ListNode *res = AddList(l1, l2);
	ListNode *cur = res;
	while (cur) {
		cout << cur->_val << ' ';
		cur = cur->_next;
	}
	cout << endl;
	return 0;
}

class A
{
public:
	A() {
		cout << "A" << endl;
	}
	virtual ~A() {
		cout << "~A" << endl;
	}
	void f(){ cout << "A::f()" << endl; }
	int a;
};

class B : public A
{
public:
	B() {
		cout << "B" << endl;
	}
	~B() {
		cout << "~B" << endl;
	}
	void f(int a){ cout << "B::f()" << endl; }
	int a;
};

int main()
{
	B *p = new B;
	delete p;
	return 0;
}
#endif