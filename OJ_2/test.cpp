#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip>
#include <list>
#include <set>
#include <functional>
#include <unordered_map>
using namespace std;

#if 0
//查找第k小的元素
int main()
{
	priority_queue<int, vector<int>, greater<int>> pq; //小堆
	set<int> s; //集合，用于去重
	int n;
	while (cin >> n) {
		while (!pq.empty()) {
			pq.pop();
		}
		s.clear();
		vector<int> arr(n);
		for (int &num : arr) {
			cin >> num;
			pq.push(num);
		}
		int k, cnt = 0;
		cin >> k;
		while (cnt < k && !pq.empty()) {
			int val = pq.top();
			if (!s.count(val)) {
				s.insert(val);
				cnt++;
			}
			if (cnt == k) {
				cout << val;
				break;
			}
			pq.pop();
		}
	}
	return 0;
}

//设计LRU缓存系统
int main()
{
	unordered_map<int, int> ump;
	list<int> lt;
	int n, k;
	cin >> n >> k;
	vector<vector<int>> vv(n, vector<int>(3, 0));
	for(int i = 0; i < n; i++) {
		cin >> vv[i][0];
		if (vv[i][0] == 1) {
			cin >> vv[i][1] >> vv[i][2];
		}
		else {
			cin >> vv[i][1];
		}
	}
	for(auto &v : vv) {
		if(v[0] == 1) { //set
			ump[v[1]] = v[2];
			lt.push_back(v[1]);
			if(lt.size() > k) {
				ump.erase(lt.front());
				lt.erase(lt.begin());
			}
		}
		else { //get
			if(!ump.count(v[1])) {
				cout << -1 << endl;
				continue;
			}
			cout << ump[v[1]] << endl;
			lt.remove(v[1]);
			lt.push_back(v[1]);
		}
	}
	return 0;
}

//连续最大和
int main()
{
	int n;
	while (cin >> n) {
		vector<int> arr(n);
		for (int &num : arr) {
			cin >> num;
		}
		int tmp = arr[0];
		int ans = arr[0];
		for (int i = 1; i < arr.size(); i++) {
			tmp += arr[i];
			tmp = max(tmp, arr[i]);
			ans = max(ans, tmp);
		}
		cout << ans << endl;
	}
	return 0;
}

//数组中出现次数超过一半的数字(摩尔投票)
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		int vote = 1;
		int target = gifts[0];
		for(size_t i = 1; i < gifts.size(); i++) {
			if(vote == 0) {
				target = gifts[i];
				vote = 1;
			}
			else if(gifts[i] == target){
				vote++;
			}
			else {
				vote--;
			}
		}
		int cnt = 0;
		for(size_t i = 0; i < gifts.size(); i++) {
			if(target == gifts[i]) {
				cnt++;
			}
		}
		return cnt > gifts.size() / 2 ? target : 0;
	}
};

//二进制插入
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		n |= (m << j);
		return n;
	}
};

//查找组成—个偶数最接近的两个素数
bool isSu(int n)
{
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	while(cin >> n) {
		int m1 = n /2;
		int m2 = 0;
		while(1) {
			if(isSu(m1)) {
				m2 = n - m1;
				if(isSu(m2)) {
					break;
				}
			}
			m1--;
		}
		cout << m1 << endl;
		cout << m2 << endl;
	}
	return 0;
}

//旋转链表
//先成环，再断开
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next) {
			return head;
		}
		int len = 1; //统计链表长度
		ListNode *p = head;
		while (p->next) {
			len++;
			p = p->next;
		}
		p->next = head; //闭合链表
		k %= len; //取模去重
		p = head;
		//寻找断开的地方
		while (--len != k) {
			p = p->next;
		}
		//断开并重新连接
		head = p->next;
		p->next = nullptr;
		return head;
	}
};

//礼物的最大价值
class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		if(row == 0 || col == 0) {
			return 0;
		}
		vector<vector<int>> dp(row, vector<int>(col, 0));
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				int up = 0, left = 0; //上边和左边的元素
				if(i > 0) {
					up = dp[i - 1][j];
				}
				if(j > 0) {
					left = dp[i][j - 1];
				}
				dp[i][j] = max(up, left) + grid[i][j]; //状态转移
			}
		}
		return dp[row - 1][col - 1];
	}
};

//俩数之和
class Solution {
public:
	/**
	*
	* @param numbers int整型vector
	* @param target int整型
	* @return int整型vector
	*/
	vector<int> twoSum(vector<int>& numbers, int target) {
		// write code here
		unordered_map<int, int> index;
		for (int i = 0; i < numbers.size(); i++) {
			if (index.count(target - numbers[i])) {
				return{ index[target - numbers[i]], i + 1 };
			}
			index[numbers[i]] = i + 1;
		}
		return{};
	}
};

//调整数组顺序使奇数位于偶数前面
class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			if ((nums[left] % 2) != 0) {
				left++;
				continue;
			}
			if ((nums[right] % 2) == 0) {
				right--;
				continue;
			}
			swap(nums[left++], nums[right--]);
		}
		return nums;
	}
};

//删除链表中的节点
class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		ListNode *cur = head, *prev = nullptr;
		while(cur) {
			if(cur->val == val) {
				break;
			}
			prev = cur;
			cur = cur->next;
		}
		if(prev == nullptr) {
			return head->next;
		}
		prev->next = cur->next;
		return head;
	}
};

//二叉树的镜像
class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if(!root) {
			return nullptr;
		}
		TreeNode *tmp = mirrorTree(root->left);
		root->left = mirrorTree(root->right);
		root->right = tmp;
		return root;
	}
};

//二叉树的子结构
class Solution {
private:
	bool judgeCur(TreeNode *a, TreeNode *b) {
		if(b == nullptr) {
			return true;
		}
		if(a == nullptr || a->val != b->val) {
			return false;
		}
		return judgeCur(a->left, b->left) && judgeCur(a->right, b->right);
	}
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		return (A != nullptr && B != nullptr) && (judgeCur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
	}
};

