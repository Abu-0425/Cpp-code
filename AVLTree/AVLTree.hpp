#pragma once

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& x = T())
	: left(nullptr)
	, right(nullptr)
	, parent(nullptr)
	, data(x)
	, _bf(0)
	{}

	AVLTreeNode<T>* left;
	AVLTreeNode<T>* right;
	AVLTreeNode<T>* parent;
	T data;
	int _bf;    // ��ʾ�ýڵ��ƽ������
};


// ���裺AVL���е�ֵ��Ψһ��
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _root(nullptr)
	{}

	~AVLTree()
	{
		Destroy(_root);
	}

	bool Insert(const T& data)
	{
		// 1. ���ն����������Ĺ�������½ڵ�
		if (nullptr == _root)
		{
			_root = new Node(data);
			return true;
		}

		// �Ҵ�����ڵ��ڶ����������е�λ��---��Ҫ������˫��
		Node* cur = _root;
		Node* parent = nullptr;
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

		// 2. �½ڵ�����һ�����˫�׽ڵ��ƽ�����⵽Ӱ��
		// ��Ҫ����parent��ƽ������
		while (parent)
		{
			if (cur == parent->left)  // parent�������߶�û�б䣬���������߶�������һ��
				parent->_bf--;
			else
				parent->_bf++;

			if (0 == parent->_bf)
				break;
			else if (-1 == parent->_bf || 1 == parent->_bf)
			{
				// �ڲ���cur֮ǰparent��Ҷ��
				// ��parentΪ���������ĸ߶�������һ��---��Ҫ�������ϸ���
				cur = parent;
				parent = cur->parent;
			}
			else
			{
				// parent��ƽ������2 || -2
				// ��parentΪ���Ķ�����������ת����

				// ���֣�
				if (2 == parent->_bf)
				{
					if (1 == cur->_bf)
					{
						// ����
						RotateLeft(parent);
					}
					else
					{
						RotateRL(parent);
					}
				}
				else
				{
					//parent��ƽ������Ϊ-2
					if (-1 == cur->_bf)
					{
						RotateRight(parent);
					}
					else
					{
						RotateLR(parent);
					}
				}

				break;
			}
		}

		return true;
	}

	void InOrder()
	{
		InOrder(_root);
		cout << endl;
	}

	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}

private:
	void InOrder(Node* root)
	{
		if (root)
		{
			InOrder(root->left);
			cout << root->data << " ";
			InOrder(root->right);
		}
	}

	// �����������������
	void Destroy(Node*& root)
	{
		if (root)
		{
			Destroy(root->left);
			Destroy(root->right);
			delete root;
			root = nullptr;
		}
	}

	void RotateRight(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;

		parent->left = subLR;
		// ������֧�ĳ�����subLR��nullptr
		if (subLR)
			subLR->parent = parent;

		subL->right = parent;

		// ��Ϊparent������ĳ���ڵ������������ڸ���parent��˫��ǰ�����Ƚ���֮ǰ��˫�׼�¼
		Node* pparent = parent->parent;
		parent->parent = subL;
		subL->parent = pparent;

		// parent�����Ǹ��ڵ㣺��Ҫ�޸�_root
		// parentҲ������һ������: ��Ҫ�޸�pparent����/��ָ�����ָ��
		if (nullptr == pparent)
		{
			// ��ת֮ǰparent�Ǹ��ڵ�
			_root = subL;
		}
		else
		{
			// parent��ĳ���ڵ������
			if (parent == pparent->left)
				pparent->left = subL;
			else
				pparent->right = subL;
		}

		parent->_bf = subL->_bf = 0;
	}


	void RotateLeft(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;

		parent->right = subRL;
		// ���⣺�ҵ�֧
		if (subRL)
			subRL->parent = parent;

		subR->left = parent;

		// ��Ҫ����parent��subR��˫��
		Node* pparent = parent->parent;
		parent->parent = subR;
		subR->parent = pparent;

		// ��ת֮ǰ��
		// parent�����Ǹ��ڵ㣺�޸�_root��ָ��
		// parent�������������޸�ԭparent��||��ָ�����ָ��
		if (nullptr == pparent)
		{
			_root = subR;
		}
		else
		{
			if (parent == pparent->left)
				pparent->left = subR;
			else
				pparent->right = subR;
		}

		// ��parent��subR��ƽ�����Ӹ���Ϊ0
		parent->_bf = subR->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		// ��ת֮ǰ����Ҫ����subLR, ��Ϊ��ת���֮����Ҫ����subLR֮ǰƽ����������������ת��ɺ�
		// ���ֽڵ��ƽ������
		Node* subL = parent->left;
		Node* subLR = subL->right;
		int bf = subLR->_bf;

		RotateLeft(parent->left);
		RotateRight(parent->right);
		RotateRight(parent);

		if (1 == bf)
			subL->_bf = -1;
		else if (-1 == bf)
			parent->_bf = 1;
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;
		int bf = subRL->_bf;

		RotateRight(parent->right);
		RotateLeft(parent);

		if (1 == bf)
			parent->_bf = -1;
		else if (-1 == bf)
			subR->_bf = 1;
	}

	int _Height(Node* root)
	{
		if (nullptr == root)
			return 0;

		int leftHeight = _Height(root->left);
		int rightHegiht = _Height(root->right);
		return leftHeight > rightHegiht ? leftHeight + 1 : rightHegiht + 1;
	}

	bool _IsBalanceTree(Node* root)
	{
		// ����Ҳ��AVL��
		if (nullptr == root)
			return true;

		// ����root���ڵ��ƽ�������Ƿ���ȷ
		int leftHeight = _Height(root->left);
		int rightHegiht = _Height(root->right);
		int bf = rightHegiht - leftHeight;
		if (abs(bf) > 1 || bf != root->_bf)
		{
			cout << root->data << " �ڵ��ƽ������������" << endl;
			return false;
		}

		return _IsBalanceTree(root->left) && _IsBalanceTree(root->right);
	}

private:
	AVLTreeNode<T>* _root;
};


#include <iostream>
using namespace std;

void TestAVLTree()
{
	//int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int array[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	AVLTree<int> t;
	for (auto e : array)
		t.Insert(e);

	t.InOrder();

	if (t.IsBalanceTree())
	{
		cout << "t is a AVL tree!!!" << endl;
	}
	else
	{
		cout << "t is not a AVL tree!!!" << endl;
	}
}