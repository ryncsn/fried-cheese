#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
void hacks() { std::cout.sync_with_stdio(false); }
void clean() { std::cin >> std::ws; }
template <typename Number> inline bool odd(Number number) { return number & 1; }
template <typename Number> inline Number floor_div_2(Number number) { return (number + 1) / 2; }
template <typename Number> inline Number ceil_div_2(Number number) { return number / 2; }
int main(int argc, char *argv[]) {
	hacks();
	int T,count=0;
	unsigned long long N = 0, K = 0;
	unsigned long long left, right, stage, lc, rc, plc, prc;
	unsigned long long ll, lr, rl, rr, ansl, ansr;

	for(std::cin >> T; count < T; count++){
		clean();
		std::cin >> N;
		std::cin >> K;

		left = ceil_div_2(N - 1);
		right = floor_div_2(N - 1);
		lc = 1;
		rc = 1;
		stage = 1;
		while (K > stage) {
			K -= stage;
			stage *= 2;

			plc = lc;
			prc = rc;

			lc = 0;
			rc = 0;

			if (left > 0) {
				ll = ceil_div_2(left - 1);
				lr = floor_div_2(left - 1);
			} else {
				ll = lr = 0;
			}
			rl = ceil_div_2(right - 1);
			rr = floor_div_2(right - 1);

			left = ll;
			right = rr;

			if (ll == rr || (lr == rr && rl == ll)) {
				lc = plc * 2;
				rc = prc * 2;
			} else if (rl == rr) {
				lc = plc;
				rc = plc + prc * 2;
			} else {
				lc = plc * 2 + prc;
				rc = prc;
			}
		}
		unsigned long long mid;

		if (lc > rc) {
			mid = rc;
		} else {
			mid = lc;
		}

		lc -= mid; rc -= mid;

		if (K * 2 <= rc) {
			ansr = right;
			ansl = right;
		}
		else if (K * 2 <= rc + (mid * 2)) {
			ansr = left;
			ansl = right;
		} else {
			ansr = left;
			ansl = left;
		}

		std::cout << "Case #" << count + 1 << ": ";
		std::cout << ansl << " " << ansr;
		std::cout << std::endl;
	}
	return 0;
}

