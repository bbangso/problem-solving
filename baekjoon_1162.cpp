#include <stdio.h>
#include <queue>
#include <vector>

long long INF = 1000000000LL * 50000LL;

using namespace std;

struct NODE {
	int node;
	int weight;
};

struct DIST {
	int node;
	long long dist;
	int n_pave;
	bool operator < (const DIST &other) const {
		return dist > other.dist;
	}
};

int n, m, k;

long long dist[21][10001];
vector<NODE> adj_list[10001];
int visited[21][10001];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	
	int n1, n2, w;
	while (m--) {
		scanf("%d %d %d", &n1, &n2, &w);
		adj_list[n1].push_back({ n2,w });
		adj_list[n2].push_back({ n1,w });
	}

	for (int i = 1; i <= n; i++) {
		for (int q = 0; q <= k; q++) {
			dist[q][i] = INF;
		}
	}

	
	dist[0][1] = 0;

	priority_queue<DIST> pq;
	pq.push({ 1, dist[0][1], 0 });
	
	while (!pq.empty()) {
		int node = pq.top().node;
		long long d = pq.top().dist;
		int n_pave = pq.top().n_pave; pq.pop();
		

		if (visited[n_pave][node]) continue;
		visited[n_pave][node] = 1;

		for (int i = 0; i < adj_list[node].size(); i++) {
			int next = adj_list[node][i].node;
			int weight = adj_list[node][i].weight;
			
			if (dist[n_pave][next] > dist[n_pave][node] + weight) {
				dist[n_pave][next] = dist[n_pave][node] + weight;
				pq.push({ next, dist[n_pave][next], n_pave });
			}

			if (n_pave < k && dist[n_pave + 1][next] > dist[n_pave][node]) {
				dist[n_pave + 1][next] = dist[n_pave][node];
				pq.push({ next, dist[n_pave+1][next], n_pave + 1 });
			}
		}
	}


	long long ans = INF;
	for (int q = 0; q <= k; q++) {
		if (dist[q][n] == INF) continue;
		if (ans > dist[q][n]) ans = dist[q][n];
	}

	printf("%lld\n", ans);
}