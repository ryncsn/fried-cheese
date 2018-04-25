/*
 * Author: Kairui Song
 * Date: 2018-02-25
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <limits>
#include <map>
#include <unordered_map>
#include <bitset>

using namespace::std;

#define CITY_MAX 5000
#define INF numeric_limits<int>::max()

int cities[CITY_MAX];
vector<int> to[CITY_MAX];

void hacks() {
	cout.sync_with_stdio(false);
}

void clean() {
	cin >> ws;
}

int main(int argc, char *argv[]) {
	hacks();

	int T,count=0;

	for(cin >> T; count < T; count++){
		clean();

		int N, ai, bi, P;

		for (int i = 0; i < CITY_MAX; ++i) {
			to[i].clear();
			cities[i] = 0;
		}

		cin >> N;

		for (int i = 0; i < N; ++i) {
			cin >> ai >> bi;
			to[ai - 1].push_back(bi - 1);
		}

		cin >> P;

		for (int i = 0; i < P; ++i) {
			int c;
			cin >> c;
			for (int j = 0; j < c; ++j) {
				for (auto city : to[j]) {
					if (city >= c - 1) {
						cities[i] += 1;
					}
				}
			}
		}

		cout << "Case #" << count + 1 << ": ";

		for (int i = 0; i < P; ++i) {
			cout << cities[i] << " ";
		}

		cout << endl;

	}

	return 0;
}
