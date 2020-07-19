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



void Tree::removeNode(int value)
{
	// inorder traversal and if find value remove node and 
}
