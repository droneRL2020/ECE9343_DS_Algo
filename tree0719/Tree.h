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
		int height;
	};
	TreeNode* m_root;

private:
	Tree::TreeNode* insert(TreeNode* node, int value);
	Tree::TreeNode* newNode(int value);
	
	
	int height(TreeNode* N);
	int max(int a, int b);
	int getBalance(TreeNode* N);
	Tree::TreeNode* leftRotate(TreeNode* y);
	Tree::TreeNode* rightRotate(TreeNode* y);

	void printInorder(TreeNode*& m_root) const;
	void printPreorder(TreeNode*& m_root) const;
	void printPostorder(TreeNode*& m_root) const;
	
	void removeLeaves(TreeNode*& parent, TreeNode*& child, const int value, int flag) const;
};

