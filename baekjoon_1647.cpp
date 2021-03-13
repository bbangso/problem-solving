#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

struct EDGE {
	int from;
	int to;
	int weight;
	bool operator < (const EDGE& other) const {
		return weight < other.weight;
	}
};

int parent[100001];

int find(int node) {
	if (parent[node] == 0) return node;
	
	parent[node] = find(parent[node]);
	return parent[node];
}

int main() {
	scanf("%d %d", &n, &m);
	
	vector<EDGE> edge(m);
	
	int from, to, weight;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &weight);
		edge[i] = { from, to ,weight };
	}

	sort(edge.begin(), edge.end());

	int total_cost = 0;
	int cnt = 0;

	for (int i = 0; i < m; i++) {
		int n1 = edge[i].from;
		int n2 = edge[i].to;
		int p1 = find(n1);
		int p2 = find(n2);
		if (p1 == p2) continue;
		parent[p1] = p2;
		
		
		
		total_cost += edge[i].weight;
		cnt += 1;
		if (cnt == n - 2) break;
	}

	printf("%d\n", total_cost);
}