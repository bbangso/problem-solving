#include <stdio.h>
#include <vector>

using namespace std;

int n, m;
vector<int> child[100001];

int ancestor[100001][17];

int tin[100001];
int tout[100001];
int cnt;
int anc_len;

void dfs(int node, int parent) {
	tin[node] = ++cnt;
	ancestor[node][0] = parent;

	for (int i = 1; i <= anc_len; i++) {
		ancestor[node][i] = ancestor[ancestor[node][i - 1]][i - 1];
	}
	
	for (int i = 0; i < child[node].size(); i++) {
		int next = child[node][i];
		if (tin[next]) continue;
		dfs(next, node);
	}
	tout[node] = ++cnt;
}

bool upper(int n1, int n2) {
	if (tin[n1] <= tin[n2] && tout[n1] >= tout[n2]) return true;
	return false;
}

int lca(int n1, int n2) {
	if (upper(n1, n2)) return n1;
	if (upper(n2, n1)) return n2;
	
	for (int i = anc_len; i >= 0; i--) {
		if (!upper(ancestor[n1][i], n2)) {
			n1 = ancestor[n1][i];
		}
	}

	return ancestor[n1][0];
}

int main() {
	scanf("%d", &n);
	cnt = 0;
	int n1, n2;
	for (int i = 1; i <= n - 1; i++) {
		scanf("%d %d", &n1, &n2);
		child[n1].push_back(n2);
		child[n2].push_back(n1);
	}


	for (anc_len = 1; (1 << anc_len) <= n; anc_len++);
	dfs(1, 1);

	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &n1, &n2);
		printf("%d\n", lca(n1, n2));
	}
}