#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int num;

	priority_queue<int, vector<int>, less<int>> lq;
	priority_queue<int, vector<int>, greater<int>> rq;

	while (n--) {
		scanf("%d", &num);
		
		if (lq.size() <= rq.size()) {
			if (!rq.empty() && num > rq.top()) {
				lq.push(rq.top()); rq.pop();
				rq.push(num);
			}
			else {
				lq.push(num);
			}
		}
		else {
			if (!lq.empty() && num < lq.top()) {
				rq.push(lq.top()); lq.pop();
				lq.push(num);
			}
			else {
				rq.push(num);
			}
		}

		printf("aaaa%d\n", lq.top());
	}


}