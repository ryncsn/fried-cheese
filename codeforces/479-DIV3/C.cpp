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

	const int N_MAX = 2 * 100000;
	const int K_MAX = N_MAX;

	int n, k;

	std::cin >> n >> k;

	std::array<long, N_MAX> numbers;

	long max = 1000000000, min = 1, x;

	for (int i = 0; i < n; ++i) {
		std::cin >> numbers[i];
	}

	int distance;
	std::sort(numbers.begin(), numbers.begin() + n);

	do {
		x = (max + min) / 2;
		distance = std::upper_bound(numbers.cbegin(), numbers.cbegin() + n, x) - numbers.begin();
		if (distance == k) {
			break;
		} else if (min == max) {
			x = -1;
			break;
		} else if (distance > k) {
			max = x;
		} else if (distance < k) {
			min = x + 1;
		}
	} while (true);

	std::cout << x << std::endl;

	return 0;
}
