#include <stdio.h>

int n, m;

int input[100000];
int tree[1 << 18 ];

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

void make_tree(int node, int start, int end) {
	if (start == end) {
		tree[node] = input[start];
	}
	else {
		make_tree(node << 1, start, (start + end) >> 1);
		make_tree((node << 1) + 1, ((start + end) >> 1) + 1, end);
		tree[node] = min(tree[node << 1], tree[(node << 1) + 1]);
	}
}

int search(int node, int start, int end, int com1, int com2) {
	if (com2 < start || com1 > end) return -1;
	if (com1 <= start && com2 >= end) return tree[node];
	
	int value1 = search(node << 1, start, (start+ end) >> 1, com1, com2);
	int value2 = search((node << 1) + 1, ((start + end) >> 1) + 1,end, com1, com2);

	if (value1 == -1) {
		return value2;
	}
	else if (value2 == -1) {
		return value1;
	}
	else
		return min(value1, value2);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}


	make_tree(1, 0, n - 1);


	int com1, com2;
	while (m--) {
		scanf("%d %d", &com1, &com2);
		printf("%d\n", search(1, 0, n - 1, com1-1, com2-1));
	}

	return 0;
}