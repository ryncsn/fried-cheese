/*
 * Author: Kairui Song
 * Date: 2019-04-22
 */
#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <list>
#include <map>
#include <set>
#include <array>
#include <queue>
#include <vector>
#include <bitset>
#include <cstring>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>

#define SET_PERCISION(x) std::cout << std::fixed << std::setprecision(x)
#define INF std::numeric_limits<int>::max()
#define PI M_PI

#define GRID_MAX 100

std::array<std::array<char, GRID_MAX + 1>, GRID_MAX + 1> waffle;
std::array<std::array<int, GRID_MAX + 1>, GRID_MAX + 1> waffle_sum;

void hacks() {
	std::cout.sync_with_stdio(false);
}

void clean() {
	std::cin >> std::ws;
}

int main(int argc, char *argv[]) {
	hacks();
	int test_case_n = 0, test_case_c = 0;

	for (std::cin >> test_case_n; test_case_c < test_case_n; test_case_c ++){
		int R, C, H, V;
		std::cin >> R >> C >> H >> V;

		for (int i = 0; i <= R; ++i) {
			for (int j = 0; j <= C; j++) {
				waffle[i][j] = waffle_sum[i][j] = waffle_sum[i][j] = 0;
			}
		}

		int total_choco = 0;
		for (int i = 1; i <= R; ++i) {
			for (int j = 1; j <= C; j++) {
				char &read = waffle[i][j];
				while (read != '.' && read != '@') {
					std::cin >> read;
				}

				waffle_sum[i][j] += waffle_sum[i - 1][j];
				waffle_sum[i][j] += waffle_sum[i][j - 1];
				waffle_sum[i][j] -= waffle_sum[i - 1][j - 1];

				if (read == '@') {
					waffle_sum[i][j] ++;
					total_choco ++;
				}
			}
		}
		std::cout << "Case #" << test_case_c + 1 << ": ";

		int each_choco = total_choco / (H + 1) / (V + 1);
		if (each_choco * (H + 1) * (V + 1) != total_choco) {
			std::cout << "IMPOSSIBLE" << std::endl;
			continue;
		}

		if (each_choco == 0) {
			std::cout << "POSSIBLE" << std::endl;
			continue;
		}

		std::vector<int> V_cut = {0};
		for (int i = 1; i <= C; ++i) {
			if (waffle_sum[R][i] - waffle_sum[R][V_cut.back()] == total_choco / (V + 1)) {
				V_cut.push_back(i);
			}
		}

		if (V_cut.size() != V + 2) {
			std::cout << "IMPOSSIBLE" << std::endl;
			continue;
		}

		std::vector<int> H_cut = {0};
		for (int i = 1; i <= R; ++i) {
			if (waffle_sum[i][C] - waffle_sum[H_cut.back()][C] == total_choco / (H + 1)) {
				H_cut.push_back(i);
			}
		}

		if (H_cut.size() != H + 2) {
			std::cout << "IMPOSSIBLE" << std::endl;
			continue;
		}

		int flag = 0;
		for (int i = 1; i < H_cut.size() && !flag; ++i) {
			for (int j = 1; j < V_cut.size() && !flag; j++) {
				int h = H_cut[i];
				int v = V_cut[j];
				int ph = H_cut[i - 1];
				int pv = V_cut[j - 1];
				if (waffle_sum[h][v] + waffle_sum[ph][pv] - waffle_sum[h][pv] - waffle_sum[ph][v] != each_choco) {
					std::cout << "IMPOSSIBLE" << std::endl;
					flag = 1;
				}
			}
		}
		if (flag) {
			continue;
		}

		std::cout << "POSSIBLE" << std::endl;
	}
	return 0;
}
