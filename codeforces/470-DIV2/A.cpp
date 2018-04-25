/*
 * Author: Kairui Song
 * Date: 2018-03-10
 */
#include <iostream>
#include <algorithm>
#include <array>
#include <bitset>
#include <cstring>
#include <forward_list>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace::std;

#define INF numeric_limits<int>::max()
#define len(x) x.size()

void hacks() {
	cout.sync_with_stdio(false);
}

void clean() {
	cin >> ws;
}

int main(int argc, char *argv[]) {
	hacks();

	int R, C;

	char table[500][500];

	char cell;

	char failed = false;

	cin >> R >> C;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> cell;
			if (cell == '.') {
				table[i][j] = 'D';
			}
			else {
				table[i][j] = cell;
			}
			if (i > 0) {
				if (table[i][j] != table[i-1][j]) {
					if (table[i][j] != 'D' && table[i-1][j] != 'D') {
						failed = true;
					}
				}
			}
			if (j > 0) {
				if (table[i][j] != table[i][j-1]) {
					if (table[i][j] != 'D' && table[i][j-1] != 'D') {
						failed = true;
					}
				}
			}
		}
	}

	if (!failed) {
		cout << "Yes" << endl;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cout << table[i][j];
			}
			cout << endl;
		}
	} else {
		cout << "No" << endl;
	}

	return 0;
}
