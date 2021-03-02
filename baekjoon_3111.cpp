#include <stdio.h>
#include <string.h>

char word[26];
char text[300001];

char lstack[300001];
char rstack[300001];
int ltop;
int rtop;

int main() {
	scanf("%s %s", word, text);
	
	int n_word = strlen(word);
	int n_text = strlen(text);

	ltop = -1;
	rtop = -1;

	int lindex = 0;
	int rindex = n_text - 1;
	int mode = 0;


	while (lindex <= rindex) {
		if (mode == 0) {
			// push stack
			lstack[++ltop] = text[lindex];

			// compare
			if (ltop - n_word + 1 >= 0) {
				int isSame = 1;
				for (int i = 0; i < n_word; i++) {
					if (lstack[ltop - n_word + 1 + i] != word[i]) {
						isSame = 0;
						break;
					}
				}

				if (isSame) {
					ltop -= n_word;
					mode = 1;
				}
			}

			lindex += 1;
		}
		else {
			rstack[++rtop] = text[rindex];
			
			if (rtop - n_word + 1 >= 0) {
				int isSame = 1;
				for (int i = 0; i < n_word; i++) {
					if (rstack[rtop - i] != word[i]) {
						isSame = 0;
						break;
					}
				}

				if (isSame) {
					rtop -= n_word;
					mode = 0;
				}
			}

			rindex--;
		}
	}

	while (ltop != -1) {
		char c = lstack[ltop--]; //pop
		rstack[++rtop] = c;
		
		if (rtop - n_word + 1 >= 0) {
			int isSame = 1;
			for (int i = 0; i < n_word; i++) {
				if (rstack[rtop - i] != word[i]) {
					isSame = 0;
					break;
				}
			}

			if (isSame) {
				rtop -= n_word;
			}
		}
	}

	while (rtop != -1) {
		printf("%c", rstack[rtop--]);
	}
}