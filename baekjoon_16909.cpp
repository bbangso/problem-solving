#include <iostream>
#include <set>
#include <string>

using namespace std;

typedef struct NODE {
	int num;
	NODE* left;
	NODE* right;
};

void insert(NODE* root, int num) {
	while (1) {
		if (root->num > num) {
			if (root->left) {
				root = root->left;
			}
			else {
				NODE* node = new NODE;
				node->num = num;
				node->left = NULL;
				node->right = NULL;
				root->left = node;
				break;
			}
		}
		else {
			if (root->right) {
				root = root->right;
			}
			else {
				NODE* node = new NODE;
				node->num = num;
				node->left = NULL;
				node->right = NULL;
				root->right = node;
				break;
			}
		}
	}
}

string find_shape(NODE * root) {
	string shape;
	shape += 'V';

	if (root->left) {
		shape += 'L';
		shape += find_shape(root->left);
		shape += 'l';
	}

	if (root->right) {
		shape += 'R';
		shape += find_shape(root->right);
		shape += 'r';
	}
	shape += 'v';

	return shape;
}

void remove(NODE* root) {
	if (root->left) {
		remove(root->left);
	}
	if (root->right) {
		remove(root->right);
	}
	delete root;
}

int main() {
	int n, k;
	cin >> n >> k;

	NODE* root;
	set<string> shape;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		// node init
		root = new NODE;
		root->num = num;
		root->left = NULL;
		root->right = NULL;

		for (int j = 1; j < k; j++) {
			cin >> num;
			insert(root, num);
		}

		shape.insert(find_shape(root));

		remove(root);
	}

	cout << shape.size() << '\n';
}