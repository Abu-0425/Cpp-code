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
	int _bf;    // 表示该节点的平衡因子
};


// 假设：AVL树中的值是唯一的
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
		// 1. 按照二叉搜索树的规则插入新节点
		if (nullptr == _root)
		{
			_root = new Node(data);
			return true;
		}

		// 找待插入节点在二叉搜索树中的位置---并要保存其双亲
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

		// 插入新节点
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;

		cur->parent = parent;

		// 2. 新节点插入后，一定会对双亲节点的平衡性遭到影响
		// 需要调整parent的平衡因子
		while (parent)
		{
			if (cur == parent->left)  // parent右子树高度没有变，而左子树高度增加了一层
				parent->_bf--;
			else
				parent->_bf++;

			if (0 == parent->_bf)
				break;
			else if (-1 == parent->_bf || 1 == parent->_bf)
			{
				// 在插入cur之前parent是叶子
				// 以parent为根的子树的高度增加了一层---需要继续往上更新
				cur = parent;
				parent = cur->parent;
			}
			else
			{
				// parent的平衡因子2 || -2
				// 对parent为根的二叉树进行旋转处理

				// 发现：
				if (2 == parent->_bf)
				{
					if (1 == cur->_bf)
					{
						// 左单旋
						RotateLeft(parent);
					}
					else
					{
						RotateRL(parent);
					}
				}
				else
				{
					//parent的平衡因子为-2
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

	// 二叉树后序遍历规则
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
		// 避免左单支的场景：subLR是nullptr
		if (subLR)
			subLR->parent = parent;

		subL->right = parent;

		// 因为parent可能是某个节点的子树，因此在更新parent的双亲前必须先将其之前的双亲记录
		Node* pparent = parent->parent;
		parent->parent = subL;
		subL->parent = pparent;

		// parent可能是根节点：需要修改_root
		// parent也可能是一棵子树: 需要修改pparent的左/右指针域的指向
		if (nullptr == pparent)
		{
			// 旋转之前parent是根节点
			_root = subL;
		}
		else
		{
			// parent是某个节点的子树
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
		// 避免：右单支
		if (subRL)
			subRL->parent = parent;

		subR->left = parent;

		// 需要更新parent和subR的双亲
		Node* pparent = parent->parent;
		parent->parent = subR;
		subR->parent = pparent;

		// 旋转之前：
		// parent可能是根节点：修改_root的指向
		// parent可能是子树：修改原parent左||右指针域的指向
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

		// 将parent和subR的平衡因子更新为0
		parent->_bf = subR->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		// 旋转之前必须要保存subLR, 因为旋转完成之后需要根据subLR之前平衡因的情况来跟新旋转完成后
		// 部分节点的平衡因子
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
		// 空树也是AVL树
		if (nullptr == root)
			return true;

		// 计算root根节点的平衡因子是否正确
		int leftHeight = _Height(root->left);
		int rightHegiht = _Height(root->right);
		int bf = rightHegiht - leftHeight;
		if (abs(bf) > 1 || bf != root->_bf)
		{
			cout << root->data << " 节点的平衡因子有问题" << endl;
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