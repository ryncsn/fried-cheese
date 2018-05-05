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
#include <set>
#include <unordered_set>
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
	hacks();
	const auto L_MAX = 10;
	const auto N_MAX = 2000;
	int T, t_counter=0;

	for(std::cin >> T; t_counter < T; t_counter ++){
		int N, L;
		std::unordered_map<char, std::unordered_set<char>> combine[L_MAX];
		std::set<char> alphas[L_MAX];
		char string[L_MAX + 1];
		std::cin >> N >> L;
		for (int i = 0; i < N; ++i) {
			std::cin >> string;
			for (int i = 0; i < L - 1; ++i) {
				combine[i][string[i]].insert(string[i+1]);
			}
			for (int i = 0; i < L; ++i) {
				alphas[i].insert(string[i]);
			}
		}
        bool unique = false;
        int i = 0;
        for (i = 0; i < L - 1; ++i) {
            if (unique) { break; }
			for (auto alpha : alphas[i]) {
                if (unique) { break; }
                for (auto nextAlpha : alphas[i + 1]) {
                    if(combine[i][alpha].count(nextAlpha) == 0) {
                        unique = true;
                        string[i] = alpha; i++;
                        string[i] = nextAlpha;
                        break;
                    }
                }
			}
		}
        if (unique) {
            while (i < L) {
                string[i] = *alphas[i].begin();
                i++;
            }
            std::cout << "Case #" << t_counter + 1 << ": " << string << std::endl;
        } else {
            std::cout << "Case #" << t_counter + 1 << ": " << "-" << std::endl;
        }
	}
	return 0;
}

