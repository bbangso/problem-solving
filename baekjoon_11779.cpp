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

vector<NODE> adj_list[1001];
int visited[1001];
int dist[1001];
int path[1001];

void print_path(int node, int cnt) {
	if (path[node] == 0) {
		printf("%d\n", cnt+1);
		printf("%d ", node);
		return;
	}
	print_path(path[node], cnt+1);
	printf("%d ", node);
}

int main() {
	scanf("%d %d", &n, &m);

	int n1, n2, w;

	while (m--) {
		scanf("%d %d %d", &n1, &n2, &w);
		adj_list[n1].push_back({ n2,w });
	}

	int start, end;
	scanf("%d %d", &start, &end);

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


		if (node == end) break;

		for (int i = 0; i < adj_list[node].size(); i++) {
			int next = adj_list[node][i].node;
			int weight = adj_list[node][i].weight;

			if (visited[next]) continue;
			if (dist[next] > dist[node] + weight) {
				dist[next] = dist[node] + weight;
				pq.push({ next, dist[next] });
				path[next] = node;
			}
		}
	}

	printf("%d\n", dist[end]);
	print_path(end, 0);
}