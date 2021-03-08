#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int>> adj_list(10001);
vector<int> indegree(10001);
vector<int> time(10001);
vector<int> sum(10001);

int search() {
	queue<int> q;

	int max = 0;

	for (int i = 1; i < indegree.size(); i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int node = q.front(); q.pop();
		int total_time = sum[node] + time[node];

		if (max < total_time) max = total_time;
		for (int i = 0; i < adj_list[node].size(); i++){
			int next = adj_list[node][i];
			
			
			indegree[next] -= 1;

			if (sum[next] < total_time) sum[next] = total_time;
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	return max;
}

int main() {
	int n;
	scanf("%d", &n);

	adj_list.resize(n + 1);
	indegree.resize(n + 1);
	time.resize(n + 1);
	sum.resize(n + 1);
	
	int pre;
	int node;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &time[i], &pre);
		while (pre--) {
			scanf("%d", &node);
			indegree[i] += 1;
			adj_list[node].push_back(i);
		}
	}

	printf("%d\n", search());
}