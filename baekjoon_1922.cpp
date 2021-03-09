#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct ADJ {
	int node;
	int weight;
	bool operator < (const ADJ& other) const {
		return weight > other.weight;
	}
};


int n, m;
vector<ADJ> adj_list[1001];
int visited[1001];

int main() {
	scanf("%d %d", &n, &m);

	int node1, node2, weight;
	while (m--) {
		scanf("%d %d %d", &node1, &node2, &weight);
		adj_list[node1].push_back({ node2, weight });
		adj_list[node2].push_back({ node1, weight });
	}

	priority_queue<ADJ> pq;

	visited[1] = 1;
	
	for (int i = 0; i < adj_list[1].size(); i++) {
		pq.push(adj_list[1][i]);
	}
	
	int sum = 0;
	while (!pq.empty()) {
		int node = pq.top().node;
		int weight = pq.top().weight; pq.pop();
		if (visited[node]) continue;
		visited[node] = 1;
		sum += weight;

		for (int i = 0; i < adj_list[node].size(); i++) {
			int next = adj_list[node][i].node;
			int nweight = adj_list[node][i].weight;
			
			if (visited[next]) continue;
			pq.push(adj_list[node][i]);
		}
	}

	printf("%d\n", sum);
}