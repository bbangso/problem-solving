#include <stdio.h>
#include <vector>

using namespace std;

vector<int> adj_list[32000];

int check[32000];

void search(int node) {
	check[node] = 1;
	for (int i = 0; i < adj_list[node].size(); i++) {
		int next = adj_list[node][i];
		if (check[next]) continue;
		search(next);
	}
	printf("%d ", node+1);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int std1, std2;

	while (m--) {
		scanf("%d %d", &std1, &std2);
		std1--; std2--;
		adj_list[std2].push_back(std1);
	}

	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		search(i);
	}

	return 0;
}