//链表的倒数第k个节点
class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode *slow = head, *fast = head;
		while(k--) {
			if(fast) {
				fast = fast->next;
			}
			else {
				return nullptr;
			}
		}
		while(fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};

//百度笔试--剧组
vector<int> ans;
void Solution(vector<int> &partner, vector<int> &juzu) 
{
	for(size_t i = 0; i < partner.size(); i++) {
		int cnt = 0;
		for(size_t j = 0; j < juzu.size(); j++) {
			if(partner[i] <= juzu[j]) {
				cnt++;
			}
		}
		ans.push_back(cnt);
	}
}

int main()
{
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		vector<int> partner(n);
		vector<int> juzu(m);
		for(int &p : partner) {
			cin >> p;
		}
		for(int &j : juzu) {
			cin >> j;
		}
		Solution(partner, juzu);
		for(int &a : ans) {
			cout << a << ' ';
		}
		cout << endl;
		ans.clear();
	}
	return 0;
}

//丑数
class Solution {
public:
	bool isUgly(int n) {
		if(n <= 0) {
			return false;
		}
		while(1) {
			if(n == 1) {
				return true;
			}
			else if(n % 2 == 0) {
				n /= 2;
			}
			else if(n % 3 == 0) {
				n /= 3;
			}
			else if(n % 5 == 0) {
				n /= 5;
			}
			else {
				return false;
			}
		}
	}
};

//丑数2
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> dp(n + 1);
		dp[1] = 1;
		int p2 = 1, p3 = 1, p5 = 1;
		for(int i = 2; i < n + 1; i++) {
			int num1 = dp[p2] * 2, num2 = dp[p3] * 3, num3 = dp[p5] * 5;
			dp[i] = min(min(num1, num2), num3);
			if(dp[i] == num1) {
				p2++;
			}
			if(dp[i] == num2) {
				p3++;
			}
			if(dp[i] == num3) {
				p5++;
			}
		}
		return dp[n];
	}
};

//旋转数组的最小数字
class Solution {
public:
	int minArray(vector<int>& numbers) {
		int size = numbers.size();
		int left = 0, right = size - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (numbers[mid] < numbers[right]) {
				right = mid;
			}
			else if (numbers[mid] > numbers[right]) {
				left = mid + 1;
			}
			else {
				right--;
			}
		}
		return numbers[left];
	}
};

//青蛙跳台阶问题
class Solution {
public:
	int numWays(int n) {
		if(n == 0) {
			return 1;
		}
		if(n <= 2) {
			return n; //一层或两层
		}
		int a = 1, b = 2, sum; //a保存f(n - 2), b保存f(n - 1), sum保存f(n)
		for(int i = 3; i <= n; i++) {
			sum = (a + b) % 1000000007;
			a = b;
			b = sum;
		}
		return sum;
	}
};

//斐波那契数列
int fib(int n) 
{
	vector<int> dp;
	for (int i = 0; i < n + 1; i++) {
		if (i == 0) {
			dp.push_back(0);
		}
		else if (i == 1) {
			dp.push_back(1);
		}
		else {
			dp.push_back((dp[i - 1] + dp[i - 2]) % 1000000007);
		}
	}
	return dp[n];
}

int main()
{
	for (int i = 0; i < 11; i++) {
		cout << fib(i) << endl;
	}
	return 0;
}

//根据前序和中序还原二叉树
//递归法1
class Solution {
public:
	//构建哈希映射，保存中序中各节点的位置，以便快速定位到中序中根节点的位置
	unordered_map<int, int> index;
	TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
		if (pre_left > pre_right) { //不能是>=
			return nullptr;
		}
		int pre_root = pre_left; //前序中根节点的位置，即第一个元素
		int in_root = index[preorder[pre_root]]; //中序中根节点的位置

		//先还原根节点
		TreeNode *root = new TreeNode(preorder[pre_root]);
		int left_size = in_root - in_left; //左子树的元素个数

		//递归构建左子树和右子树
		//左子树：前序中[左边界+1，左边界+左子树元素个数]的元素就对应了中序中[左边界，左边界+左子树元素个数]的元素
		root->left = myBuildTree(preorder, inorder, pre_left + 1, pre_left + left_size, in_left, in_left + left_size);
		//右子树：前序中[左边界+1+左子树元素个数，右边界]的元素就对应了中序中[根节点位置+1，右边界]的元素
		root->right = myBuildTree(preorder, inorder, pre_left + 1 + left_size, pre_right, in_root + 1, in_right);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = inorder.size();
		for (size_t i = 0; i < n; i++) {
			index[inorder[i]] = i; //键为中序中的元素，值为其在中序中的下标
		}
		return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
	}
};
//2
class Solution {
private:
	vector<int> preorder;
	unordered_map<int, int> index;
	TreeNode* BuildTree(int pre_root, int in_left, int in_right) {
		if (in_left > in_right) {
			return nullptr;
		}
		int in_root = index[preorder[pre_root]];
		TreeNode *root = new TreeNode(preorder[pre_root]);
		int left_size = in_root - in_left;
		root->left = BuildTree(pre_root + 1, in_left, in_root - 1);
		root->right = BuildTree(pre_root + left_size + 1, in_root + 1, in_right);
		return root;
	}
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		this->preorder = preorder;
		int n = inorder.size();
		for (int i = 0; i < n; i++) {
			index[inorder[i]] = i;
		}
		return BuildTree(0, 0, n - 1);
	}
};

//二维数组的查找
class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if(matrix.empty()) {
			return false;
		}
		int row = matrix.size();
		int col = matrix[0].size();
		int i = 0, j = col - 1;
		while(i < row && j >= 0) {
			if(target == matrix[i][j]) {
				return true;
			}
			else if(target > matrix[i][j]) {
				i++;
			}
			else {
				j--;
			}
		}
		return false;
	}
};

