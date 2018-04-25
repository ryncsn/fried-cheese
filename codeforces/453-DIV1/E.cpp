/*
 * Author: Kairui Song
 * Date: 2018-04-19
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

#define SET_PERCISION(x) std::cout << std::fixed << std::setprecision(x)
#define INF std::numeric_limits<int>::max()
#define PI M_PI

void hacks() {
	std::cout.sync_with_stdio(false);
}

void clean() {
	std::cin >> std::ws;
}

template <typename T>
struct SplayTree {
	struct Node {
		T key;
		Node *L, *R;

		Node (T value) : key(value) {}
	};

	Node* root;

	Node* leftRount(Node* root) {
		Node* right = root -> R;
		if (right != nullptr) {
			root -> R = right -> L;
			right -> L = root;
		}
		return right;
	}

	Node* rightRount(Node* root) {
		Node* left = root -> L;
		if (left != nullptr) {
			root -> L = left -> R;
			left -> R = root;
		}
		return left;
	}

	SplayTree (T initValue) {
		root = new Node(initValue);
	}

	Node* insert (T value) {
		Node* root = root;
	}

	static Node* query (T value) {
		Node* root = root;
	}
};

struct Pony {
	int s;
	int m;
	int r;
};

int main(int argc, char *argv[]) {
	hacks();

	int n, m;

	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		Pony *pony = new Pony();
		std::cin >> pony -> s >> pony -> m >> pony -> r;
		// TODO
	}
	std::cin >> m;

	int t, l, r;
	for (int i = 0; i < m; ++i) {
		std::cin >> t >> l >> r;
	}

	return 0;
}
