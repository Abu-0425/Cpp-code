#pragma once

#include <iostream>
using namespace std;

enum Color{ 
	RED, 
	BLACK 
};

// 红黑树节点的定义
template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& x = T(), Color c = RED)
	: left(nullptr)
	, right(nullptr)
	, parent(nullptr)
	, data(x)
	, color(c)
	{}

	RBTreeNode<T>* left;
	RBTreeNode<T>* right;
	RBTreeNode<T>* parent;
	T data;
	Color color;
};


// 假设：红黑树中值是唯一的
template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		head = new Node();
		head->left = head;
		head->right = head;
		head->parent = nullptr;  // 红黑树中没有任何节点
	}

	~RBTree()
	{
		Destroy(GetRoot());
		delete head;
		head = nullptr;
	}

	bool Insert(const T& data)
	{
		// 1. 按照二叉搜索树的规则插入新节点
		Node*& root = GetRoot();   // 注意：root就是head->parent的别名

		// 空树
		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			root->parent = head;
			head->left = root;
			head->right = root;
			return true;
		}

		// 找待插入节点在红黑树(二叉搜索树)中的位置
		Node* cur = root;
		Node* parent = head;
		while (cur)
		{
			parent = cur;
			if (data < cur->data)
				cur = cur->left;
			else if (data > cur->data)
				cur = cur->right;
			else
				return false;
		}

		// 插入新节点
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;

		cur->parent = parent;

		// 新节点默认颜色是红色的
		// 2. 检测是否违反性质3：检测新插入节点与其双亲节点的颜色是否都为红色
		while (parent != head && RED == parent->color)
		{
			// 违反性质3：cur 和 parent两个节点的颜色都是红色的
			// ....
			// 为什么此处的祖父节点不需要判空？
			// parent!=head 说明parent一定是树中的有效节点
			// RED == parent->color 说明parent一定不是根节点，说明parent的双亲一定是存在的
			// grandFather一定不为空
			Node* grandFather = parent->parent;
			if (parent == grandFather->left)
			{
				// 课件中给的情况一、二、三
				Node* uncle = grandFather->right;
				if (uncle && RED == uncle->color)
				{
					// 情况一：叔叔节点存在且为红
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// 叔叔节点不存在 || 叔叔节点存在且为黑色--->情况二和情况三
					if (cur == parent->right)
					{
						// 情况三
						RotateLeft(parent);
						std::swap(parent, cur);
					}

					// 情况二
					grandFather->color = RED;
					parent->color = BLACK;
					RotateRight(grandFather);
				}
			}
			else
			{
				// 课件中情况一二三的反情况:双亲在祖父的右侧
				Node* uncle = grandFather->left;
				if (uncle && RED == uncle->color)
				{
					// 课件中情况一的反情况
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// 情况二和情况三的反情况
					if (cur == parent->left)
					{
						// 情况三的反情况
						RotateRight(parent);
						std::swap(parent, cur);
					}

					// 情况二的反情况
					parent->color = BLACK;
					grandFather->color = RED;
					RotateLeft(grandFather);
				}
			}
		}


		// 新节点插入之后，红色树中的最大或者最小节点发生变化
		root->color = BLACK;
		head->left = LeftMost();
		head->right = RightMost();
		return true;
	}

	void InOrder()
	{
		InOrder(GetRoot());
	}

	bool IsValidRBTree()
	{
		// 空树也是红黑树
		Node* root = GetRoot();
		if (nullptr == root)
			return true;

		// 树非空---主要用红黑树的性质
		if (BLACK != root->color)
		{
			cout << "违反性质2：根节点不是黑色的" << endl;
			return false;
		}

		// 性质3：没有连在一起的红色节点
		// 性质4：每条路径中黑色节点的个数相同的
		// 可以放在一起来进行检测
		// 在验证性质4时，需要求红黑树每条路径中黑色节点的个数，然后验证黑色节点的个数是否相等
		// 在该过程中，会拿到所有的节点，而红黑树是采用孩子双亲表示法来表示的，因此也可以拿到该节点
		// 的双亲，顺便就将性质3检测了

		// 性质4检测原理：
		// 1. 任意求出一条路径中黑色节点的个数----简单起见：求最左侧路径中黑色节点的个数blackCount
		// 2. 在求出其他路径中黑色节点的个数，检测其是否与第一步求出的黑色节点个数是否相同
		size_t blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (BLACK == cur->color)
				blackCount++;

			cur = cur->left;
		}

		size_t pathBlackCount = 0;   // 用来保存单条路径中黑色节点的个数
		return _IsValidRBTree(root, pathBlackCount, blackCount);
	}

