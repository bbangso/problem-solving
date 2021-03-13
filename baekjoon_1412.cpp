#include <stdio.h>

int adj_mat[100][100];
char temp[100][101];

int n;
int inf = 987654321;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", temp[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			adj_mat[i][j] = inf;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (temp[i][j] == 'Y' && temp[j][i] == 'N') {
				adj_mat[i][j] = 1;
			}
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (adj_mat[i][j] > adj_mat[i][k] + adj_mat[k][j]) {
					adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (adj_mat[i][i] != inf) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}