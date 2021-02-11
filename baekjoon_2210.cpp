#include <iostream>
#include <set>

using namespace std;

int board[5][5];

int drow[4] = { 0,0,1,-1 };
int dcol[4] = { 1,-1,0,0 };

set<int> check;


void search(int row, int col, int depth, int num) {

	if (depth >= 6) {

		check.insert(num);

		return;
	}

	for (int k = 0; k < 4; k++) {
		int nrow = row + drow[k];
		int ncol = col + dcol[k];

		if (nrow < 0 || nrow >= 5 || ncol < 0 || ncol >= 5) continue;
		search(nrow, ncol, depth + 1, num * 10 + board[nrow][ncol]);
	}
}

int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			search(i, j, 0, 0);
		}
	}

	cout << check.size() << '\n';
	return 0;
}