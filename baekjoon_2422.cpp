#include <stdio.h>
#include <set>

using namespace std;

int n, m;

int combi[201][201];

int main() {
	scanf("%d %d", &n, &m);
	int node1, node2;
	while (m--) {
		scanf("%d %d", &node1, &node2);
		combi[node1][node2] = 1;
		combi[node2][node1] = 1;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (combi[i][j]) continue;
			for (int k = j + 1; k <= n; k++) {
				if (combi[k][i] || combi[k][j]) continue;
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}