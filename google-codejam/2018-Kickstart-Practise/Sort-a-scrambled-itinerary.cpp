/*
 * Author: Kairui Song
 * Date: 2018-02-25
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <limits>
#include <unordered_map>
#include <map>
#include <bitset>

using namespace::std;

#define N_MAX 100
#define INF numeric_limits<int>::max()

struct Airport {
	vector<string> from;
	vector<string> to;
	bool visited;
};

unordered_map<string, Airport> Airports;

vector<string> Ans;

void hacks() {
	cout.sync_with_stdio(false);
}

void clean() {
	cin >> ws;
}

void dfs(string from, bool start=false) {
	Airport& ap = Airports[from];
	if (ap.to.empty()){
		cout << from << "";
		return;
	}
	if (!start)
		cout << from << " ";
	cout << from << "-";
	for (auto to : ap.to) {
		dfs(to);
	}
}

int main(int argc, char *argv[]) {
	hacks();

	int T,count=0;

	for(cin >> T; count < T; count++){
		int N;

		Airports.clear();
		Ans.clear();

		cin >> N;
		for (int i = 0; i < N; ++i) {
			string from, to;
			cin >> from >> to;
			if(Airports.count(from) == 0){
				Airports[from] = Airport();
			}
			if(Airports.count(to) == 0){
				Airports[to] = Airport();
			}
			Airports[from].to.push_back(to);
			Airports[to].from.push_back(from);
		}

		cout << "Case #" << count + 1 << ": ";
		for (const auto ap : Airports) {
			if (ap.second.from.empty()){
				dfs(ap.first, true);
			}
		}
		cout << endl;
	}

	return 0;
}
