#include <iostream>
#include <vector>
#include "Tree.h"


int main() {
	Tree tree;
	tree.addNode(15);
	tree.addNode(5);
	tree.addNode(16);
	tree.addNode(3);
	tree.addNode(12);
	tree.addNode(10);
	tree.addNode(13);
	tree.addNode(6);
	tree.addNode(7);
	tree.addNode(20);
	tree.addNode(18);
	tree.printAll(1);
	tree.removeNode(5);
	return 0;
}