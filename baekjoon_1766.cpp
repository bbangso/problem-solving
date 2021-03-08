#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void search(vector<int> &indegree, vector<vector<int>> &adj_list) {
	priority_queue<int, vector<int>, greater<int> > pq;
	
	for (int i = 1; i < indegree.size(); i++) {
		if (indegree[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int node = pq.top(); pq.pop();

		cout << node << ' ';
		
		for (int i = 0; i < adj_list[node].size(); i++) {
			int next = adj_list[node][i];
			indegree[next] -= 1;
			if (indegree[next] == 0) {
				pq.push(next);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> adj_list(n+1);
	vector<int> indegree(n+1);

	int  num1, num2;

	while (m--) {
		cin >> num1 >> num2;
		indegree[num2] += 1;
		adj_list[num1].push_back(num2);
	}

	search(indegree, adj_list);
}