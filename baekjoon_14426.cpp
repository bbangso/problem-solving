#include <stdio.h>

char str[501];

typedef struct NODE {
	int is_valid;
	int child[26];
};

NODE trie[600];
int size;

int new_node() {
	trie[++size].is_valid = -1;
	for (int i = 0; i <= 26; i++) {
		trie[size].child[i] = -1;
	}
	return size;
}

int init() {
	size = -1;
	
	return new_node();
}

void push(int root, char* str) {

	int index = 0;
	while (str[index]) {
		int c = str[index] - 'a';
		if (trie[root].child[c] == -1) {
			int next = new_node();
			trie[root].child[c] = next;
		}
		root = trie[root].child[c];
		index++;
	}
}

int find(int root, char* str) {
	int index = 0;
	while (str[index]) {
		int c = str[index] - 'a';
		if (trie[root].child[c] == -1) {
			return 0;
		}
		root = trie[root].child[c];
		index++;
	}

	return 1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int root = init();

	while (n--) {
		scanf("%s", str);
		push(root, str);
	}

	int cnt = 0;
	while (m--) {
		scanf("%s", str);
		cnt += find(root, str);
	}

	printf("%d\n", cnt);
}