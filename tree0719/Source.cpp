#include <iostream>
#include <vector>
#include "Tree.h"


int main() {
	Tree tree;
	tree.addNode(4);
	tree.addNode(2);
	tree.addNode(5);
	tree.addNode(1);
	tree.addNode(3);
	tree.printAll(1);
	tree.removeNode(3);
	return 0;
}