#include <stdio.h>
#define INF 987654321

int dist[401][401];

int n, m;

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}

	int n1, n2, w;

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

	int min = INF;
	for (int i = 1; i <= n; i++) {
		if (min > dist[i][i]) {
			min = dist[i][i];
		}
	}

	if (min == INF) min = -1;

	printf("%d\n", min);
}