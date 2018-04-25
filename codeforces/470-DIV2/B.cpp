/*
 * Author: Kairui Song
 * Date: 2018-03-13
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

using namespace::std;

#define INF numeric_limits<int>::max()
#define len(x) x.size()

std::array<bool, 1000001> is_prime;

void hacks() {
	cout.sync_with_stdio(false);
}

void clean() {
	cin >> ws;
}

void gen_prime() {
	is_prime.fill(true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < 1000001; ++i) {
		if (is_prime[i] == true) {
			for (int j = 2; j * i < 1000001; ++j) {
				is_prime[i * j] = false;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	hacks();

	int X0 = 3, X1 = 4, X2 = 4;

	int X2P, X1P;

	cin >> X2;

	gen_prime();

	for (int i = X2; i >= 2; --i) {
		if (is_prime[i] && (X2 % i) == 0) {
			X2P = i;
			break;
		}
	}

	X0 = INF;

	int X1_min = X2 - X2P + 1;
	int X1_max = X2;

	for (X1P = 2; X1P < X1_min; ++X1P) {
		if (is_prime[X1P]) {
			X1 = (X1_min / X1P) * X1P;
			if (X1 < X1_min)
				X1 += X1P;
			if (X1 <= X1_max && X1 >= X1_min) {
				X0 = min(X1 - X1P + 1, X0);
			}
		}
	}

	cout << X0 << endl;

	return 0;
}