//最长回文子串
//动态规划
class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		if (len == 0 || len == 1) {
			return s;
		}

		//dp[i][j]表示s[i]-s[j]的元素是否为回文子串（1为真， 0为假）
		vector<vector<int>> dp(len, vector<int>(len));

		int max = 1; //最长回文子串的长度
		int start = 0; //最长回文子串起始位置

		for (int i = 0; i < len; i++) { //初始化状态（一个字符和俩个字符相等的情况都是回文子串）
			dp[i][i] = 1; //单个字母肯定回文
			if (i < len - 1 && s[i] == s[i + 1]) { //俩个字母是否回文
				dp[i][i + 1] = 1;
				start = i;
				max = 2;
			}
		}

		for (int l = 3; l <= len; l++) { //从长度为3的回文子串开始判断
			for (int i = 0; i + l - 1 < len; i++) {
				int j = i + l - 1; //结束标记
				if (s[i] == s[j] && dp[i + 1][j - 1] == 1) { //状态转移
					dp[i][j] = 1;
					start = i;
					max = l;
				}
			}
		}
		return s.substr(start, max);
	}
};

//中心扩展法
class Solution {
private:
	pair<int, int> expandAroundCentor(const string &s, int l, int r) {
		while (l >= 0 && r < s.size() && s[l] == s[r]) {
			l--;
			r++;
		}
		return{ l + 1, r - 1 };
	}
public:
	string longestPalindrome(string s) {
		int len = s.size();
		int start = 0, end = 0;
		for (int i = 0; i < len; i++) {
			auto[left1, right1] = expandAroundCentor(s, i, i);
			auto[left2, right2] = expandAroundCentor(s, i, i + 1);
			if (right1 - left1 > end - start) {
				start = left1;
				end = right1;
			}
			if (right2 - left2 > end - start) {
				start = left2;
				end = right2;
			}
		}
		return s.substr(start, end - start + 1);
	}
};

/*
有一款产品，年化收益率为x%，x为浮点数，精确到小数点后3位，客户买入后就
开始按日计算利息，每持有一天就获得一天利息，客户卖出后自动结束计息。客
户在多个日期内进行了买入和卖出，结构体orderrec记录的是客户每一次的买入或卖出信息。
//买入或卖出记录结构体
struct ORDERREC{
int order_amount;//买卖金额 ,单位元；
int order_date;  //买卖日期，格式为yyyymmdd例如20200901表示2020年9月1日；
char order_flag;  //买卖方向，字符’B’表示买入，字符‘S’表示卖出；
}
ORDERREC orderlist[100]是一个结构体数组，记录了客户所有的买入卖出记录，
已经按照买卖日期order_date从小到大进行了排序，请根据该结构体，计算出来，
客户今天：Today(int型整数，格式为yyyymmdd，大于orderlist中所有日期)为止
获得的所有利息，精确到小数点后2位。
计算计息公式为：interest=（A – B）* x% / 365,A为买入日期，
B为卖出日期,A和B都是int型整数，格式为yyyymmdd。
*/

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool Isleap(int year)
{
	if(year%4 == 0 && year%100 != 0)
		return true;
	else if(year%400 == 0)
		return true;
	return false;
}

struct info
{
	info() = default;
	info(int time,int money,bool status)
	{
		time_ = time;
		money_ = money;
		status_ = status;
	}
	int time_;
	int money_;
	bool status_;//规定true买入，false卖出
};
double rata = 0.5;


void caltime(int time, int& year, int& month, int& day)
{
	string str;
	while(time)
	{
		str.push_back(time%10 + 48);
		time /= 10;
	}
	reverse(str.begin(), str.end());
	//str = to_string(time);
	year = stoi(str.substr(0, 4));
	month = stoi(str.substr(4, 2));
	day = stoi(str.substr(6, 2));
}

int calday(const int start_year,const int start_month, const int start_day, const int end_year, const int end_month, const int end_day)
{
	if(start_year > end_year || (start_year == end_year && start_month > end_month) || (start_year == end_year && start_month == end_month && start_day > end_day))
		return -1;
	int day = 0;
	if(start_year == end_year)
	{
		if(start_month == end_month)
			day =  end_day - start_day;
		else
		{
			for(int i = start_month; i < end_month; i++)
			{
				if(i == 2 && Isleap(start_year))
					day += 29;
				else 
					day += days[i];
			}
			day -= start_day;
			day += end_day;
		}
	}
	else
	{
		for(int i = start_year; i < end_year; i++)
		{
			if(Isleap(start_year))
				day += 366;
			else
				day += 365;
		}
		for(int i = 1; i < start_month ; i++)
		{
			if(i == 2 && Isleap(start_year))
				day -= 29;
			else
				day -= days[i];
		}
		day -= start_day;
		for(int i = 1; i < end_month; i++)
		{
			if(i == 2 && Isleap(start_year))
				day += 29;
			else
				day += days[i];
		}
		day += end_day;
	}
	return day; 
}

int main()
{
	vector<info> arr;
	arr.push_back(info(20201001,100,true));
	arr.push_back(info(20201101,100,false));
	arr.push_back(info(20201201,100,true));
	arr.push_back(info(20210101,100,true));
	arr.push_back(info(20210201,100,true));
	double money_in = 0;
	double money_out = 0;
	int start_year = 0;
	int end_year = 0;
	int start_month = 0;
	int end_month = 0;
	int start_day = 0;
	int end_day = 0;
	//核心---
	//从第二个节点开始算起
	//1.计算天数
	//2.判断是否为买入
	//    是----更新在里面存的钱数
	//           （注意在里面存的钱分为三部分，
	//                  第一部分是上个月在里面存的，
	//                  第二部分是之前就有的
	//                  第三部分是之前第一部分和第二部分产生的利息
	//    否---更新在里面存的钱&保存取出来的钱
	for(size_t i = 1;i < arr.size(); i++)
	{
		//计算天数
		int start = arr[i-1].time_;
		caltime(start,start_year, start_month, start_day);
		int end = arr[i].time_;
		caltime(end,end_year, end_month, end_day);
		int all_day = calday(start_year, start_month, start_day, end_year, end_month, end_day);
		//判断是否为买入
		//   是-算出利息，更新在里面存的钱的数目
		//   否-算出利息，更新在里面存的钱的数目，更新取出钱的数目
		if(arr[i-1].status_)
		{
			//买入
			money_in = money_in + arr[i-1].money_ + (money_in + arr[i-1].money_) * rata * all_day;
		}
		else
		{
			//卖出
			money_out += arr[i-1].money_;
			money_in = money_in - arr[i-1].money_ + (money_in - arr[i-1].money_) * rata * all_day;
		}
	}

	return 0;
}

