#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

// 按摩师
class Solution {
public:
	int massage(vector<int>& nums) {
		int n = (int)nums.size();
		if (0 == n) {
			return 0;
		}
		if (1 == n) {
			return nums[0];
		}

		int dp0 = nums[0];
		int dp1 = max(nums[0], nums[1]);
		for (int i = 2; i < n; i++) {
			int d0 = max(dp0, dp1);
			int d1 = dp0 + nums[i];

			dp0 = d0;
			dp1 = d1;
		}
		return max(dp0, dp1);
	}
};

// T9键盘
class Solution {
public:
	vector<string> getValidT9Words(string num, vector<string>& words) {
		vector<char> map = { '2', '2', '2', '3', '3', '3', '4', '4', '4',
			'5', '5', '5', '6', '6', '6', '7', '7', '7',
			'7', '8', '8', '8', '9', '9', '9', '9' };
		vector<string> res;
		int n = num.size();
		for (auto &w : words) {
			for (int i = 0; i < n; i++) {
				if (map[w[i] - 'a'] != num[i]) {
					break;
				}
				if (i + 1 == n) {
					res.push_back(w);
				}
			}
		}
		return res;
	}
};

#if 0
//变位词组
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int n = strs.size();
		vector<vector<string>> res;
		unordered_map<string, vector<string>> u_map;
		for(int i = 0; i < n; i++) {
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			u_map[tmp].push_back(strs[i]);
		}
		auto it = u_map.begin();
		while(it != u_map.end()) {
			res.push_back(it->second);
			++it;
		}
		return res;
	}
};

//分割链表
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if(!head || !head->next) {
			return head;
		}
		ListNode *lessHead, *lessTail, *greaterHead, *greaterTail;
		lessHead = lessTail = new ListNode(-1);
		greaterHead = greaterTail = new ListNode(-1);
		ListNode *cur = head;
		while(cur) {
			if(cur->val < x) {
				lessTail->next = cur;
				lessTail = cur;
			}
			else {
				greaterTail->next = cur;
				greaterTail = cur;
			}
			cur = cur->next;
		}
		lessTail->next = greaterHead->next;
		greaterTail->next = nullptr;
		return lessHead->next;
	}
};

//合法二叉搜索树
//法一：递归
class Solution {
private:
	bool IsValidBST(TreeNode *t, long long lower, long long upper) {
		if (!t) {
			return true;
		}
		else if (t->val <= lower || t->val >= upper) {
			return false;
		}
		return IsValidBST(t->left, lower, t->val) && IsValidBST(t->right, t->val, upper);
	}
public:
	bool isValidBST(TreeNode* root) {
		return IsValidBST(root, LONG_MIN, LONG_MAX);
	}
};

//法二：中序遍历
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> st;
		long long pre = LONG_MIN;
		while (!st.empty() || root != nullptr) {
			while (root) {
				st.push(root);
				root = root->left;
			}
			root = st.top();
			st.pop();
			if (root->val <= pre) {
				return false;
			}
			pre = root->val;
			root = root->right;
		}
		return true;
	}
};

//环路检测
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if(!head || !head->next) {
			return nullptr;
		}
		ListNode *slow, *fast;
		slow = fast = head;
		while(fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast) {
				break;
			}
		}
		if(fast == nullptr || fast->next == nullptr) {
			return nullptr; //无环
		}
		slow = head;
		while(slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};

//蛋糕的最大数量
class Solution {
public:
	int maxIceCream(vector<int>& costs, int coins) {
		vector<int> table(100001);
		for (const int &cos : costs) {
			table[cos]++;
		}

		int cnt = 0;
		for (int i = 1; i <= 100000; i++) {
			if (coins >= i) {
				int curCnt = min(table[i], coins / i);
				cnt += curCnt;
				coins -= curCnt * i;
			}
			else {
				break;
			}
		}
		return cnt;
	}
};

//一次编辑
class Solution {
public:
	bool oneEditAway(string first, string second) {
		int len1 = first.size(), len2 = second.size();
		//长度差大于1
		if (abs(len1 - len2) > 1) {
			return false;
		}
		//长度差相等
		else if (len1 == len2) {
			int cnt = 0;
			for (int i = 0; i < len1; i++) {
				if (first[i] != second[i]) {
					cnt++;
				}
			}
			return cnt <= 1;
		}
		//长度差为1
		else {
			//使first为较短串
			if (len1 > len2) {
				swap(first, second);
			}
			int i = 0;
			for (; i < first.size(); i++) {
				if (first[i] != second[i]) {
					break;
				}
			}
			first.insert(first.begin() + i, second[i]);
		}
		return first == second;
	}
};

//螺旋矩阵2
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int curData = 1;
		vector<vector<int>> matrix(n, vector<int>(n));
		int left = 0, right = n - 1, top = 0, bottom = n - 1;
		while(left <= right && top <= bottom) {
			//上边的行
			for(int col = left; col <= right; col++) {
				matrix[top][col] = curData;
				curData++;
			}

			//右侧的列
			for(int row = top + 1; row <= bottom; row++) {
				matrix[row][right] = curData;
				curData++;
			}

			if(left < right && top < bottom) {
				//下边的行
				for(int col = right - 1; col > left; col--) {
					matrix[bottom][col] = curData;
					curData++;
				}

				//左侧的列
				for(int row = bottom; row > top; row--) {
					matrix[row][left] = curData;
					curData++;
				}
			}

			//更新边界
			left++;
			right--;
			top++;
			bottom--;
		}
		return matrix;
	}
};

//纯质数
bool isZhi(int n)
{
	if (n == 1 || n == 0) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

bool isChuZhi(int n)
{
	while (n) {
		if (!isZhi(n % 10)) {
			return false;
		}
		n /= 10;
	}
	return true;
}

int main()
{
	int cnt = 0;
	for (int i = 2; i < 20210605; i++) {
		if (isZhi(i) && isChuZhi(i)) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}

//二叉树中和为某一值的路径
class Solution {
private:
	vector<int> path;
	vector<vector<int>> ans;
	void dfs(TreeNode *cur, int target) {
		if(cur == nullptr) {
			return;
		}
		else {
			path.push_back(cur->val);
			target -= cur->val;
			if(target != 0 || cur->left != nullptr || cur->right != nullptr) {
				dfs(cur->left, target);
				dfs(cur->right, target);
			}
			else {
				ans.push_back(path);
			}
			path.pop_back();
		}
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		dfs(root, target);
		return ans;
	}
};

//删除链表倒数第k个节点
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *slow = head, *fast = head;
		ListNode *prev = nullptr;
		while(n--) {
			fast = fast->next;
		}
		while(fast) {
			fast = fast->next;
			prev = slow;
			slow = slow->next;
		}

		if(prev) {
			prev->next = slow->next;
			return head;
		}
		else {
			return slow->next;
		}
	}
};

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