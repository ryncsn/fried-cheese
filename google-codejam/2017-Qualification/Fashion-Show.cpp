/*
 * Author: Kairui Song
 * Date: 2018-02-20
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

#define N_MAX 100 * 4
#define INF numeric_limits<int>::max()

vector<int> to[N_MAX];
int match[N_MAX] = {-1};
bool visited[N_MAX] = {false};
bool skip[N_MAX] = {0};


bool bi_match_dfs(int num) {
	/* Do DFS bi match in place */
	if (skip[num]) {
		return false;
	}
	for (int next : to[num]) {
		if (visited[next] == false && !skip[next]) {
			visited[next] = true;
			if (match[next] == -1 || bi_match_dfs(match[next])) {
				match[num] = next;
				match[next] = num;
				return true;
			}
		}
	}
	return false;
}

void hacks() {
	cout.sync_with_stdio(false);
}

void clean() {
	cin >> ws;
}

int main(int argc, char *argv[]) {
	hacks();

	int T,count=0;
	int N, M;
	int ri, ci;
	char xboard[N_MAX][N_MAX], pboard[N_MAX][N_MAX], check;
	char oboard[N_MAX][N_MAX];

	for(cin >> T; count < T; count++){
		clean();
		cin >> N >> M;
		bitset<N_MAX> used_r, used_c;

		for (int i = 0; i < N_MAX; ++i) {
			for (int j = 0;  j < N_MAX; ++j) {
				oboard[i][j] = pboard[i][j] = xboard[i][j] = '.';
			}
			used_r[i] = used_c[i] = 0;
			to[i].clear();
			match[i] = -1;
			skip[i] = false;
		}

		for (int i = 0; i < M; ++i) {
			cin >> check >> ws;
			cin >> ri >> ci >> ws;
			oboard[ri - 1][ci - 1] = check;
			if (check == 'o') {
				xboard[ri - 1][ci - 1] = 'x';
				pboard[ri - 1][ci - 1] = '+';
				used_r[ri - 1] = used_c[ci - 1] = 1;
			}
			else if (check == 'x') {
				xboard[ri - 1][ci - 1] = 'x';
				used_r[ri - 1] = used_c[ci - 1] = 1;
			}
			else if (check == '+') {
				pboard[ri - 1][ci - 1] = '+';
			}
		}

//		for (int c = 0; c < N; ++c) {
//			for (int r = 0; r < N; ++r) {
//				cout << oboard[c][r];
//			}
//			cout << endl;
//		}
//
		int ri = 0, ci = 0;
//		cout << used_r << endl;
//		cout << used_c << endl;
		while (ri < N && ci < N) {
			while (used_r[ri] == 1) {
				ri++;
			}
			while (used_c[ci] == 1) {
				ci++;
			}
			xboard[ri][ci] = 'x';
			used_r[ri] = used_c[ci] = 1;
		}

		for (int c = 0; c < N; ++c) {
			for (int r = 0; r < N; ++r) {
				int lt = r + c;
				int rt = (N + r - c) - 1 + 2 * N;
				if (pboard[r][c] == '+') {
					skip[rt] = skip[lt] = true;
				}
				// cout << r << " " << c << endl;
				// cout << lt << " " << rt - 2 * N << endl;
				to[lt].push_back(rt);
				to[rt].push_back(lt);
			}
		}

		for (int i = 0; i < N_MAX; ++i) {
			for (int i = 0; i < N_MAX; i++)
				visited[i] = 0;
			if (match[i] == -1) {
				bi_match_dfs(i);
			}
		}

		for (int i = 0; i < N * 2 - 1; ++i) {
			int lt = i, rt = match[i];
			if (rt == -1){
				continue;
			}
			rt -= 2 * N;
			// cout << endl;
			// cout << lt << ' ' << rt << endl;
			int r = (rt + lt - N + 1) / 2;
			int c = lt - r;
			// cout << c << ' ' << r << endl;
			pboard[r][c] = '+';
		}

//		cout << "Case #" << count + 1 << ": " << '\n';
//		for (int c = 0; c < N; ++c) {
//			for (int r = 0; r < N; ++r) {
//				cout << pboard[c][r];
//			}
//			cout << endl;
//		}
//		for (int c = 0; c < N; ++c) {
//			for (int r = 0; r < N; ++r) {
//				cout << xboard[c][r];
//			}
//			cout << endl;
//		}

		int points = 0;
		int steps = 0;
		for (int c = 0; c < N; ++c) {
			for (int r = 0; r < N; ++r) {
				if (xboard[c][r] == 'x') {
					points += 1;
					if (pboard[c][r] == '+') {
						xboard[c][r] = 'o';
					}
				}
				if (pboard[c][r] == '+') {
					points += 1;
				}
				if (xboard[c][r] == '.') {
					xboard[c][r] = pboard[c][r];
				}
			}
		}

		for (int c = 0; c < N; ++c) {
			for (int r = 0; r < N; ++r) {
				if (xboard[c][r] != oboard[c][r]) {
					steps += 1;
				}
			}
		}

		cout << "Case #" << count + 1 << ": " << points << " " << steps << endl;

		for (int c = 0; c < N; ++c) {
			for (int r = 0; r < N; ++r) {
				if (xboard[c][r] != oboard[c][r]) {
					cout << xboard[c][r] << " " << c + 1 << " " << r + 1 << " " << endl;
				}
			}
		}
	}

	return 0;
}
