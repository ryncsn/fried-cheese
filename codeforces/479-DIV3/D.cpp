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

	std::array<unsigned long long, 100> numbers;
	std::bitset<100> used;
	std::list<unsigned long long> ordered;

	int n;

	std::cin >> n;
	used.reset();

	unsigned long long first;
	std::cin >> first;
	ordered.push_back(first);

	for (int i = 1; i < n; ++i) {
		std::cin >> numbers[i];
	}

	while (ordered.size() != n) {
		for (int i = 0; i < n; ++i) {
			if (used[i]) {
				continue;
			} else if (ordered.front() * 3 == numbers[i]) {
				ordered.push_front(numbers[i]);
				used[i] = true;
			} else if (ordered.front() == numbers[i] * 2) {
				ordered.push_front(numbers[i]);
				used[i] = true;
			} else if (numbers[i] == ordered.back() * 2) {
				ordered.push_back(numbers[i]);
				used[i] = true;
			} else if (numbers[i] * 3 == ordered.back()) {
				ordered.push_back(numbers[i]);
				used[i] = true;
			}
		}
	}

	for (auto i : ordered) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
