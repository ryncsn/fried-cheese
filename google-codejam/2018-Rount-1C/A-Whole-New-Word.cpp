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

const auto L_MAX = 10;
const auto N_MAX = 2000;

bool findString(std::string& string, std::unordered_set<std::string>& words, std::unordered_set<char> alphas[], int alphasLen, int pos){
	if (pos == alphasLen) {
		if (words.count(string) == 0) {
			return true;
		}
	} else {
		for (auto alpha : alphas[pos]) {
			string[pos] = alpha;
			if (findString(string, words, alphas, alphasLen, pos + 1)) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	hacks();
	int T, t_counter=0;

	for(std::cin >> T; t_counter < T; t_counter ++){
		int N, L;
		std::unordered_set<char> alphas[L_MAX];
		std::unordered_set<std::string> words;
		std::string string;
		std::cin >> N >> L;
		for (int i = 0; i < N; ++i) {
			std::cin >> string;
			for (int i = 0; i < L; ++i) {
				alphas[i].insert(string[i]);
			}
			words.insert(string);
		}
		auto found = findString(string, words, alphas, L, 0);
        if (found) {
            std::cout << "Case #" << t_counter + 1 << ": " << string << std::endl;
        } else {
            std::cout << "Case #" << t_counter + 1 << ": " << "-" << std::endl;
        }
	}
	return 0;
}

