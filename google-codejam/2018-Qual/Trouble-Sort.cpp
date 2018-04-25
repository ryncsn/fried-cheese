/*
 * Author: Kairui Song
 * Date: 2018-04-07
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

	int T,count=0;

	for(std::cin >> T; count < T; count++){
		int N, arr_len = 0, even_len = 0, odd_len = 0;
		std::array<int, 100001> odd, even, merged;
		std::cin >> N;

		for (arr_len = 0; arr_len < N; ++arr_len) {
			if (arr_len & 1) {  // odd
				std::cin >> odd[odd_len ++];
			} else {  // even
				std::cin >> even[even_len ++];
			}
		}

		std::sort(odd.begin(), odd.begin() + odd_len);
		std::sort(even.begin(), even.begin() + even_len);

		for (arr_len = 0, odd_len = 0, even_len = 0; arr_len < N; ++arr_len) {
			if (arr_len & 1) {  // odd
				merged[arr_len] = odd[odd_len ++];
			} else {  // even
				merged[arr_len] = even[even_len ++];
			}
		}

		std::cout << "Case #" << count + 1 << ": ";
		for (arr_len = 0, odd_len = 0, even_len = 0; arr_len < N - 1; ++arr_len) {
			if (merged[arr_len] > merged[arr_len + 1]) {
				std::cout << arr_len;
				break;
			}
		}

		if (arr_len == N - 1) {
			std::cout << "OK";
		}

		std::cout << std::endl;
	}

	return 0;
}

