/*
 * Author: Kairui Song
 * Date: 2018-03-18
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

	int T, count=0;
	char digits[100] = {};

	for(std::cin >> T; count < T; count++){
		long long n, pos = 0;
		std::cin >> n;
		for (int i = 0; i < 100; ++i) {
			digits[i] = 0;
		}
		while (n > 0) {
			digits[pos] = (n % 10);
			n /= 10;
			pos ++;
		}
		pos --;

		long long sub_num = 0, sub_target_up = 0, sub_target_down = 0;

		while (pos >= 0 && !(digits[pos] & 1)) {
			pos --;
		}

		if (pos >= 0) {
			if (digits[pos] == 9) {
				while (pos >= 0) {
					sub_num *= 10;
					sub_target_down *= 10;
					sub_num += digits[pos];
					sub_target_down += 8;
					sub_target_up = -1;
					pos --;
				}
			} else {
				sub_num += digits[pos];
				sub_target_up += digits[pos] + 1;
				sub_target_down += digits[pos] - 1;
				pos --;
				while (pos >= 0) {
					sub_num *= 10;
					sub_target_down *= 10;
					sub_target_up *= 10;
					sub_num += digits[pos];
					sub_target_down += 8;
					pos --;
				}
			}
		}

		long long up = sub_target_up - sub_num;
		long long down = sub_num - sub_target_down;

		long long ans = (up > down)?down:up;
		if (sub_target_up == -1) {
			ans = down;
		}
		std::cout << "Case #" << count + 1 << "" << ": " << ans << std::endl;
	}

	return 0;
}

