/*
 * Author: Kairui Song
 * Date: 2018-06-11
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

	std::array<char, 2001> tide;
	std::array<bool, 2001> repeatings;

	tide.fill('\0');
	repeatings.fill(true);

	int n, p;

	std::cin >> n >> p;

	for (int i = 0; i < n; ++i) {
		std::cin >> tide[i];
	}

	if (n > p) {
		for (int i = 0; i < p; ++i) {
			int j = i;
			bool& repeating = repeatings[i];
			char& initial = tide[j];
			while (j + p < n) {
				j += p;
				if (tide[j] == '.') {
					if (initial == '.') {
						tide[j] = '0';
						initial = '1';
					} else {
						if (initial == '0') {
							tide[j] = '1';
						} else {
							tide[j] = '0';
						}
					}
					repeating = false;
				} else if (tide[j] != initial) {
					if (initial == '.') {
						if (tide[j] == '0') {
							initial = '1';
						} else {
							initial = '0';
						}
					}
					repeating = false;
				}
			}
			if (initial == '.') {
				initial = '0';
			}
		}
		for (int i = 0; i < p; ++i) {
			if (repeatings[i] == false) {
				for (int i = 0; i < n; ++i) {
					std::cout << tide[i];
				}
				std::cout << std::endl;
				return 0;
			}
		}
	}
	std::cout << "No" << std::endl;

	return 0;
}
