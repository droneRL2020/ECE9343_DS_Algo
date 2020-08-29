#include "Tree.h"
#include <vector>


Tree::Tree()
	:m_root(nullptr)
{}

Tree::~Tree()
{}

void Tree::addNode(int value)
{
	m_root = insert(m_root, value);
}


Tree::TreeNode* Tree::newNode(int value)
{
	TreeNode* node = new TreeNode();
	node->data = value;
	node->left = nullptr;
	node->right = nullptr;
	node->height = 1;
	return node;
}


Tree::TreeNode* Tree::insert(TreeNode* node, int value)
{
	/* 1. Perform normal BST insertion*/
	if (node == nullptr)
	{
	    //m_root = new TreeNode();
		return newNode(value);
	}
	if (value < node->data)
	{
		node->left = insert(node->left, value);
	}
	else if (value > node->data)
	{
		node->right = insert(node->right, value);
	}
	else
	{
		return node;
	}
	
	/* 2. Update height of ancestor */
	node->height = 1 + max(height(node->left), height(node->right));

	/* 3. Get balance factor */
	int balance = getBalance(node);
	//Left Left Case
	if (balance > 1 && value < node->left->data)
	{
		return rightRotate(node);
	}
	//Right Right Case  
	if (balance < -1 && value > node->right->data)
	{
		return leftRotate(node);
	}
	// Left Right Case
	if (balance > 1 && value > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	// Right Left Case
	if (balance < -1 && value < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

int Tree::height(TreeNode* N)
{
	if (N == nullptr)
		return 0;
	else
	{
		return N->height;
	}
}

int Tree::max(int a, int b)
{
    return (a > b) ? a : b; 
}

int Tree::getBalance(TreeNode* N)
{
	if (N == nullptr)
		return 0;
	else
	{
		return height(N->left) - height(N->right);
	}
}

Tree::TreeNode* Tree::leftRotate(TreeNode* y)
{
	TreeNode* x = y->right;
	TreeNode* T2 = x->left;

	// Perform rotation  
	x->left = y;
	y->right = T2;

	// Update heights  
	y->height = max(height(y->right), height(y->left)) + 1;
	x->height = max(height(x->right), height(x->left)) + 1;
	return x;
}

Tree::TreeNode* Tree::rightRotate(TreeNode* y)
{
	TreeNode* x = y->left;
	TreeNode* T2 = x->right;

	// Perform rotation  
	x->right = y;
	y->left = T2;

	// Update heights  
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}


void Tree::printInorder(TreeNode*& node) const
{
	// Need to think how to finish sub problem
	// left root right
	if (node == nullptr)
	{
		return;
	}
	else
	{
		printInorder(node->left);
		std::cout << node->data << std::endl;
		printInorder(node->right);
	}
}

void Tree::printPreorder(TreeNode*& node) const
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		std::cout << node->data << std::endl;
		printPreorder(node->left);
		printPreorder(node->right);
	}
}

void Tree::printPostorder(TreeNode*& node) const
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		printPreorder(node->left);
		printPreorder(node->right);
		std::cout << node->data << std::endl;
	}
}

void Tree::printAll(int mode)
{
	// mode: 0=inorder, 1=preorder, 2=postorder
	if (mode == 0)
	{
		// ? what do you think about copying m_root
		TreeNode* node = m_root;
		printInorder(node);
	}
	else if (mode == 1)
	{
		TreeNode* node = m_root;
		printPreorder(node);
	}
	else if (mode == 2)
	{
		TreeNode* node = m_root;
		printPostorder(node);
	}

}



void Tree::removeLeaves(TreeNode*& parent, TreeNode*& child, const int value, int flag) const
{
	if (value == child->data)
	{
		if ((child->left == nullptr) and (child->right == nullptr))
		{
			// zero child delete
			delete child;
			child = nullptr;
		}
		else if ((child->left != nullptr) and (child->right != nullptr))
		{
			// two child delete
			// 1. find minimum sub_child(y) in right subtree of deleting value
			TreeNode* sub_child = child->right;
			//TreeNode* sub_parent = child->right;
			TreeNode* sub_parent = new TreeNode();
			while (sub_child->left != nullptr)
			{
				sub_parent = sub_child;
				sub_child = sub_child->left;
				//sub_parent = sub_parent->left;
			}
			// 2. if sub_child(y) has no children zero child delete
			if ((sub_child->left == nullptr) and (sub_child->right == nullptr))
			{
				child->data = sub_child->data;
				delete sub_child;
				sub_child = nullptr;
			}
			// 3. if sub_child(y) has right child
			if (sub_child->right != nullptr)
			{
				child->data = sub_child->data;
				TreeNode* temp = sub_child->right;
				delete sub_child;
				sub_child = nullptr;
				sub_parent->left = temp;
			}
		}
		else if ((child->left != nullptr))
		{
			//one left child delete
			if (flag == 1)
			{
				TreeNode* temp = child->left;
				delete child;
				child = nullptr;
				parent->right = temp;
			}
			if (flag == 0)
			{
				TreeNode* temp = child->left;
				delete child;
				child = nullptr;
				parent->left = temp;
			}
		}
		else
		{
			//one right child delete
			if (flag == 1)
			{
				TreeNode* temp = child->right;
				delete child;
				child = nullptr;
				parent->right = temp;
			}
			if (flag == 0)
			{
				TreeNode* temp = child->right;
				delete child;
				child = nullptr;
				parent->left = temp;
			}
		}
	}
	else if (value > child->data)
	{
		flag = 1;
		removeLeaves(child, child->right, value, flag);
	}
	else
	{
		flag = 0;
		removeLeaves(child, child->left, value, flag);
	}

}

void Tree::removeNode(int value)
{
	if (m_root->data == value)
	{
		// m_root has the value --> delete tree
	}
	else if (m_root->data < value)
	{
		// second node data is larger than value
		int flag = -1; // initial value
		removeLeaves(m_root, m_root->right, value, flag);
	}
	else
	{
		// second node data is smaller than value
		int flag = -1; // initial value
		removeLeaves(m_root, m_root->left, value, flag);
	}
}