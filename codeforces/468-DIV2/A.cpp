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

	int a, b;

	cin >> a >> b;

	int distance = abs(a - b);

	int l = (distance + 1) / 2, r = distance / 2;

	int tireness = l * (1 + l) / 2;
	tireness += r * (1 + r) / 2;

	cout << tireness;

	return 0;
}
