/*
 * Author: Kairui Song
 * Date: 2018-03-04
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>
#include <queue>
#include <cstring>
#include <limits>
#include <map>
#include <map>
#include <unordered_map>
#include <bitset>

using namespace::std;

#define INF numeric_limits<int>::max()
#define len(x) x.size()

int n;

void hacks() {
	cout.sync_with_stdio(false);
}

void clean() {
	cin >> ws;
}

int ans = 0;

struct node {
	int to;
	int idx;
};
array<node, 100002> nodes;

forward_list<int> curs;
array<node*, 100002> nodes_by_to;
array<node*, 100002> nodes_by_idx;

int count(int idx){
	int ret = 1;
	while(idx < n && nodes_by_to[idx] -> to == nodes_by_to[idx + 1] -> to){
		idx ++;
		ret ++;
	}
	return ret;
}

int b_select(int to){
	int l = 0, r = n + 1, mid;
	do {
		mid = (l + r) / 2;
		int value = nodes_by_to[mid] -> to;
		if (value > to) {
			r = mid;
		} else if (value < to) {
			l = mid + 1;
		}
	} while (l != r && nodes_by_to[mid] -> to != to);
	if (nodes_by_to[mid]->to != to) {
		return -1;
	}
	while (mid > 0 && nodes_by_to[mid - 1] -> to == to) {
		mid --;
	}
	return mid;
}

void bfs() {
	// cout << "BFS" << endl;
	forward_list<int> next;
	int j = 0;
	for (auto node_idx : curs) {
		// cout << "Current node: " << node_idx << endl;
		int pos = b_select(node_idx);
		// cout << "Found child: " << pos << endl;
		if (pos == -1) {
			continue;
		}
		int len = count(pos);
		// cout << "Len: " << len << endl;
		for (int i = pos; i < pos + len; i++){
			next.push_front(nodes_by_to[i]->idx);
			j++;
		}
	}
	if (j % 2 == 1) {
		// cout << "Apple: " << j << endl;
		ans ++;
	}
	curs.clear();
	curs = next;
	if (!next.empty()){
		bfs();
	}
}

int main(int argc, char *argv[]) {
	hacks();

	cin >> n;

	for (int i = 0; i < n + 1; ++i) {
		nodes_by_to[i] = nodes.data() + i;
		nodes_by_idx[i] = nodes.data() + i;
		nodes[i].idx = i;
		nodes[i].to = -1;
	}

	nodes[1].to = 0;

	for (int i = 1; i < n; ++i) {
		cin >> nodes_by_idx[i + 1]->to;
	}

	std::sort(nodes_by_to.begin(), nodes_by_to.begin() + n + 1, [](const node* a, const node* b) -> bool {return a->to < b->to;});

//	for (int i = 0; i < n + 1; ++i) {
//		cout << nodes_by_to[i]->to << endl;
//	}
//
//	cout << "Start" << endl;

	curs.push_front(-1);

	bfs();

	cout << ans - 1;

	return 0;
}