//字符串转整形
class Solution {
public:
	int myAtoi(string s) {
		int len = s.size();
		int i = 0;
		while (s[i] == ' ') {
			i++;
		}
		int flag = 1;
		if(s[i] == '-') {
			flag = -flag;
			i++;
		}
		else if(s[i] == '+') {
			i++;
		}
		int ans = 0;
		long long num = 0;
		while(i < len) {
			if(!isdigit(s[i])) {
				break;
			}
			num = num * 10 + flag * (s[i] - '0');
			if(num > INT_MAX) {
				ans = INT_MAX;
				break;
			}
			else if(num < INT_MIN) {
				ans = INT_MIN;
				break;
			}
			else {
				ans = num;
				i++;
			}
		}
		return ans;
	}
};

//无重复的最长子串
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = s.size();
		unordered_set<char> us;
		int right = -1, ans = 0;
		for (int i = 0; i < len; i++) {
			if (i != 0) {
				us.erase(s[i - 1]);
			}
			while (right + 1 < len && !us.count(s[right + 1])) {
				us.insert(s[right + 1]);
				right++;
			}
			ans = max(ans, right - i + 1);
		}
		return ans;
	}
};

//二叉树层序遍历
class Solution {
public:
	/**
	*
	* @param root TreeNode类
	* @return int整型vector<vector<>>
	*/
	vector<vector<int> > levelOrder(TreeNode* root) {
		// write code here
		vector<vector<int>> ans;
		if (!root) {
			return ans;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			vector<int> tmp;
			while (size--) {
				TreeNode *node = q.front();
				tmp.push_back(node->val);
				q.pop();
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
			if (!tmp.empty()) {
				ans.push_back(tmp);
			}
		}
		return ans;
	}
};

//反转部分单链表
class Solution {
public:
	/**
	*
	* @param head ListNode类 the head
	* @param l int整型 left
	* @param r int整型 right
	* @return ListNode类
	*/
	ListNode* reversePartLinkedlist(ListNode* head, int l, int r) {
		// write code here
		if (!head || !head->next) {
			return head;
		}
		ListNode *p = head, *q = nullptr; //q是反转前的最后一个节点，也可能是空
		for (int i = 0; i < l - 1; i++) {
			q = p;
			p = p->next;
		}
		//此时p在l的位置
		ListNode *rend = p, *prev = p; //部分反转后的尾节点及首节点
		ListNode *next = nullptr; //反转中用的辅助节点，记录p的下一个位置
		p = p->next; //p走到下一个节点，开始部分反转
		for (int i = l; i < r; i++) {
			next = p->next;
			p->next = prev;
			prev = p;
			p = next;
		}
		//此时p在r+1的位置
		rend->next = p; //不能是next（可能为nullptr）
		if (q) { //q存在则连接链表，不存在则说明链表是从开头开始反转的
			q->next = prev;
		}
		else {
			head = prev;
		}
		return head;
	}
};

//二叉树前序遍历迭代解法
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		if (!root) {
			return ans;
		}
		stack<TreeNode*> s;
		TreeNode *node = root;
		while (!s.empty() || node) {
			while (node) {
				ans.push_back(node->val);
				s.push(node);
				node = node->left;
			}
			node = s.top();
			s.pop();
			node = node->right;
		}
		return ans;
	}
};

//合并有序链表
//迭代解法
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *res = new ListNode(-1);
		ListNode *cur = res;
		while(l1 && l2) {
			if(l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next;
			}
			else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		cur->next = l1 == nullptr ? l2 : l1;
		return res->next;
	}
};

//递归解法
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(!l1) {
			return l2;
		}
		else if(!l2) {
			return l1;
		}
		else if(l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};

//寻找第K大(通过快排)
class Solution {
public:
	int partition(vector<int> &a, int l, int r) {
		int key = a[l];
		while(l < r) {
			while(l < r && a[r] < key) {
				r--;
			}
			a[l] = a[r];
			while(l < r && a[l] >= key) {
				l++;
			}
			a[r] = a[l];
		}
		a[l] = key;
		return l;
	}
	int findKth(vector<int> a, int n, int K) {
		// write code here
		int left = 0, right = n;
		while(left < right) {
			int key = partition(a, left, right - 1);
			if(key + 1 == K) {
				return a[key];
			}
			else if(key + 1 < K) {
				left = key + 1;
			}
			else {
				right = key;
			}
		}
		return -1;
	}
};

/*topk问题*/
//自建大/小堆
class Solution {
private:
	void AdjustUp(vector <int> &v, int cur)
	{
		int n = v.size();
		int i = cur, j = 2 * i + 1;
		int tmp = v[i];
		while (j < n) {
			if (j + 1 < n && v[j + 1] < v[j]) {
				j++;
			}
			if (v[j] < tmp) {
				v[i] = v[j];
				i = j;
				j = 2 * i + 1;
			}
			else {
				break;
			}
		}
		v[i] = tmp;
	}

