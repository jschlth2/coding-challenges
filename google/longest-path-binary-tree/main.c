

#include <stdio.h>

int START      	= 0;
int INCREASING 	= 1;
int DECREASING 	= 2;

typedef struct node {

	struct node* parent;
	struct node* left;
	struct node* right;

	int val;

} node;

int longestPathFromTree(node* node);

int longestPath(node* node, int order);

int main() {


	// but wait, there is probably a better way...

	return 1;

}

int longestPathFromTree(node* node) {

	if(node == NULL) return -1;

	int curr_path = longestPath(node, START);

	if(node->left == NULL && node->right == NULL) {
		return curr_path;
	} else if(node->left == NULL) {
		int next_path = longestPathFromTree(node->right);
		return next_path > curr_path ? next_path : curr_path;
	} else if(node->right == NULL) {
		int next_path = longestPathFromTree(node->left);
		return next_path > curr_path ? next_path : curr_path;
	} else {
		int r_path = longestPathFromTree(node->right);
		int l_path = longestPathFromTree(node->left);
		int t_max = r_path > l_path ? r_path : l_path;
		return t_max > curr_path ? t_max : curr_path;
	}

	// won't reach
	return -1;

}

int longestPath(node* node, int order) {

	if(node == NULL) return -1;

	// TODO but straightforward

	return 0;

}
