/*
 * Author: Kairui Song
 * Date: 2018-03-13
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

void four_way_merge() {
	return;
}

int main(int argc, char *argv[]) {
	hacks();

	int m, n;
	const int BLOCK_SIZE = 100;
	const int N_MAX = 100000;

	std::array<int, N_MAX> buffer;
	std::array<std::array<int, BLOCK_SIZE>, (N_MAX / BLOCK_SIZE) + 1> blocks;
	std::array<int, N_MAX> arr;

	std::cin >> n >> m;

	int block_count = 0;

	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];

		int offset = n % BLOCK_SIZE;

		if (n % BLOCK_SIZE == 0 || i + 1 == n) {
			std::copy(
					arr.cbegin() + (block_count * BLOCK_SIZE),
					arr.cbegin() + ((block_count + 1) * BLOCK_SIZE),
					(blocks.begin() + block_count)->begin());
			std::sort(
					(blocks.begin() + block_count)->begin(),
					(blocks.begin() + block_count)->begin() + (offset ? offset: BLOCK_SIZE)
					);
			block_count ++;
		}
	}

	for (int i = 0; i < m; ++i) {
		int l, r, k;
		std::cin >> l >> r >> k;
	}

	return 0;
}
