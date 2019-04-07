/*
 * Author: Kairui Song
 * Date: 2019-04-06
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

void hacks() {
	std::cout.sync_with_stdio(false);
}

void clean() {
	std::cin >> std::ws;
}


int main(int argc, char *argv[]) {
	hacks();
	int test_case_n, test_case_c = 0;
	std::string N, N1, N2;
	std::cin >> test_case_n;
	for(;test_case_c < test_case_n; test_case_c ++){
		N = N1 = N2 = "";
		std::cin >> N;
		bool carry = 0;
		for (auto i : N) {
			if (i == '4') {
				N1 += '2';
				N2 += '2';
				carry = 1;
			} else {
				N1 += i;
				if (carry) {
					N2 += '0';
				}
			}
		}
		std::cout << "Case #" << test_case_c + 1 << ": ";
		std::cout << N1 << " " << N2 << std::endl;
	}
	return 0;
}
