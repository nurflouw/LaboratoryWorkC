#include "tree.h"
int test() {
	TNode* node = NULL;

	if (node != NULL) {
		return 1;
	}

	node = node_create(2);
	if (node == NULL) {
		return 2;
	}

	add_node(node, 7);
	add_node(node, 9);

	if (node->descend[0] == NULL) {
		return 3;
	}

	if (node->descender[1] == NULL) {
		return 4;
	}

	if (node->descender[2] != NULL) {
		return 4;
	}

	return 0;
}


int main() {

	return test();
}
