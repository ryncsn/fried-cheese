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

#define N_MAX 100
#define INF numeric_limits<int>::max()

void hacks() {
	cout.sync_with_stdio(false);
}

void clean() {
	cin >> ws;
}

bool get_t_th_bool(long long t, long long scale) {
	if (t < 3) {
		return false;
	}
	if (t == scale) {
		return false;
	}
	if (t > scale) {
		t = scale * 2 - t;
		return !get_t_th_bool(t, scale / 2);
	}
	return get_t_th_bool(t, scale / 2);
}

int main(int argc, char *argv[]) {
	hacks();

	int T,count=0;

	for(cin >> T; count < T; count++){
		long long K;
		long long scale = 1;
		cin >> K;
		while (scale < K) {
			scale *= 2;
		}
		if (get_t_th_bool(K, scale))
			cout << "Case #" << count + 1 << ": 1\n";
		else
			cout << "Case #" << count + 1 << ": 0\n";
	}

	return 0;
}
