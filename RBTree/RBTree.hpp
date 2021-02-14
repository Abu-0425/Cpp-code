#pragma once

#include <iostream>
using namespace std;

enum Color{ 
	RED, 
	BLACK 
};

// ������ڵ�Ķ���
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


// ���裺�������ֵ��Ψһ��
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
		head->parent = nullptr;  // �������û���κνڵ�
	}

	~RBTree()
	{
		Destroy(GetRoot());
		delete head;
		head = nullptr;
	}

	bool Insert(const T& data)
	{
		// 1. ���ն����������Ĺ�������½ڵ�
		Node*& root = GetRoot();   // ע�⣺root����head->parent�ı���

		// ����
		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			root->parent = head;
			head->left = root;
			head->right = root;
			return true;
		}

		// �Ҵ�����ڵ��ں����(����������)�е�λ��
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

		// �����½ڵ�
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;

		cur->parent = parent;

		// �½ڵ�Ĭ����ɫ�Ǻ�ɫ��
		// 2. ����Ƿ�Υ������3������²���ڵ�����˫�׽ڵ����ɫ�Ƿ�Ϊ��ɫ
		while (parent != head && RED == parent->color)
		{
			// Υ������3��cur �� parent�����ڵ����ɫ���Ǻ�ɫ��
			// ....
			// Ϊʲô�˴����游�ڵ㲻��Ҫ�пգ�
			// parent!=head ˵��parentһ�������е���Ч�ڵ�
			// RED == parent->color ˵��parentһ�����Ǹ��ڵ㣬˵��parent��˫��һ���Ǵ��ڵ�
			// grandFatherһ����Ϊ��
			Node* grandFather = parent->parent;
			if (parent == grandFather->left)
			{
				// �μ��и������һ��������
				Node* uncle = grandFather->right;
				if (uncle && RED == uncle->color)
				{
					// ���һ������ڵ������Ϊ��
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// ����ڵ㲻���� || ����ڵ������Ϊ��ɫ--->������������
					if (cur == parent->right)
					{
						// �����
						RotateLeft(parent);
						std::swap(parent, cur);
					}

					// �����
					grandFather->color = RED;
					parent->color = BLACK;
					RotateRight(grandFather);
				}
			}
			else
			{
				// �μ������һ�����ķ����:˫�����游���Ҳ�
				Node* uncle = grandFather->left;
				if (uncle && RED == uncle->color)
				{
					// �μ������һ�ķ����
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// �������������ķ����
					if (cur == parent->left)
					{
						// ������ķ����
						RotateRight(parent);
						std::swap(parent, cur);
					}

					// ������ķ����
					parent->color = BLACK;
					grandFather->color = RED;
					RotateLeft(grandFather);
				}
			}
		}


		// �½ڵ����֮�󣬺�ɫ���е���������С�ڵ㷢���仯
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
		// ����Ҳ�Ǻ����
		Node* root = GetRoot();
		if (nullptr == root)
			return true;

		// ���ǿ�---��Ҫ�ú����������
		if (BLACK != root->color)
		{
			cout << "Υ������2�����ڵ㲻�Ǻ�ɫ��" << endl;
			return false;
		}

		// ����3��û������һ��ĺ�ɫ�ڵ�
		// ����4��ÿ��·���к�ɫ�ڵ�ĸ�����ͬ��
		// ���Է���һ�������м��
		// ����֤����4ʱ����Ҫ������ÿ��·���к�ɫ�ڵ�ĸ�����Ȼ����֤��ɫ�ڵ�ĸ����Ƿ����
		// �ڸù����У����õ����еĽڵ㣬��������ǲ��ú���˫�ױ�ʾ������ʾ�ģ����Ҳ�����õ��ýڵ�
		// ��˫�ף�˳��ͽ�����3�����

		// ����4���ԭ��
		// 1. �������һ��·���к�ɫ�ڵ�ĸ���----��������������·���к�ɫ�ڵ�ĸ���blackCount
		// 2. ���������·���к�ɫ�ڵ�ĸ�����������Ƿ����һ������ĺ�ɫ�ڵ�����Ƿ���ͬ
		size_t blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (BLACK == cur->color)
				blackCount++;

			cur = cur->left;
		}

		size_t pathBlackCount = 0;   // �������浥��·���к�ɫ�ڵ�ĸ���
		return _IsValidRBTree(root, pathBlackCount, blackCount);
	}

private:
	bool _IsValidRBTree(Node* root, size_t pathBlackCount, const size_t blackCount)
	{
		if (nullptr == root)
			return true;

		// ˵����һ��·�����ҵ���һ����ɫ�ڵ�
		if (BLACK == root->color)
		{
			pathBlackCount++;
		}

		Node* parent = root->parent;
		// parent != head : ˵��rootһ�����Ǻ�����ĸ��ڵ㣬parentһ���Ǻ�����е���Ч�ڵ�
		if (parent != head && RED == parent->color && RED == root->color)
		{
			cout << "Υ������3����������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		// root��һ��Ҷ�ӽڵ�---һ��·���Ѿ��ߵ�ͷ��
		if (nullptr == root->left && nullptr == root->right)
		{
			if (pathBlackCount != blackCount)
			{
				cout << "Υ������4��·���к�ɫ�ڵ�ĸ�����ͬ��" << endl;
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
		// ע�⣺�ҵ�֧
		if (subRL)
			subRL->parent = parent;

		subR->left = parent;

		// ����subR��parent��˫��
		Node* pparent = parent->parent;
		parent->parent = subR;
		subR->parent = pparent;

		// ��Ҫ������ת֮��parent˫�׵����
		if (pparent == head)
		{
			// ��ת֮ǰparent�Ǹ��ڵ�
			head->parent = subR;
		}
		else
		{
			// ��ת֮ǰparent����˫�׵�
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

		// �޸�parent��subL�ĺ���
		parent->left = subLR;

		// ע�⣺��֧
		if (subLR)
			subLR->parent = parent;

		subL->right = parent;

		// �޸�parent��subL��˫��
		Node* pparent = parent->parent;
		parent->parent = subL;
		subL->parent = pparent;

		// ����ԭparent��˫��
		if (pparent == head)
		{
			// ˵����ת֮ǰparentһ���Ǹ��ڵ�
			head->parent = subL;
		}
		else
		{
			// ˵����ת֮ǰparent��˫��һ���Ǵ��ڵ�
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
	Node* head;    // ָ�������е�ͷ�ڵ�
};


void TestRBTree()
{
	int array[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int> t;
	for (auto e : array)
		t.Insert(e);

	// ��֤�������ȷ�ԣ�
	// 1. �Ƿ�Ϊ������������-->�����������Ƿ�Ϊ��������
	t.InOrder();
	cout << endl;

	// 2. ��֤���������--
	if (t.IsValidRBTree())
	{
		cout << "t is a RBTree!!!" << endl;
	}
	else
	{
		cout << "t is not a RBTree!!!" << endl;
	}
}