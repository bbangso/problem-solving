#include <stdio.h>

int m;
int f[200001][19];

int main() {
	scanf("%d", &m);
	
	for (int i = 1; i <= m; i++) {
		scanf("%d", &f[i][0]);
	}

	for (int j = 1; j < 19; j++) {
		for (int i = 1; i <= m; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}

	int n_q;
	scanf("%d", &n_q);

	int i, j;
	while (n_q--) {
		scanf("%d %d", &j, &i);

		int index = 0;
		while (j) {
			if (j & 1) {
				i = f[i][index];
			}
			j = j >> 1;
			index += 1;
		}

		printf("%d\n", i);
	}
}