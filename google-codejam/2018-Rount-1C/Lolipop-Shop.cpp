/*
 * Author: Kairui Song
 * Date: 2018-05-05
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
	int T, t_counter=0;
	const auto N_MAX = 200 + 1;
	const auto D_MAX = 200 + 1;

	std::array<int, N_MAX> likeCounter;
	std::array<int, N_MAX> choices;
	std::bitset<N_MAX> sold;

	for(std::cin >> T; t_counter < T; t_counter ++){
		likeCounter.fill(0);
		sold.reset();
		int N, D;

		std::cin >> N;

		for (int i = 0; i < N; ++i) {
			std::cin >> D;
			int minLikeCounter = INF, minLike = -1;
			for (int i = 0; i < D; ++i) {
				int choose;
				std::cin >> choose;
				choices[i] = choose;
				likeCounter[choose] ++;
				if(likeCounter[choose] < minLikeCounter && !sold[choose]) {
					minLikeCounter = likeCounter[choose];
					minLike = choose;
				}
			}
			if (minLike == -1) {
				std::cout << -1 << std::endl;
				continue;
			} else {
				std::cout << minLike << std::endl;
				sold[minLike] = true;
			}
		}
	}
	return 0;
}