	void AdjustDown(vector<int> &v, int cur) {
		int n = v.size();
		int i = cur, j = 2 * i + 1;
		int tmp = v[i];
		while(j < n) {
			if(j + 1 < n && v[j + 1] > v[j]) {
				j++;
			}
			if(tmp < v[j]) { //向下调整
				v[i] = v[j];
				i = j;
				j = 2 * i + 1;
			}
			else {
				break;
			}
		}
		v[i] = tmp;
	}
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> ans;
		if(k == 0 || k > input.size()) {
			return ans;
		}
		int i = 0;
		for(; i < k; i++) {
			ans.push_back(input[i]);
		}
		for(int cur = ans.size() / 2 - 1; cur >= 0; cur--) {
			AdjustDown(ans, cur);
		}
		for(; i < input.size(); i++) {
			if(input[i] < ans[0]) {
				swap(ans[0], ans[ans.size() - 1]);
				ans.pop_back();
				AdjustDown(ans, 0);
				ans.push_back(input[i]);
				for(int cur = ans.size() / 2 - 1; cur >= 0; cur--) {
					AdjustDown(ans, cur);
				}
			}
		}
		return ans;
	}

	vector<int> GetBiggestNumbers_Solution(vector<int> input, int k) {
		vector<int> ans;
		if (k == 0 || k > input.size()) {
			return ans;
		}
		int i = 0;
		for (; i < k; i++) {
			ans.push_back(input[i]);
		}
		for (int cur = ans.size() / 2 - 1; cur >= 0; cur--) {
			AdjustUp(ans, cur);
		}
		for (; i < input.size(); i++) {
			if (input[i] > ans[0]) {
				swap(ans[0], ans[ans.size() - 1]);
				ans.pop_back();
				AdjustUp(ans, 0);
				ans.push_back(input[i]);
				for (int cur = ans.size() / 2 - 1; cur >= 0; cur--) {
					AdjustUp(ans, cur);
				}
			}
		}
		return ans;
	}
};

//使用priority_queue建立小/大堆
#include <functional> //向priority_queue中传递greater比较器时需包含
//仿函数
struct Compare{
	bool operator()(const int l, const int r) {
		return l > r;
	}
};

class Solution {
	typedef bool(*COM)(const int, const int); //函数指针
	static bool compare(const int left, const int right) { //自制比较器
		return left > right;
	}
public:
	vector<int> GetBiggestNumbers_Solution(vector<int> input, int k) {
		vector<int> ans;
		if (k == 0 || (size_t)k > input.size()) {
			return ans;
		}

		priority_queue<int, vector<int>, greater<int>> pq;
		//priority_queue<int, vector<int>, COM> pq(compare); //函数指针方式
		//priority_queue<int, vector<int>, Compare> pq; //仿函数方式
		for (const auto &e : input) {
			if (pq.size() < (size_t)k) {
				pq.push(e);
			}
			else {
				if (e > pq.top()) {
					pq.pop();
					pq.push(e);
				}
			}
		}
		while (!pq.empty()) {
			ans.push_back(pq.top());
			pq.pop();
		}
		//reverse(ans.begin(), ans.end());
		return ans;
	}
};


int main()
{
	Solution sol;
	vector<int> input{ 4, 5, 1, 6, 2, 7, 3, 8 };
	//input = sol.GetLeastNumbers_Solution(input, 4);
	input = sol.GetBiggestNumbers_Solution(input, 4);
	for (auto e : input) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

//快排方式
class Solution {
private:
	//前后指针法
	int partition_2(vector<int> &input, int left, int right) {
		int base = input[left];
		int front = left, back = left + 1;
		for (int i = back; i <= right; i++) {
			if (input[i] < base) {
				if (++front != i) {
					swap(input[i], input[front]);
				}
			}
		}
		swap(input[left], input[front]);
		return front;
	}
	//挖坑法
	int partition_1(vector<int> &input, int left, int right) {
		int base = input[left];
		while (left < right) {
			while (left < right &&input[right] > base) {
				right--;
			}
			input[left] = input[right];
			while (left < right && input[left] <= base) {
				left++;
			}
			input[right] = input[left];
		}
		input[left] = base;
		return left;
	}
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> ans;
		if (k == 0 || k > input.size()) {
			return ans;
		}
		int left = 0, right = input.size();
		while (left < right) {
			int mid = partition_2(input, left, right - 1);
			if (mid + 1 == k) {
				return vector<int>({ input.begin(), input.begin() + k });
			}
			else if (mid + 1 < k) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return ans;
	}
};

//简单错误记录
struct ErrorLog{
	string file_name;
	int line;
	int count; //该错误出现的次数
};

ErrorLog CreateLog(string file_name, const int &line)
{
	int len = file_name.size();
	int index = -1;
	for (int i = len - 1; i >= 0; i--) {
		if (file_name[i] == '\\') {
			index = i;
			break;
		}
	}
	ErrorLog log;
	file_name = file_name.substr(index + 1);
	log.file_name = file_name;
	log.line = line;
	log.count = 1;
	return log;
}

void RecordErrorLog(vector<ErrorLog> &all_log, const ErrorLog &log)
{
	bool isRepeat = false;
	for (size_t i = 0; i < all_log.size(); i++) {
		if (log.file_name == all_log[i].file_name && log.line == all_log[i].line) {
			all_log[i].count++;
			isRepeat = true;
			break;
		}
	}
	if (!isRepeat) {
		all_log.push_back(log);
	}
}

int main()
{
	string file;
	int n;
	vector<ErrorLog> all_log;
	while (cin >> file >> n) {
		ErrorLog log = CreateLog(file, n);
		RecordErrorLog(all_log, log);
	}
	int start = all_log.size() - 8;
	if (start < 0) {
		start = 0;
	}
	for (int i = start; i < all_log.size(); i++) {
		int len = all_log[i].file_name.size();
		if (len > 16) {
			all_log[i].file_name = all_log[i].file_name.substr(len - 16);
		}
		cout << all_log[i].file_name << " " << all_log[i].line << " " << all_log[i].count << endl;
	}
	return 0;
}

//数组中出现次数超过一半的数字
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int ans = 0, count = 0, votes = 0;
		for(auto &e : numbers) {
			if(votes == 0) {
				ans = e;
			}
			votes += ans == e ? 1 : -1;
		}
		for(auto &e : numbers) {
			if(e == ans) {
				count++;
			}
		}
		return count > numbers.size() / 2 ? ans : 0;
	}
};

//乒乓球框
int main()
{
	string a, b;
	while (cin >> a >> b) {
		int len_a = a.size();
		int len_b = b.size();
		int count[26] = { 0 };
		for (int i = 0; i < len_a; i++) {
			count[a[i] - 'A']++;
		}
		bool flag = false; //标记是否为No
		for (int i = 0; i < len_b; i++) {
			count[b[i] - 'A']--;
			if (count[b[i] - 'A'] < 0) {
				cout << "No" << endl;
				flag = true; //是No后边就不输出Yes
				break;
			}
		}
		if (!flag) {
			cout << "Yes" << endl;
		}
	}
	return 0;
}

