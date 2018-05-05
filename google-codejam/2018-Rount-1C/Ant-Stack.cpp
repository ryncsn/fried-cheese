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

const int N_MAX = 100000 + 1;
int N;

std::array<int, N_MAX> ants;
std::unordered_map<int, std::unordered_map<int, int>> memory;

int solve(int pos, int weightLeft) {
	int ans = memory[pos][weightLeft];
	if (ans == -1) {
		return 0;
	} else if (ans > 0) {
		return ans;
	} else {
		ans = -1;
		int value = 0;
		for (int i = pos + 1; i < N; ++i) {
			int newWeightLimit = ants[i] * 6;
			int newWeightLeft = weightLeft - ants[i];
			if (newWeightLeft >= 0) {
				int minWeightLeft = newWeightLimit < newWeightLeft ? newWeightLimit : newWeightLeft;
				value = 1 + solve(i, minWeightLeft);
				if (value > ans) {
					ans = value;
				}
			}
		}
		memory[pos][weightLeft] = ans;
		if (ans == -1) {
			return 0;
		}
		return ans;
	}
}

int main(int argc, char *argv[]) {
	hacks();

	int T, t_counter=0;

	for(std::cin >> T; t_counter < T; t_counter ++){
		ants.fill(0);
		memory.clear();

		std::cin >> N;
		for (int i = 1; i <= N; ++i) {
			std::cin >> ants[N - i];
		}

		int ans = 0;
		for (int i = 0; i < N; ++i) {
			int value = 1 + solve(i, ants[i] * 6);
			if (value > ans) {
				ans = value;
			}
		}
		std::cout << "Case #" << t_counter + 1 << ": " << ans << std::endl;
	}

	return 0;
}

