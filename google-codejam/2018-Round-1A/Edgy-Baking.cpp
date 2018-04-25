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

void hacks() {
	std::cout.sync_with_stdio(false);
}

void clean() {
	std::cin >> std::ws;
}

struct cookie {
	int w;
	int h;
	int min;
	int mid;
	double max;
};

std::array<cookie, 100> cookies;

int main(int argc, char *argv[]) {
	hacks();

	int T, t_counter=0;
	SET_PERCISION(6)

	for(std::cin >> T; t_counter < T; t_counter ++){
		int N;
		double P;
		double min = 0;
		std::cin >> N >> P;
		for (int i = 0; i < N; ++i) {
			cookie &c = cookies[i];
			std::cin >> c.w;
			std::cin >> c.h;
			c.min = (c.w + c.h) * 2;
			c.mid = std::min(c.w, c.h) * 2 + c.min;
			c.max = std::sqrt(c.w * c.w + c.h * c.h) * 2 + c.min;
			min += c.min;
		}
		int mid_i = 0;
		if (min < P) {
			for (; mid_i < N; ++mid_i) {
				if (min + (cookies[mid_i].mid - cookies[mid_i].min) < P) {
					min += (cookies[mid_i].mid - cookies[mid_i].min);
				} else {
					break;
				}
			}
			if (min == P) {
				std::cout << "Case 1#" << t_counter + 1 << ": " << min << std::endl;
			} else {
				for (int i = 0; i < mid_i; ++i) {
					double max = cookies[i].max, mid = cookies[i].mid;
					if (min + (max - mid) >= P) {
						min = P;
						break;
					}
					else {
						min += (max - mid);
					}
				}
				std::cout << "Case 2#" << t_counter + 1 << ": " << min << std::endl;
			}
		}
		else {
			std::cout << "Case 3#" << t_counter + 1 << ": " << min << std::endl;
		}
	}

	return 0;
}

