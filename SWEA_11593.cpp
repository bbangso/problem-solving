#include <stdio.h>

using namespace std;

char input[21];
long long fac[21];
int cnt_alpha[26];

void make_fac() {
	fac[1] = 1;

	for (int i = 2; i <= 20; i++) {
		fac[i] = fac[i - 1] * i;
	}
}


int main() {
	int T;
	scanf("%d", &T);

	make_fac();


	for (int tc = 1; tc <= T; tc++) {
		scanf("%s", input);
		
		int l = 0;
		for (int i = 0; i < 26; i++) {
			cnt_alpha[i] = 0;
		}

		for (l = 0; input[l]; l++) {
			cnt_alpha[input[l] - 'A'] += 1;
		}

		long long ans = 0;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < 26; j++) {
				if (cnt_alpha[j] > 0) {
					if (j+'A' < input[i]) {
						long long value = fac[l - 1 - i];

						cnt_alpha[j] -= 1;
						for (int k = 0; k < 26; k++) {
							if (cnt_alpha[k] > 0) {
								value = value / fac[cnt_alpha[k]];
							}
						}
						ans += value;
						cnt_alpha[j] += 1;
					}

					else {
						cnt_alpha[j] -= 1;
						break;
					}
				}
			}
		}

		printf("#%d %lld\n",tc, ans);
	}

	return 0;
}