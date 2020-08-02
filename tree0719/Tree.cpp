#include "Tree.h"
#include <vector>

Tree::Tree()
	:m_root(nullptr)
{}

Tree::~Tree()
{}

void Tree::addNode(int value)
{
	std::vector<int> vec;
	if (m_root == nullptr) 
	{
		m_root = new TreeNode();
		m_root->left = nullptr;
		m_root->data = value;
		m_root->right = nullptr;
	}
	else {
		// Do with Recursion
		TreeNode* node = m_root;
		insert(node, value);
	}
}


void Tree::insert(TreeNode* &node, const int value) const
{
	//TODO : AVL Tree
	if (node == nullptr) 
	{
		node = new TreeNode();
		node->data = value;
		return;
	}
	else 
	{
		if(value >= node->data)
		{
			//m_root->right = node;
			insert(node->right, value);
		}
		else
		{
			insert(node->left, value);
		}
	}
}


void Tree::printInorder(TreeNode*& node)
{
	// Need to think how to finish sub problem
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

void Tree::printPreorder(TreeNode*& node)
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

void Tree::printPostorder(TreeNode*& node)
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


void Tree::removeLeaves(TreeNode*& parent, TreeNode*& child, const int value, int flag)
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
		else if((child->left != nullptr))
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
	else if(m_root->data < value)
	{
		// second node data is larger than value
		int flag=-1; // initial value
		removeLeaves(m_root, m_root->right, value, flag);
	}
	else
	{
		// second node data is smaller than value
		int flag = -1; // initial value
		removeLeaves(m_root, m_root->left, value, flag);
	}
}
