/*
 * Author: Kairui Song
 * Date: 2019-04-06
 */
#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <list>
#include <map>
#include <set>
#include <array>
#include <queue>
#include <vector>
#include <bitset>
#include <cstring>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>

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
	int test_case_n = 0, test_case_c = 0;

	for(std::cin >> test_case_n; test_case_c < test_case_n; test_case_c ++){
		int N;
		char lid_move;
		std::cin >> N;
		std::cout << "Case #" << test_case_c + 1 << ": ";
		for (int i = 0; i < (2 * N - 2); ++i) {
			std::cin >> lid_move;
			if (lid_move == 'S') {
				std::cout << 'E';
			} else {
				std::cout << 'S';
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
