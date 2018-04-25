/*
 * Author: Kairui Song
 * Date: 2018-04-14
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

#define SET_PERCISION(x) std::cout << std::fixed << std::setprecision(x);
#define INF std::numeric_limits<int>::max()
#define PI M_PI

void hacks() {
	std::cout.sync_with_stdio(false);
}

void clean() {
	std::cin >> std::ws;
}

struct casher {
	int M;
	int S;
	int P;
} cashiers[1000];

int main(int argc, char *argv[]) {
	hacks();

	int T, t_counter=0;

	for(std::cin >> T; t_counter < T; t_counter ++){
		int R, B, C;
		std::cin >> R >> B >> C;
		for (int i = 0; i < C; ++i) {
			std::cin >> cashiers[i].M;
			std::cin >> cashiers[i].S;
			std::cin >> cashiers[i].P;
		}

		std::cout << "Case #" << t_counter + 1 << ": " << " " << std::endl;
	}

	return 0;
}