private:
	bool _IsValidRBTree(Node* root, size_t pathBlackCount, const size_t blackCount)
	{
		if (nullptr == root)
			return true;

		// 说明在一条路径中找到了一个黑色节点
		if (BLACK == root->color)
		{
			pathBlackCount++;
		}

		Node* parent = root->parent;
		// parent != head : 说明root一定不是红黑树的根节点，parent一定是红黑树中的有效节点
		if (parent != head && RED == parent->color && RED == root->color)
		{
			cout << "违反性质3：存在连在一起的红色节点" << endl;
			return false;
		}

		// root是一个叶子节点---一条路径已经走到头了
		if (nullptr == root->left && nullptr == root->right)
		{
			if (pathBlackCount != blackCount)
			{
				cout << "违反性质4：路径中黑色节点的个数不同的" << endl;
				return false;
			}
		}

		return _IsValidRBTree(root->left, pathBlackCount, blackCount) &&
			_IsValidRBTree(root->right, pathBlackCount, blackCount);
	}

	void RotateLeft(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;

		parent->right = subRL;
		// 注意：右单支
		if (subRL)
			subRL->parent = parent;

		subR->left = parent;

		// 更新subR和parent的双亲
		Node* pparent = parent->parent;
		parent->parent = subR;
		subR->parent = pparent;

		// 需要处理旋转之后parent双亲的情况
		if (pparent == head)
		{
			// 旋转之前parent是根节点
			head->parent = subR;
		}
		else
		{
			// 旋转之前parent是有双亲的
			if (parent == pparent->left)
				pparent->left = subR;
			else
				pparent->right = subR;
		}
	}

	void RotateRight(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;

		// 修改parent和subL的孩子
		parent->left = subLR;

		// 注意：左单支
		if (subLR)
			subLR->parent = parent;

		subL->right = parent;

		// 修改parent和subL的双亲
		Node* pparent = parent->parent;
		parent->parent = subL;
		subL->parent = pparent;

		// 处理：原parent的双亲
		if (pparent == head)
		{
			// 说明旋转之前parent一定是根节点
			head->parent = subL;
		}
		else
		{
			// 说明旋转之前parent的双亲一定是存在的
			if (parent == pparent->left)
				pparent->left = subL;
			else
				pparent->right = subL;
		}
	}

	Node*& GetRoot()
	{
		return head->parent;
	}

	Node* LeftMost()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return head;

		Node* cur = root;
		while (cur->left)
			cur = cur->left;

		return cur;
	}

	Node* RightMost()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return head;

		Node* cur = root;
		while (cur->right)
			cur = cur->right;

		return cur;
	}

	void InOrder(Node* root)
	{
		if (root)
		{
			InOrder(root->left);
			cout << root->data << " ";
			InOrder(root->right);
		}
	}

	void Destroy(Node* & root)
	{
		if (root)
		{
			Destroy(root->left);
			Destroy(root->right);
			delete root;
			root = nullptr;
		}
	}

private:
	Node* head;    // 指向红黑树中的头节点
};


void TestRBTree()
{
	int array[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int> t;
	for (auto e : array)
		t.Insert(e);

	// 验证红黑树正确性：
	// 1. 是否为二叉树搜索树-->检测中序遍历是否为有序序列
	t.InOrder();
	cout << endl;

	// 2. 验证红黑树性质--
	if (t.IsValidRBTree())
	{
		cout << "t is a RBTree!!!" << endl;
	}
	else
	{
		cout << "t is not a RBTree!!!" << endl;
	}
}