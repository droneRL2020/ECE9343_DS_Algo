#include <iostream>
#include <vector>
#include "Tree.h"


int main() {
	Tree tree;
	tree.addNode(3);
	tree.addNode(2);
	tree.addNode(1);
	tree.addNode(4);
	tree.addNode(5);
	tree.addNode(6);
	tree.addNode(7);
	tree.addNode(16);
	tree.addNode(15);
	tree.addNode(14);
	tree.printAll(1);
	tree.removeNode(5);
	return 0;
}