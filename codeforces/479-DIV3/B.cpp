/*
 * Author: Kairui Song
 * Date: 2018-05-06
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

#define SET_PERCISION(x) std::cout << std::fixed << std::setprecision(x)
#define INF std::numeric_limits<int>::max()
#define PI M_PI

void hacks() {
	std::cout.sync_with_stdio(false);
}

void clean() {
	std::cin >> std::ws;
}

int main(int argc, char *argv[]) {
	hacks();
	const int alphaMax = 26 + 1;
	std::array<std::array<int, alphaMax>, alphaMax> map;
	std::array<char, 100 + 1> string;
	int n;

	std::cin >> n;
	for (auto &i : map) {
		i.fill(0);
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> string[i];
		string[i] -= 'A';
	}
	for (int i = 0; i < n - 1; ++i) {
		map[string[i]][string[i + 1]] ++;
	}

	int maxA = -1, maxB = -1;
	int maxS = 0;

	for (int i = 0; i < alphaMax; ++i) {
		for (int j = 0; j < alphaMax; j++) {
			if(map[i][j] > maxS){
				maxS = map[i][j];
				maxA = i;
				maxB = j;
			}
		}
	}

	std::cout << (char) (maxA + 'A') << (char) (maxB + 'A') << std::endl;

	return 0;
}
