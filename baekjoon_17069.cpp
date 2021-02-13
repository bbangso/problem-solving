#include <stdio.h>

int n;
int map[33][33];

long long memo[3][33][33];



int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	memo[0][1][2] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (i == 1 && j == 2) continue;
			if (map[i][j] == 0) {
				memo[0][i][j] = memo[0][i][j - 1] + memo[1][i][j - 1];
				memo[2][i][j] = memo[1][i - 1][j] + memo[2][i - 1][j];
				
				if(map[i-1][j] ==0 && map[i][j-1] == 0)
					memo[1][i][j] = memo[0][i - 1][j - 1] + memo[1][i - 1][j - 1] + memo[2][i - 1][j - 1];
			
			}
		}
	}

	printf("%lld\n", memo[0][n][n] + memo[1][n][n] + memo[2][n][n]);
	return 0;
}