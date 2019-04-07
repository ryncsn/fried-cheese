/*
 * Author: Kairui Song
 * Date: 2019-04-06
 */
#include <iostream>
#include <numeric>
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
	int test_case_n = 0, test_case_c = 0;

	for(std::cin >> test_case_n; test_case_c < test_case_n; test_case_c ++){
		std::map<unsigned long long, char> known_dict;
		std::set<unsigned long long> known_crypt;
		std::vector<unsigned long long> ordered_crypt, buffer;

		unsigned long long reader, prev;
		unsigned long long chain_key = 0;
		unsigned long long N, L;
		bool key_resolved = 0;
		std::cin >> N >> L;

		std::cin >> reader;
		buffer.push_back(reader);
		for (unsigned long long i = 0; i < L - 1; ++i) {
			prev = reader;
			std::cin >> reader;
			if (prev == reader && !key_resolved) {
				buffer.push_back(reader);
				continue;
			}

			if (!key_resolved) {
				key_resolved = 1;
				chain_key = std::__gcd(reader, prev);
				known_crypt.insert(prev / chain_key);

				unsigned long long temp_chain_key = chain_key;
				for (unsigned long long j = i; j >= 0; j--) {
					buffer[j] = buffer[j] / temp_chain_key;
					temp_chain_key = buffer[j];
				}
			}

			buffer.push_back(chain_key);
			known_crypt.insert(chain_key);
			chain_key = reader / chain_key;
		}

		known_crypt.insert(chain_key);
		buffer.push_back(chain_key);

		std::copy(known_crypt.begin(), known_crypt.end(), std::back_inserter(ordered_crypt));
		std::sort(ordered_crypt.begin(), ordered_crypt.end());

		char key = 'A';
		for (auto &i: ordered_crypt) {
			known_dict[i] = key++;
		}

		std::cout << "Case #" << test_case_c + 1 << ": ";
		for (auto &i: buffer) {
			std::cout << known_dict[i];
			//std::cout << i << " ";
		}
		std::cout << std::endl;

	}
	return 0;
}
