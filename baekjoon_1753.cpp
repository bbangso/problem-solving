#include <cstdio>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int n, m;

struct NODE {
	int node;
	int weight;
	bool operator < (const NODE& other) const {
		return weight > other.weight;
	}
};

vector<NODE> adj_list[20001];
int visited[20001];
int dist[20001];

int main() {
	scanf("%d %d", &n, &m);

	int n1, n2, w;

	int start;
	scanf("%d", &start);

	while (m--) {
		scanf("%d %d %d", &n1, &n2, &w);
		adj_list[n1].push_back({ n2,w });
	}


	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;

	priority_queue<NODE> pq;

	pq.push({ start, dist[start] });

	while (!pq.empty()) {
		int node = pq.top().node;  pq.pop();

		if (visited[node]) continue;
		visited[node] = 1;

		for (int i = 0; i < adj_list[node].size(); i++) {
			int next = adj_list[node][i].node;
			int weight = adj_list[node][i].weight;

			if (visited[next]) continue;
			if (dist[next] > dist[node] + weight) {
				dist[next] = dist[node] + weight;
				pq.push({ next, dist[next] });

			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}

	return 0;
}