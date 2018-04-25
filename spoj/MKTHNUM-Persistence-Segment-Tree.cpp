/*
 * Author: Kairui Song
 * Date: 2018-03-30
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

#define INF std::numeric_limits<int>::max()

void hacks() {
	std::cout.sync_with_stdio(false);
}

void clean() {
	std::cin >> std::ws;
}

const int N_MAX = 100000;

template <typename T, int max_history>
struct Tree {
	struct Node {
		T data;
		int l, r;
		Node *L, *R;

		Node (T value, int l, int r, Node* L, Node* R) : // Copied Node
			data(value), l(l), r(r), L(L), R(R) {}

		Node (const Node& node) : Node (node.data, node.l, node.r, node.L, node.R) { }

		Node (int l, int r) :
			Node (0, l, r, nullptr, nullptr) { }

		Node* update (int value, int pos) {
			int mid = (l + r) / 2;
			if (l != r) {
				if (pos > mid) {
					R = (R ? new Node(*R) : new Node(mid + 1, r)) -> update(value, pos);
				}
				else {
					L = (L ? new Node(*L) : new Node(l, mid)) -> update(value, pos);
				}
			}
			data += value;
			return this;
		}

		Node* lc() { // Left child
			return L ? L : new Node(l, (l + r) / 2);
		}

		Node* rc() { // Right child
			return R ? R : new Node((l + r) / 2 + 1, r);
		}

		T ld() { return lc() -> data; }
		T rd() { return rc() -> data; }

	} *history_root [max_history];

	int head_version = 0;

	int bottom_length;

	Tree (int len): bottom_length(len) {
		history_root[0] = new Node(0, bottom_length);
	}

	void update (int pos) {
		history_root[head_version + 1] = new Node(*history_root[head_version]);
		history_root[++head_version]-> update(1, pos); // XXX
	}

	int query (int i, int j, int k) {
		Node* L = history_root[i - 1];
		Node* R = history_root[j];
		while (L -> l != L -> r) {
			int left_count = R -> ld() - L -> ld();
			if (k <= left_count) {
				L = L -> lc();
				R = R -> lc();
			}
			else {
				k -= left_count;
				L = L -> rc();
				R = R -> rc();
			}
		}
		return L -> l;
	}
};

int main(int argc, char *argv[]) {
	hacks();
	int n, m;
	std::cin >> n >> m;
	std::array<int, N_MAX> inputs;
	std::array<int, N_MAX> numbers;

	for (int i = 0; i < n; ++i) {
		std::cin >> inputs[i];
	}

	std::copy(inputs.begin(), inputs.begin() + n, numbers.begin());
	std::sort(numbers.begin(), numbers.begin() + n);
	auto number_uniq_end = std::unique(numbers.begin(), numbers.begin() + n);
	Tree<int, N_MAX + 1> tree(std::distance(numbers.begin(), number_uniq_end) - 1);

	for (int i = 0; i < n; ++i) {
		tree.update(std::distance(numbers.begin(), std::lower_bound(numbers.begin(), number_uniq_end, inputs[i])));
	}

	for (int _ = 0; _ < m; ++_) {
		int i, j, k;
		std::cin >> i >> j >> k;
		std::cout << numbers[tree.query(i, j, k)] << std::endl;
	}

	return 0;
}
