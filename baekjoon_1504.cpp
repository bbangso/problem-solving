#include <stdio.h>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int n, m;

struct NODE{
	int node;
	int weight;
	bool operator < (const NODE &other) const {
		return weight > other.weight;
	}
};

vector<NODE> adj_list[801];
int dist[801];
int visited[801];

void find_dist(int start) {
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		visited[i] = 0;
	}
	dist[start] = 0;
	
	priority_queue<NODE> pq;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int node = pq.top().node; pq.pop();
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
}

int main() {
	scanf("%d %d", &n, &m);
	
	int n1, n2, w;
	while (m--) {
		scanf("%d %d %d", &n1, &n2, &w);
		adj_list[n1].push_back({ n2,w });
		adj_list[n2].push_back({ n1,w });
	}
	
	int node1, node2;
	scanf("%d %d", &node1, &node2);

	int path1 = 0;
	int path2 = 0;
	find_dist(node1);
	path1 = dist[1] + dist[node2];
	path2 = dist[node2] + dist[n];
	
	if (dist[1] == INF || dist[node2] == INF || dist[n] == INF) {
		path1 = -1;
	}

	if(path1 != -1){
		find_dist(node2);
		path1 += dist[n];
		path2 += dist[1];
	}
	
	printf("%d\n", path1 < path2 ? path1 : path2);
}