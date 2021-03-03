#include <stdio.h>
#include <malloc.h>

typedef struct NODE{
	NODE *child[2];
}NODE;

NODE* new_node() {
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->child[0] = NULL;
	node->child[1] = NULL;
	return node;
}

int main() {
	int n;
	scanf("%d", &n);
	
	int num;

	NODE* root = new_node();

	int max = 0;

	while (n--) {
		scanf("%d", &num);

		// add node
		NODE* node = root;
		for (int index = 1 << 29; index; index = index >> 1) {
			int child_index = !!(index & num);
			if (node->child[child_index] == NULL) {
				node->child[child_index] = new_node();
			}
			node = node->child[child_index];
		}

		// query
		int res = 0;
		node = root;
		for (int index = 1 << 29; index; index = index >> 1) {
			int child_index = !!(index & num);

			res = res << 1;
			if (node->child[1 - child_index] != NULL) {
				res += 1;
				node = node->child[1 - child_index];

			}
			else {
				node = node->child[child_index];

			}
		}


		if (max < res) max = res;
	}

	printf("%d\n", max);
}