//查找兄弟单词
bool isBrotherWord(string s1, string s2)
{
	if(s1.length() == s2.length()) {
		if(s1 == s2) {
			return false;
		}
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		if(s1 == s2) {
			return true;
		}
	}
	return false;
}

int main()
{
	int num;
	while(cin >> num) {
		vector<string> dict;
		for(int i = 0; i < num; i++) {
			string tmp;
			cin >>  tmp;
			dict.push_back(tmp);
		}
		sort(dict.begin(), dict.end());
		string word;
		int n;
		cin >> word;
		cin >> n;
		string ans_word;
		int count = 0;
		for(int i  = 0; i < num; i++) {
			if(isBrotherWord(word, dict[i])) {
				count++;
				if(count == n) {
					ans_word = dict[i];
				}
			}
		}
		cout << count;
		if(count >= n) {
			cout << " " << ans_word;
		}
		cout << endl;
	}
	return 0;
}


//把数字翻译成字符串
class Solution {
public:
	int translateNum(int num) {
		string code = to_string(num);
		int p = 0, q = 0, r = 1;
		for (size_t i = 0; i < code.size(); i++) {
			p = q;
			q = r;
			r = 0;
			r += q;
			if (i == 0) {
				continue;
			}
			string pre = code.substr(i - 1, 2);
			if (pre >= "10" && pre <= "25") {
				r += p;
			}
		}
		return r;
	}
};

//走迷宫
char maze[10][10];//迷宫
int flag[10][10] = { 0 };//记录是否走过以及当前步数(0表示没走过)

int Bfs(int x0, int y0)
{
	queue<pair<int, int>> q; //存储格子坐标的队列
	pair<int, int> p;
	q.push(make_pair(x0, y0));
	int x, y;
	while (1) {
		p = q.front();
		x = p.first;
		y = p.second;
		//走到终点就退出循环
		if (x == 9 && y == 8) {
			return flag[9][8];
		}
		//分别判断该格子上下左右的格子
		if ((y - 1) >= 0 && (y - 1) <= 9 && x >= 0 && x <= 9 && flag[x][y - 1] == 0 && maze[x][y - 1] != '#') {
			flag[x][y - 1] = flag[x][y] + 1;
			q.push(make_pair(x, y - 1));
		}
		if ((y + 1) >= 0 && (y + 1) <= 9 && x >= 0 && x <= 9 && flag[x][y + 1] == 0 && maze[x][y + 1] != '#') {
			flag[x][y + 1] = flag[x][y] + 1;
			q.push(make_pair(x, y + 1));
		}
		if ((x - 1) >= 0 && (x - 1) <= 9 && y >= 0 && y <= 9 && flag[x - 1][y] == 0 && maze[x - 1][y] != '#') {
			flag[x - 1][y] = flag[x][y] + 1;
			q.push(make_pair(x - 1, y));
		}
		if ((x + 1) >= 0 && (x + 1) <= 9 && y >= 0 && y <= 9 && flag[x + 1][y] == 0 && maze[x + 1][y] != '#') {
			flag[x + 1][y] = flag[x][y] + 1;
			q.push(make_pair(x + 1, y));
		}
		//判断完上下左右4个格子后该格子应该出队
		q.pop();
	}
}

int main()
{
	char c;
	while (cin >> c) {
		maze[0][0] = c;
		for (int i = 1; i < 10; i++) {
			cin >> maze[0][i];
		}
		getchar(); //吃掉换行
		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cin >> maze[i][j];
			}
			getchar();
		}
		cout << Bfs(0, 1) << endl;
		memset(flag, 0, sizeof(flag)); //清空全局数组flag
	}
	return 0;
}

//解读密码
int main()
{
	string code;
	while (getline(cin, code)) {
		int len = code.length();
		for (int i = 0; i < len; i++) {
			if (code[i] >= '0' && code[i] <= '9') {
				cout << code[i];
			}
		}
		cout << endl;
	}
	return 0;
}

//发邮件
int main()
{
	long long ans[21] = { 0 };
	ans[2] = 1;
	for (int i = 3; i < 21; i++) {
		ans[i] = (i - 1) * (ans[i - 1] + ans[i - 2]);
	}
	int n;
	while (cin >> n) {
		cout << ans[n] << endl;
	}
	return 0;
}

//最长上升子序列
int main()
{
	int n;
	while(cin >> n) {
		vector<int> height(n);
		vector<int> max_long(n);
		for(int i = 0; i < n; i++) {
			cin >> height[i];
			max_long[i] = 1;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < i; j++) {
				if(height[j] < height[i]) {
					max_long[i] = max(max_long[j] + 1, max_long[i]);
				}
			}
		}
		int ans = 0;
		for(auto &m : max_long) {
			ans = max(ans, m);
		}
		cout << ans << endl;
	}
	return 0;
}

//重复的子字符串
//法1
class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int len = s.length();
		for(int i = 1; i <= len / 2; i++) {
			bool flag = true;
			if(len % i == 0) {
				for(int j = i; j < len; j++) {
					if(s[j] != s[j - i]) {
						flag = false;
					}
				}
				if(flag) {
					return true;
				}
			}
		}
		return false;
	}
};
//法2
class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		return (s + s).find(s, 1) != s.size();
	}
};

//红与黑
int count = 0;//计数

//采用深度优先遍历的方式解决
void Result(vector<vector<char>>& vv, int x, int y)
{
	//不能通行的情况：越界+白色瓷砖
	if (x<0 || x >= vv.size() || y<0 || y >= vv[0].size() || vv[x][y] == '#')//走不通
		return;
	count++;
	vv[x][y] = '#';//走过的不能再走，需要标记起来，否则后面无法区分是否走过
	//上下左右
	Result(vv, x - 1, y);
	Result(vv, x + 1, y);
	Result(vv, x, y - 1);
	Result(vv, x, y + 1);
}

