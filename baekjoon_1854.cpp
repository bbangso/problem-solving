#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct NODE{
	int to;
	int weight;
};

struct ITEM{
	long long dist;
	int node;
	bool operator < (const ITEM& other) const {
		return dist > other.dist;
	}
};

long long INF = 1LL << 60;

int k_th[1001];
vector<NODE> adj_list[1001];
int n, m, k;
long long dist[1001];

int main() {
	
	scanf("%d %d %d", &n, &m, &k);
	
	int n1, n2, w;
	while (m--) {
		scanf("%d %d %d", &n1, &n2, &w);
		adj_list[n1].push_back({ n2,w });
	}

	priority_queue<ITEM> pq;
	pq.push({ 0,1 });
	dist[1] = INF;

	while (!pq.empty()) {
		int node = pq.top().node;
		long long d = pq.top().dist; pq.pop();

		if (k_th[node] == k) continue;
		k_th[node] += 1;
		dist[node] = d;

		for (int i = 0; i < adj_list[node].size(); i++) {
			int next = adj_list[node][i].to;
			int weight = adj_list[node][i].weight;
			if (k_th[next] == k) continue;
			pq.push({dist[node] + (long long)weight, next });
		}
	}


	for (int i = 1; i <= n; i++) {

		if (k_th[i] != k) printf("-1\n");
		else printf("%lld\n", dist[i]);
	}

	return 0;
}