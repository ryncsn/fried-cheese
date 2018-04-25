/*
 * Author: Kairui Song
 * Date: 2018-04-14
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

#define SET_PERCISION(x) std::cout << std::fixed << std::setprecision(x);
#define INF std::numeric_limits<int>::max()
#define PI M_PI

std::array<std::array<char, 100>, 100> waffle;
std::array<int, 100> sumH, sumV;

void hacks() {
	std::cout.sync_with_stdio(false);
}

void clean() {
	std::cin >> std::ws;
}

int main(int argc, char *argv[]) {
	hacks();

	int T, t_counter=0;

	for(std::cin >> T; t_counter < T; t_counter ++){
		int R, C, H, V;
		std::cin >> R >> C >> H >> V;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; j++) {
				std::cin >> waffle[i][j];
			}
		}

		int totalSumV = 0;
		sumV.fill(0);
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; j++) {
				if (waffle[i][j] == '@') {
					totalSumV ++;
				}
			}
			sumV[i + 1] = totalSumV;
		}

		int totalSumH = 0;
		sumH.fill(0);
		for (int i = 0; i < C; ++i) {
			for (int j = 0; j < R; j++) {
				if (waffle[j][i] == '@') {
					totalSumH ++;
				}
			}
			sumH[i + 1] = totalSumH;
		}

		std::vector<int> Hcuts(H + 1), Vcuts(V + 1);

		int Vstep = totalSumV / (H + 1);
		int Hstep = totalSumH / (V + 1);
		if (totalSumH == 0 && totalSumV == 0) {
			std::cout << "Case #" << t_counter + 1 << ": " << "POSSIBLE" << std::endl;
		} else if (H > 0 && V > 0 && totalSumV % (H + 1) == 0 && totalSumH % (V + 1) == 0 && Vstep > 0 && Hstep > 0) {
			int i = 0;
			int flag = true;
			for (int step = 0; step <= totalSumV; step += Vstep) {
				for (; i <= R; ++i) {
					if (sumV[i] == step) {
						Hcuts.push_back(i);
						break;
					}
				}
			}
			if (i > R) {
				flag = false;
			}

			i = 0;
			for (int step = 0; step <= totalSumH; step += Hstep) {
				for (; i <= C; ++i) {
					if (sumH[i] == step) {
						Vcuts.push_back(i);
						break;
					}
				}
			}
			if (i > C) {
				flag = false;
			}

			int count = -1;
			for (int i = 1; i < Hcuts.size(); ++i) {
				for (int j = 1; j < Vcuts.size(); ++j) {
					int _count = 0;
					for (int r = Hcuts[i - 1];  r < Hcuts[i]; ++r) {
						for (int c = Vcuts[i - 1]; c < Vcuts[i]; ++c) {
							if (waffle[i][j] == '@') {
								_count ++;
							}
						}
					}
					if (count == -1) {
						count = _count;
					} else if (count != _count) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				std::cout << "Case #" << t_counter + 1 << ": " << "POSSIBLE" << std::endl;
			} else {
				std::cout << "Case #" << t_counter + 1 << ": " << "IMPOSSIBLE" << std::endl;
			}
		} else {
			std::cout << "Case #" << t_counter + 1 << ": " << "IMPOSSIBLE" << std::endl;
		}
	}
}