int main()
{
	int m = 0, n = 0;
	while (cin >> m >> n)
	{
		vector<vector<char>> vv(m, vector<char>(n));
		int x = 0, y = 0;
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				cin >> vv[i][j];
				//定位到人站的这块瓷砖
				if (vv[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}

		}
		Result(vv, x, y);
		cout << count << endl;
		count = 0;
	}
}


//蘑菇阵
int main()
{
	int n, m, k;
	while(cin >> n >> m >> k) {
		int i, j;
		int has[25][25];//有无蘑菇
		double dp[25][25];//能够到达每个格子的概率
		memset(has, 0, sizeof(has));
		memset(dp, 0, sizeof(dp));
		int x, y;
		for(i = 0; i < k; ++i){
			cin >> x >> y;
			has[x][y] = 1;
		}
		for(i = 1; i <= n; ++i) {
			for(j = 1; j <= m; ++j) {
				if(i == 1 && j == 1) {
					dp[1][1] = 1; continue;
				}
				if(has[i][j]) {
					dp[i][j] = 0; 
					continue;
				}
				if(i == n && j == m) {
					dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
					continue;
				}
				if(i == n) {dp[i][j] = dp[i-1][j]*0.5 + dp[i][j-1];
				continue;
				}
				if(j == m) {dp[i][j] = dp[i-1][j] + dp[i][j-1]*0.5;
				continue;
				}
				if(i == 1) {dp[i][j] = dp[i][j-1]*0.5;
				continue;
				}
				if(j == 1) {dp[i][j] = dp[i-1][j]*0.5;
				continue;
				}
				dp[i][j] = dp[i][j-1]*0.5 + dp[i-1][j]*0.5;
			}
		}
		cout << fixed << setprecision(2) << dp[n][m] << endl;
	}
	return 0;
}

//mkdir
bool IsSubstr(string &s1, string &s2)
{
	if (s1 == s2.substr(0, s1.size())) {
		return true;
	}
	return false;
}

void Print(vector<string> &v)
{
	string head = "mkdir -p ";
	int i = 0;
	while (i < v.size() - 1) {
		//前一个是后一个的子串并且后一个的下一个位置是'/', 则需要删除前一个字符串
		if (IsSubstr(v[i], v[i + 1]) && v[i + 1][v[i].size()] == '/') {
			v.erase(v.begin() + i);
		}
		else {
			i++;
		}
	}
	for (auto &e : v) {
		cout << head << e << endl;
	}
}

int main()
{
	int n;
	while (cin >> n) {
		vector<string> v(n);
		for (auto &e : v) {
			cin >> e;
		}
		sort(v.begin(), v.end());
		Print(v);
		cout << endl;
	}
	return 0;
}

//数据库连接池
int main()
{
	int n;
	while(cin >> n) {
		stack<string> s;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			string id, operation;
			cin >> id >> operation;
			if(operation == "connect") {
				s.push(id);
				if(s.size() > ans) {
					ans = s.size();
				}
			}
			else {
				s.pop();
			}
		}
		cout << ans << endl;
	}
	return 0;
}

//连续最大和
int main()
{
	int n;
	while (cin >> n) {
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		int ans = v[0];
		int tmp_max = v[0];
		for (int i = 1; i < n; i++) {
			tmp_max += v[i];
			tmp_max = max(tmp_max, v[i]);
			ans = max(ans, tmp_max);
		}
		cout << ans << endl;
	}
	return 0;
}

//删除公共字符
int main()
{
	string s1, s2;
	while (getline(cin, s1)) {
		getline(cin, s2);
		string ans = "";
		for (int i = 0; i < s1.length(); i++) {
			if (s2.find(s1[i]) != string::npos) {
				continue;
			}
			ans.push_back(s1[i]);
		}
		cout << ans << endl;
	}
	return 0;
}

//有序数组的平方
//法2
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		for (auto &e : nums) {
			e *= e;
		}
		sort(nums.begin(), nums.end());
		return nums;
	}
};

//法1
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		vector<int> ans;
		int size = nums.size();
		int neg = -1;
		for (int i = 0; i < size; i++) {
			if (nums[i] < 0) {
				neg = i;
			}
			else {
				break;
			}
		}
		int i = neg, j = neg + 1;
		while (i >= 0 || j < size) {
			if (i < 0) {
				ans.push_back(nums[j] * nums[j]);
				j++;
			}
			else if (j == size){
				ans.push_back(nums[i] * nums[i]);
				i--;
			}
			else if (nums[i] * nums[i] < nums[j] * nums[j]) {
				ans.push_back(nums[i] * nums[i]);
				i--;
			}
			else {
				ans.push_back(nums[j] * nums[j]);
				j++;
			}
		}
		return ans;
	}
};

//长按键入
class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int i = 0, j = 0;
		while(j < typed.size()) {
			if(i < name.size() && name[i] == typed[j]) {
				i++;
				j++;
			}
			else if(j > 0 && typed[j] == typed[j - 1]) {
				j++;
			}
			else {
				return false;
			}
		}
		return i == name.size();
	}
};

//存在重复元素
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() < 2) {
			return false;
		}
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1]) {
				return true;
			}
		}
		return false;
	}
};

//最后一个单词的长度
class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.empty() || s.length() == 0) {
			return 0;
		}
		int length = 0;
		int end = s.size() - 1;
		while (end >= 0 && s[end] == ' ') {
			end--;
		}
		if (end >= 0) {
			while (end >= 0 && s[end] != ' ') {
				end--;
				length++;
			}
			return length;
		}
		return 0;
	}
};

//回文数
//法1
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}
		int end_half = 0;
		while (x > end_half) {
			end_half = end_half * 10 + x % 10;
			x /= 10;
		}
		return x == end_half || x == end_half / 10;
	}
};
//法2
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}
		int div = 1;
		while (x / div >= 10) {
			div *= 10;
		}
		while (x > 0) {
			int left = x / div;
			int right = x % 10;
			if (left != right) {
				return false;
			}
			x = (x % div) / 10;
			div /= 100;
		}
		return true;
	}
};

