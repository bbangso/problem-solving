#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct EDGE {
	int from;
	int to;
	int weight;
	bool operator < (const EDGE& other) const {
		return weight < other.weight;
	}
};

int V, E;
vector<EDGE> edge;

int tree[10001];

int find(int node) {
	if (tree[node] == 0) return node;
	int parent =  find(tree[node]);
	tree[node] = parent;
	return parent;
}

void set(int from, int to) {
	tree[to] = from;
}

int main() {
	scanf("%d %d", &V, &E);

	int v1, v2, weight;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &v1, &v2, &weight);
		edge.push_back({ v1, v2, weight });
	}

	sort(edge.begin(), edge.end());
	
	int mst_value = 0;
	int edge_cnt = 0;

	for (int i = 0; i < edge.size(); i++) {
		int from = edge[i].from;
		int to = edge[i].to;
		int weight = edge[i].weight;
		
		int from_parent = find(from);
		int to_parent = find(to);
		if (from_parent != to_parent) {
			set(from_parent, to_parent);
			mst_value += weight;
			edge_cnt += 1;
		}
		if (edge_cnt == V - 1) break;
	}

	printf("%d\n", mst_value);
}