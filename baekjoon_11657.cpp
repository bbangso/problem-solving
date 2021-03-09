#include <stdio.h>
#define INF 987654321

int n,m;
int dist[501];
int edge[6000][3];

int main() {
	scanf("%d %d", &n, &m);

	// init dist
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	int n1, n2, weight;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &n1, &n2, &weight);
		edge[i][0] = n1;
		edge[i][1] = n2;
		edge[i][2] = weight;
	}

	dist[1] = 0;
	int is_negative = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int from = edge[j][0];
			int to = edge[j][1];
			int weight = edge[j][2];

			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + weight) {
				dist[to] = dist[from] + weight;
				if (i == n) {
					is_negative = 1;
				}
			}
		}
	}

	if (is_negative) {
		printf("%d\n", -1);
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF) dist[i] = -1;
			printf("%d\n", dist[i]);
		}
	}
	return 0;
}