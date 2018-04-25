/*
 * Author: Kairui Song
 * Date: 2018-03-18
 */
#include <iomanip>
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

int main(int argc, char *argv[]) {
	hacks();

	int T,count=0;

	for(std::cin >> T; count < T; count++){
		const int N_MAX = 20000 + 1;

		std::array<int, N_MAX> V;
		double avg = 0;
		int k, n;

		std::cin >> n;
		std::cin >> k;

		for (int i = 0; i < n; ++i) {
			std::cin >> V[i];
			double value = V[i];
			avg += (value - avg) / (i + 1);
		}

		std::sort(V.begin(), V.begin() + n);

		int ncount = 0;
		double expect = avg;
		while (k > 0) {
			double new_avg = 0;
			double pos_below_avg = 0;
			double pos_above_avg = 0;
			double exp_below_avg = 0;
			double exp_above_avg = 0;
			while (ncount < n && V[ncount] < expect) {
				ncount ++;
			}
			for (int i = 0; (i + ncount) < n; ++i) {
				double value = V[i + ncount];
				// std::cout << "Above Value" << value << std::endl;
				new_avg += (value - new_avg) / (i + 1);
			}
			pos_below_avg = ((double)ncount) / ((double)n);
			pos_above_avg = (double)1 - pos_below_avg;
			// std::cout << "Below ncount" << ncount << std::endl;
			// std::cout << "Below pos" << pos_below_avg << std::endl;
			// std::cout << "Above pos" << pos_above_avg << std::endl;
			exp_above_avg = new_avg;
			exp_below_avg = (expect - new_avg / (double)n);
			// std::cout << "Above exp" << new_avg << std::endl;
			// std::cout << "Below exp" << exp_below_avg << std::endl;
			expect = pos_below_avg * expect + pos_above_avg * exp_above_avg;
			k --;
		}
		std::cout << "Case #" << count + 1 << "" << ": " << std::fixed << std::setprecision(6) << expect << std::endl;
	}

	return 0;
}