//赎金信(第一个字符串是否能由第二个字符串中的字母组成)
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int arr[26] = { 0 };
		for (size_t i = 0; i < magazine.size(); i++) {
			arr[magazine[i] - 'a']++;
		}
		for (size_t i = 0; i < ransomNote.size(); i++) {
			arr[ransomNote[i] - 'a']--;
			if (arr[ransomNote[i] - 'a'] < 0) {
				return false;
			}
		}
		return true;
	}
};

//俩数之和
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> table;
		for(int i = 0; i < nums.size(); i++) {
			auto it = table.find(target - nums[i]);
			if(it != table.end()) {
				return {i, it->second};
			}
			table[nums[i]] = i;
		}
		return {};
	}
};

//移除元素
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			while (i < size && nums[i] == val) {
				int tmp = nums[i];
				nums[i] = nums[size - 1];
				nums[size - 1] = tmp;
				size--;
			}
		}
		return size;
	}
};

//转换成小写字母
class Solution {
public:
	string toLowerCase(string str) {
		for (size_t i = 0; i < str.length(); i++) {
			if (isupper(str[i])) {
				str[i] = tolower(str[i]);
			}
		}
		return str;
	}
};

//养兔子
int main()
{
	int n;
	while (cin >> n) {
		vector<long long> fib(n);
		fib[0] = 1;
		fib[1] = 2;
		for (int i = 2; i < n; i++) {
			fib[i] = fib[i - 1] + fib[i - 2];
		}
		cout << fib[n - 1] << endl;
	}
	return 0;
}

//收件人列表
int main()
{
	int n;
	while(cin >> n) {
		cin.get(); //处理回车
		vector<string> name;
		for (int i = 0; i < n; i++) {
			getline(cin, name[i]);
		}
		for(int i = 0; i < n; i++) {
			if(i != 0) {
				cout << ", ";
			}
			if((name[i].find(' ') != string::npos) || (name[i].find(',') != string::npos)) {
				cout << "\"" << name[i] << "\"";
			}
			else {
				cout << name[i];
			}
			if (i == n - 1) {
				cout << endl;
			}
		}
	}
	return 0;
}

//客似云来
int main()
{
	int from, to;
	vector<long long> fib(81, 0);
	fib[1] = 1;
	fib[2] = 1;
	for (size_t i = 3; i < fib.size(); i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	while (cin >> from >> to) {
		long long count = 0;
		for (int i = from; i <= to; i++) {
			count += fib[i];
		}
		cout << count << endl;
	}
	return 0;
}

//剪花布条
int main()
{
	string s, t;
	while (cin >> s >> t) {
		int s_len = s.length();
		int t_len = t.length();
		int cnt = 0;
		int pos = 0;
		int new_pos = 0;
		while (1) {
			if ((pos = s.find(t, new_pos)) != string::npos) {
				cnt++;
				new_pos = pos + t_len;
			}
			else {
				break;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

//斐波那契凤尾
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

//淘宝网店
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

//美国节日
int getDayOfWeek(int year, int mouth, int cnt, int _week, bool flag)
{
	if (mouth == 1 || mouth == 2) {
		mouth += 12;
		year--;
	}
	int day, week, i = 0;
	for (day = flag ? 1 : 31; day <= flag ? 31 : 1; flag ? (day++) : (day--)) {
		//flag：正数/倒数    
		week = (day + 2 * mouth + 3 * (mouth + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;//基姆拉尔森公式
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

//分解因数
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

//质因子个数
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

//最难的问题
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

//有假币
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

//求正数数组的最小不可组成和
class Solution {
public:
	/**
	*	正数数组中的最小不可组成和
	*	输入：正数数组arr
	*	返回：正数数组中的最小不可组成和
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

//将arr调整成奇数位上都是奇数或者偶数位上都是偶数
class Solution {
public:
	/**
	*  奇数位上都是奇数或者偶数位上都是偶数
	*  输入：数组arr，长度大于2
	*  len：arr的长度
	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
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

//猴子分桃
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

//不用加减乘除做加法
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

//三角形
bool IsTriangle(double a, double b, double c)
{
	if (a + b <= c || a + c <= b || b + c <= a) {
		return false;
	}
	return true;
}

//快到碗里来
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

//变态青蛙跳台阶
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

//星际密码
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

//数根
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

//迷宫问题
int row, col;
vector<vector<int>> maze;
vector<vector<int>> tmp; //当前路径
vector<vector<int>> best; //最短路径

void Track(int i, int j)
{
	maze[i][j] = 1; //表示已走过
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
	maze[i][j] = 0; //回溯
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

//小易的升级之路
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

//找出字符串中第一个只出现一次的字符
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

//洗牌
vector<int> XiPai(vector <int> v, int n)
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i<n; i++)
		v1.push_back(v[i]);     //左手中的牌
	for (int i = n; i<2 * n; i++)
		v2.push_back(v[i]);      //右手中的牌
	for (int i = 0; i<n; i++)
	{
		v[i * 2] = v1[i];   //洗一次牌后左手牌的新位置
		v[i * 2 + 1] = v2[i];    //洗一次牌后右手牌的新位置
	}
	return v;
}

int main()
{
	int T, n, k;
	cin >> T;
	while (T--)    //T组数据
	{
		vector<int> v;    
		cin >> n >> k;
		for (int i = 0; i < 2 * n; i++)
		{
			int a = 0;
			cin >> a;
			v.push_back(a);    //用数组存储牌号
		}
		while (k--)     //洗k次牌
			v = XiPai(v, n);

		for (int i = 0; i < 2 * n - 1; i++) {
			cout << v[i] << " ";
		}
		cout << v[2 * n - 1] << endl;   //每组数据后要换行
	}

	return 0;
}

//最长公共子串的长度
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

//字符串反转
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

//查找俩个子串中的最长公共子串
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

//喝汽水问题
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

//最长回文子串
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

//巴什博弈问题
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

//三数之和
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

//整数反转
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