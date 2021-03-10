#include <stdio.h>
#define INF 987654321

int dist[101][101];
int n, m;



int main() {
	scanf("%d %d", &n, &m);

	int n1, n2, w;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
			if (i == j) dist[i][j] = 0;
		}
	}

	while (m--) {
		scanf("%d %d %d", &n1, &n2, &w);
		dist[n1][n2] = w;
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) dist[i][j] = 0;
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
}