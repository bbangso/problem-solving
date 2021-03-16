#include <stdio.h>
#include <map>

using namespace std;

int n;
int k;

int input[200001];

map<int, int> m;

int main() {
	scanf("%d %d", &n, &k);
	
	m[0] = 1;
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
		input[i] += input[i - 1];
		
		cnt += m[input[i] - k];
		m[input[i]] += 1;
	}

	printf("%lld\n", cnt);
}