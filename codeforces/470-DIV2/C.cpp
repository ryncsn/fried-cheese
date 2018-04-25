/*
 * Author: Kairui Song
 * Date: 2018-03-15
 */
#include <iostream>
#include <algorithm>
#include <array>
#include <bitset>
#include <set>
#include <cstring>
#include <forward_list>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

#define INF std::numeric_limits<int>::max()

void hacks() {
	std::cout.sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void clean() {
	std::cin >> std::ws;
}

int main(int argc, char *argv[]) {
	hacks();
	const int N_MAX = 1000008;

	long long N, today_v = 0, temp = 0, offset = 0, next_offset = 0;
	std::multiset<long long> piles;
	std::array<long long, N_MAX> volumes;

	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> volumes[i];
	}
	for (int i = 0; i < N; ++i) {
		std::cin >> temp;
		next_offset = offset + temp;
		today_v = 0;
		piles.insert(volumes[i] + offset);
		for (auto it = piles.begin(); it != piles.end() && *it <= next_offset;) {
			today_v += *it - offset;
			it = piles.erase(it);
		}
		today_v += temp * piles.size();
		offset = next_offset;
		std::cout << today_v << " ";
	}
	std::cout << std::endl;
	return 0;
}
