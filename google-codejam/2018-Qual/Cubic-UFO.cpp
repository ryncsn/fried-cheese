/*
 * Author: Kairui Song
 * Date: 2018-04-07
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
		double A;
		std::cin >> A;

		double Y, Z;
		double Y_r = 0, Z_r = 0;

		const double diagonal = std::sqrt(2);
		const double tdiagonal = std::sqrt(3);

		if (A <= 1.414213) {
			double Z_left = 0, Z_right = 45;
			double Z_mid = (Z_left + Z_right) / 2;
			double shadow = diagonal * std::sin((45 + Z_mid) * M_PI / 180);
			double diff = shadow - A;
			while (std::abs(diff) > 0.00000000001) {
				if (diff > 0) {
					Z_right = Z_mid;
				} else {
					Z_left = Z_mid;
				}
				Z_mid = (Z_left + Z_right) / 2;
				shadow = diagonal * std::sin((45 + Z_mid) * M_PI / 180);
				diff = shadow - A;
			}
			Z_r = (Z_mid) * M_PI / 180;
		} else {
			Z_r = (45) * M_PI / 180;
			double Y_left = 0, Y_right = std::atan(diagonal / 2);
			double Y_mid = (Y_left + Y_right) / 2;
			double shadow_c = std::sin(Y_mid);
			// double shadow_r = (tdiagonal * std::sin(0.6154797086703875 + (Y_mid * M_PI / 180)) - diagonal * std::sin(Y_mid)) * diagonal;
			double shadow_r = diagonal * std::cos(Y_mid);
			double shadow = shadow_c + shadow_r;
			double diff = shadow - A;
			while (std::abs(diff) > 0.00000000001) {
				if (diff > 0) {
					Y_right = Y_mid;
				} else {
					Y_left = Y_mid;
				}
				Y_mid = (Y_left + Y_right) / 2;
				shadow_c = std::sin(Y_mid);
				shadow_r = diagonal * std::cos(Y_mid);
				shadow = shadow_c + shadow_r;
				diff = shadow - A;
			}
			Y_r = Y_mid;
		}

		std::cout << std::fixed << std::setprecision(7);
		std::cout << "Case #" << count + 1 << ": " << std::endl;
		double Z_sin = std::sin(Z_r);
		double Z_cos = std::cos(Z_r);
		double Y_sin = std::sin(Y_r);
		double Y_cos = std::cos(Y_r);
		std::cout << Y_cos * Z_cos * 0.5 << " " << Z_sin * 0.5 << " " << 0.5 * Y_sin << std::endl;
		std::cout << Y_cos * Z_sin * - 0.5 << " " << Z_cos * 0.5 << " " << -0.5 * Y_sin << std::endl;
		std::cout << -0.5 * Y_sin << " " << 0 << " " << 0.5 * Y_cos << std::endl;
	}

	return 0;
}

