/*
 * Author: Kairui Song
 * Date: 2018-03-01
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cstring>
#include <limits>
#include <map>
#include <unordered_map>
#include <bitset>

using namespace::std;

#define INF numeric_limits<int>::max()
#define N_MAX 1000
#define C_MAX 1000

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
		int N, M, C;
		int Pi, Bi;
		cin >> N;
		cin >> C;
		cin >> M;

		std::list<int> occupy[N_MAX];

		for (int i = 0; i < N_MAX; ++i) {
			occupy[i].clear();
		}

		for (int i = 0; i < M; ++i) {
			cin >> Pi;
			cin >> Bi;
			occupy[Pi - 1].push_back(Bi - 1);
		}

		int promo = 0;
		int round = 0;
		int passenger = 0;

		std::bitset<N_MAX> ingame;
		int seated[N_MAX];
		std::bitset<N_MAX> fulled;

		do {
			passenger = 0;
			for (int j = 0; j < N; ++j) {
				seated[j] = -1;
				ingame[j] = 0;
			}

			for (int i = N - 1; i >= 0; --i) {
				if (!occupy[i].empty()) {
					int pos = i;
					for(auto j = occupy[i].begin(); j != occupy[i].end();) {
						int buyer = *j;
						if (ingame[buyer] == 1) {
							j++;
							continue;
						}
						while(seated[pos] != -1){
							pos--;
							if (pos < 0) {
								break;
							}
						}
						if (pos < 0) {
							break;
						}
						seated[pos] = buyer;
						ingame[buyer] = 1;
						passenger ++;
						occupy[i].erase(j++);
						if (pos != i) {
							promo ++;
						}
					}
				}
			}

			if (passenger) {
						for (int i = 0; i < N; ++i) {
							cout << seated[i] << " ";
						}
						cout << endl;

				round ++;
			}

		} while (passenger != 0);

		cout << "Case #" << count + 1 << ": " << round << " " << promo << '\n';
	}

	return 0;
}
