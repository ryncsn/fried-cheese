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
	std::string a;

	std::cin >> a;

	if (a.size() > 2) {
		for (int i = 0; i < a.size() - 2; ++i) {
			if (
					a[i] != a[i+1] &&
					a[i+1] != a[i+2] &&
					a[i] != a[i+2] &&
					a[i] != '.' &&
					a[i+1] != '.' &&
					a[i+2] != '.'
			   ) {
				std::cout << "Yes" << std::endl;
				return 0;
			}
		}
	}
	std::cout << "No" << std::endl;
	return 0;
}
