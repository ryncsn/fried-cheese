/*
 * Author: Kairui Song
 * Date: 2018-03-04
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
#define len(x) x.size()

void hacks() {
	cout.sync_with_stdio(false);
}

void clean() {
	cin >> ws;
}

int main(int argc, char *argv[]) {
	hacks();

	int n, a, b, round;

	cin >> n;
	cin >> a >> b;
	int i;

	for (i = 1; n > 1; ++i) {
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		n = n / 2;
		if (a == b) {
			break;
		}
	}

	if (n == 1) {
		cout << "Final!";
	} else {
		cout << i;
	}

	return 0;
}
