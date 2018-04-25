/*
 * Author: Kairui Song
 * Date: 2018-04-11
 */
#include <iomanip>
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
#include <cmath>

#define INF std::numeric_limits<int>::max()

void hacks() {
	std::cout.sync_with_stdio(false);
}

void clean() {
	std::cin >> std::ws;
}

std::array<std::array<char, 26>, 26> cake;

void fill(int y1, int y2, int x1, int x2, const char alpha) {
	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; j++) {
			cake[i][j] = alpha;
		}
	}
}

void h_partition(int y1, int y2, int x1, int x2) {
	char detected = '?';
	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; j++) {
			if (cake[i][j] != '?') {
				if(detected != '?') {
					fill(y1, y2, x1, j, detected);
					return h_partition(y1, y2, j, x2);
				}
				detected = cake[i][j];
			}
		}
		if (detected != '?') {
			return fill(y1, y2, x1, x2, detected);
		}
	}
}

void v_partition(int y1, int y2, int x1, int x2) {
	int counter = 0;
	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; j++) {
			if (cake[i][j] != '?') {
				counter ++;
				break;
			}
		}
		if (counter == 2) {
			h_partition(y1, i, x1, x2);
			return v_partition(i, y2, x1, x2);
		}
	}
	if (counter == 1) {
		return h_partition(y1, y2, x1, x2);
	}
}

int main(int argc, char *argv[]) {
	hacks();

	int T,counter=0;

	for(std::cin >> T; counter < T; counter ++){
		int R, C;
		std::cin >> R >> C;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; j++) {
				std::cin >> cake[i][j];
			}
		}
		v_partition(0, R, 0, C);
		std::cout << "Case #" << counter + 1 << ": " << std::endl;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; j++) {
				std::cout << cake[i][j];
			}
			std::cout << std::endl;
		}
	}
	return 0;
}

