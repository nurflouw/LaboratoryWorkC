#include "tree.h"
#define MARKER -1


TNode* node_create(int key) {

	TNode* node = (TNode*)malloc(sizeof(TNode));
	node->key = key;
	for (int i = 0; i < N; i++) {
		node->descender[i] = NULL;
	}
	return node;
};


TNode* add_node(TNode* root, int key) {

	TNode* node = (TNode*)malloc(sizeof(TNode));
	node->key = key;
	int i = 0;
	while (root->descender[i] != NULL && i < N) {
		i++;
	}
	if (root->descender[i] == NULL) {
		root->descender[i] = node;
		return root;
	}
	else if ( root->descender[i] != NULL && i > N) {
		return NULL;
	}
}

int tree_from_file(TNode* root, FILE* fp) {
	int val;
	if (!scanf(fp, " % d", &val) || val == MARKER) {
		return 1;
	}
	root = node_create(val);
	for (int i = 0; i < N; i++) {
		if (tree_from_file(root->descender[i], fp))
			break;
	}
	return 0;
}