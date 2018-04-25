/*
 * Author: Kairui Song
 * Date: 2018-04-13
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

std::array<std::array<char, 50>, 50> dp;

int solve(int ing1, int pkg1, int ing2, int pkg2) {
}

int main(int argc, char *argv[]) {
	hacks();

	int T,count=0;

	for(std::cin >> T; count < T; count++){
		int N, P;
		for (auto i : dp) {
			i.fill(0);
		}
		std::array<std::array<char, 50>, 50> pkgs;
		std::array<char, 50> rcps;
		std::cin >> N >> P;
		for (int i = 0; i < N; ++i) {
			std::cin >> rcps[i];
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < P; j++) {
				std::cin >> pkgs[i][j];
			}
			std::cin >> rcps[i];
		}


		std::cout << "Case #" << count + 1 << ": " << " " << std::endl;
	}

	return 0;
}

