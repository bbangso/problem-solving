#include <cstdio>
#include <queue>
#include <vector>
#define INF 1987654321

using namespace std;

int n, m;

struct EDGE {
	int to;
	int weight;
	bool operator < (const EDGE& other) const {
		return weight > other.weight;
	}
};

int dist[1001];
int visited[1001];
vector<EDGE> adj_list[1001];

int main() {
	scanf("%d %d", &n, &m);
	
	int n1, n2, w;
	while (m--) {
		scanf("%d %d %d", &n1, &n2, &w);
		adj_list[n1].push_back({ n2,w });
	}

	int start, end;
	scanf("%d %d", &start, &end);

	priority_queue<EDGE> pq;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	pq.push({start, 0});


	while (!pq.empty()) {
		int node = pq.top().to;
		int weight = pq.top().weight; pq.pop();
		
		if (visited[node]) continue;
		visited[node] = 1;

		for (int i = 0; i < adj_list[node].size(); i++) {
			int next = adj_list[node][i].to;
			int nweight = adj_list[node][i].weight;

			if (visited[next]) continue;
			if (dist[next] > dist[node] + nweight) {
				dist[next] = dist[node] + nweight;
				pq.push({next, dist[next]});
			}
		}

	}


	printf("%d\n", dist[end]);

	return 0;
}