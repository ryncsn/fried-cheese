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
#include <string>

#define INF std::numeric_limits<int>::max()

void hacks() {
	std::cout.sync_with_stdio(false);
}

void clean() {
	std::cin >> std::ws;
}

int damage(std::string& P) {
	int level = 1;
	int damage = 0;

	for (int i = 0; i < P.length(); ++i) {
		if (P[i] == 'C') {
			level *= 2;
		} else if (P [i] == 'S') {
			damage += level;
		}
	}
	return damage;
}

int main(int argc, char *argv[]) {
	hacks();

	int T,count=0;

	for(std::cin >> T; count < T; count++){
		int D;
		std::string P;
		std::cin >> D;
		std::cin >> P;

		bool flipped = true;
		int flip_count = 0;

		while(flipped) {
			if (damage(P) <= D) {
				break;
			}
			flipped = false;
			for (int i = 0; i < (int)P.length() - 1; ++i) {
				if (P[i] == 'C' && P[i + 1] == 'S') {
					P[i] = 'S';
					P[i + 1] = 'C';
					flip_count ++;
					flipped = true;
					break;
				}
			}
		}

		if (flipped) {
			std::cout << "Case #" << count + 1 << ": " << flip_count << std::endl;
		} else {
			std::cout << "Case #" << count + 1 << ": " << "IMPOSSIBLE" << std::endl;
		}
	}

	return 0;
}

