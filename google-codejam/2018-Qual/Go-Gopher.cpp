/*
 * Author: Kairui Song
 * Date: 2018-04-07
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

#define INF std::numeric_limits<int>::max()

#define MAX_N = 1000;

void hacks() {
	std::cout.sync_with_stdio(false);
}

void clean() {
	std::cin >> std::ws;
}

typedef std::array<std::array<bool, 20>, 20> Grid;

int main(int argc, char *argv[]) {
	// hacks();

	int T,count=0;
	int w = 1, h = 1;

	std::array<std::array<int, 20>, 20> mark;
	std::array<std::array<bool, 20>, 20> grid;

	for(std::cin >> T; count < T; count++){

		for (int i = 0; i < 20; ++i) {
			grid[i].fill(false);
		}

		int A;
		std::cin >> A;

		while (w * h < A) {
			if (w == h) {
				w ++;
			} else {
				h = w;
			}
		}

		for (int i = 1; i < w - 1; ++i) {
			for (int j = 1; j < h - 1; ++j) {
				mark[i][j] = 9;
			}
		}

		int max_i, max_j, max_empty = INF;
		int i, j;

		while (max_empty) {
			max_empty = 0;
			for (i = 1; i < w - 1; ++i) {
				for (j = 1; j < h - 1; ++j) {
					if (mark[i][j] > max_empty) {
						max_empty = mark[i][j], max_i = i, max_j = j;
					}
				}
			}

			std::cout << max_i + 1 << " " << max_j + 1 << std::endl;
			std::cin >> i >> j;

			if (i == -1 && j == -1) {
				return 1;
			} else if (i == 0 && j == 0) {
				max_empty = 0;
			} else {
				i--, j--;
				if (grid[i][j] == true) {
					continue;
				}
				grid[i][j] = true;
				for (int ii = i - 1; ii <= i + 1; ++ii) {
					for (int jj = j - 1; jj <= j + 1; ++jj) {
						mark[ii][jj] --;
					}
				}
			}
		}
	}

	return 0;
}

