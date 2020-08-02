#pragma once
#include <vector>
#include <iostream>
class Tree
{

public:
	Tree();
	virtual ~Tree();
	void addNode(int value);
	void printAll(int mode); //0=inorder, 1=preorder, 2=postorder, #enum
	void removeNode(int value);  // member function


private:
	struct TreeNode {
		int data;
		TreeNode* left;
		TreeNode* right;
	};
	TreeNode* m_root;

private:
	void insert(TreeNode* &m_root, const int value) const;
	void printInorder(TreeNode*& m_root);
	void printPreorder(TreeNode*& m_root);
	void printPostorder(TreeNode*& m_root);
	void removeLeaves(TreeNode*& parent, TreeNode*& child, const int value, int flag);
};

