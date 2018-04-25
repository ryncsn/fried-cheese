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

#define INF numeric_limits<int>::max()
#define NUM_LIMIT 100

int number_count[NUM_LIMIT];

void hacks() {
	cout.sync_with_stdio(false);
}

void clean() {
	cin >> ws;
}

long long sum(int number, int offset, int step, int togo) {
	int left = number_count[number] - offset;
	if (togo > left) {
		return sum(number + 1, 0, step, togo - left) + left * number;
	}
}

int main(int argc, char *argv[]) {
	hacks();

	int T,count=0;

	for (int i = 0; i < NUM_LIMIT; ++i) {
		number_count[i] = 0;
	}

	for(cin >> T; count < T; count++){
		int N, Q, Li, Ri;
		long long ans = 0;
		int in;

		cin >> N >> Q;

		for (int i = 0; i < N; ++i) {
			cin >> in;
			number_count[in - 1] += 1;
		}

		ans = 0;
		int number = 0, offset = 0, step = 1, togo = Ri - Li + 1;

		for (int i = 0; i < Q; ++i) {
			cin >> Li >> Ri;
			int n = N;
			while (Li > n) {
				Li -= n;
				n -= 1;
				step += 1;
			}
			while (Li > number_count[number]) {
				Li -= number_count[number];
				number ++;
			}
			offset = number_count[number] - Li;
		}

		cout << "Case #" << count + 1 << ": " << sum(number, offset, step, togo) << '\n';
	}

	return 0;
}
