#include <stdio.h>

int power(int A, int B, int C) {
	int ans = 1;

	while (B) {
		if (B & 1) {
			ans = (long long)ans * A % C;
		}
		A = (long long)A * A % C;
		B = B >> 1;
	}

	return ans;
}

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	printf("%d\n", power(A, B, C));
}