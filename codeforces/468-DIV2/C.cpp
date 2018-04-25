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

	int count[3] = {0,0,0};

	int buffer[5] = {0,0,0,0,0};

	int n, starter, min = 0, mid, max = INF, x;

	cin >> n;
	cin >> starter;

	long long total = starter;
	min = mid = max = starter;

	buffer[starter - mid + 2] += 1;

	for (int i = 1; i < n; ++i) {
		cin >> x;
		if (max < x) {
			max = x;
		}
		if (min > x) {
			min = x;
		}
		buffer[x - mid + 2] += 1;
		total += x;
	}

	if (buffer[4] != 0) {
		buffer[1] = buffer[2];
		buffer[2] = buffer[3];
		buffer[3] = buffer[4];
	}

	if (buffer[0] != 0) {
		buffer[3] = buffer[2];
		buffer[2] = buffer[1];
		buffer[1] = buffer[0];
	}

	mid = (min + max) / 2;

	count[2] = buffer[3];
	count[1] = buffer[2];
	count[0] = buffer[1];


	if (!count[0]) {
		cout << n << endl;
		for (int i = 0; i < count[1]; ++i) {
			cout << min << " ";
		}
		for (int i = 0; i < count[2]; ++i) {
			cout << max << " ";
		}
	}

	else if (!count[2]) {
		cout << n << endl;
		for (int i = 0; i < count[0]; ++i) {
			cout << min << " ";
		}
		for (int i = 0; i < count[1]; ++i) {
			cout << max << " ";
		}
	}
	else {
		int count1 = count[0] + count[2] - abs(count[0] - count[2]);
		int count2 = (count[1] / 2) * 2;

		if (count1 > count2) {
			count[0] -= count1 / 2;
			count[2] -= count1 / 2;
			count[1] += count1;
			n = n - count1;
		}
		else {
			count[0] += count2 / 2;
			count[2] += count2 / 2;
			count[1] -= count2;
			n = n - count2;
		}
		cout << n << endl;
		for (int i = 0; i < count[0]; ++i) {
			cout << min << " ";
		}
		for (int i = 0; i < count[1]; ++i) {
			cout << mid << " ";
		}
		for (int i = 0; i < count[2]; ++i) {
			cout << max << " ";
		}
	}


	return 0;
}
