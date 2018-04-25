/*
 * Author: Kairui Song
 * Date: 2018-03-15
 * First attemp use sliding window
 * turns out gap between each data is too big for sliding window
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

#define INF std::numeric_limits<int>::max()

void hacks() {
	std::cout.sync_with_stdio(false);
}

void clean() {
	std::cin >> std::ws;
}

int main(int argc, char *argv[]) {
	hacks();

	const int N_MAX = 10000000;
	const int V_MAX = 1000000000;
	const int T_MAX = 1000000000;

	int N, offset = 0, next_offset = 0;

	std::array<int, N_MAX> volumes, tempers;

	std::list<int> piles;

	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		std::cin >> volumes[i];
	}

	for (int i = 0; i < N; ++i) {
		std::cin >> tempers[i];
	}

	auto old_it = piles.begin();
	for (int i = 0; i < N; ++i) {
		int today_v = volumes[i], today_t = tempers[i], today_m = 0;
		next_offset = offset + today_t;
		while (piles.size() > 0 && piles.front() < next_offset) {
			today_m += piles.front() - offset;
			piles.pop_front();
		}
		if (piles.size() == 0) {
			offset = 0;
			next_offset = today_t;
		}
		if (today_v <= today_t) {
			today_m += today_v;
			today_v = 0;
		} else {
			today_v += offset;
			while (old_it != piles.begin() && *old_it > today_v) {
				old_it --;
			}
			while (old_it != piles.end() && *old_it < today_v) {
				old_it ++;
			}
			if (old_it != piles.end()) {
				piles.insert(old_it, today_v);
				old_it--;
			} else {
				piles.push_back(today_v);
			}
		}
		today_m += today_t * piles.size();
		offset = next_offset;
		std::cout << today_m << std::endl;
	}

	return 0;
}
