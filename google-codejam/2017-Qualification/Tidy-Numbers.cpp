#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
void hacks() {
	std::cout.sync_with_stdio(false);
}
void clean() {
	std::cin >> std::ws;
}

bool smaller_exist(char& cur, char* number) {
	while (*number != '\0') {
		if (cur > *number) {
			return true;
		}
		number++;
	}
	return false;
}

void mark_nine(char* number) {
	while (*number != '\0') {
		*number = '9';
		number++;
	}
}

int main(int argc, char *argv[]) {
	hacks();
	int T,count=0;
	char number[20];
	for(std::cin >> T; count < T; count++){
		clean();
		std::cin >> number;

		while (true) {
			bool inverted = false;
			for (int i = strlen(number) - 1; i >= 0; i--) {
				char& cur = number[i];
				if (smaller_exist(cur, number + i)) {
					inverted = true;
					cur = cur - 1;
					mark_nine(number + i + 1);
				}
			}
			if (!inverted) {
				break;
			}
		}

		char* print = number;
		while(print[0] == '0'){
			print++;
		}
		std::cout << "Case #" << count + 1 << ": ";
		std::cout << print;
		std::cout << '\n';
	}
	return 0;
}

