#include <stdio.h>

int parent[1000001];

int find(int com) {
	if (com == parent[com]) {
		return com;
	}
	else {
		int root = find(parent[com]);
		parent[com] = root;
		return root;
	}
}

void join(int com1, int com2) {
	int parent1 = find(com1);
	int parent2 = find(com2);
	
	parent[parent2] = parent1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	int op;
	int com1, com2;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	while (m--) {
		scanf("%d %d %d", &op, &com1, &com2);

		if (op == 0) {
			join(com1, com2);
		}
		else {
			if (find(com1) == find(com2)) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
		}
	}
}