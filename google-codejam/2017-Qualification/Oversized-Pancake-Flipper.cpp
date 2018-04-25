#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

void hacks() {
	std::cout.sync_with_stdio(false);
}

void clean() {
	std::cin >> std::ws;
}

void flip(char& pancake) {
	if (pancake == '-') {
		pancake = '+';
	} else if (pancake == '+') {
		pancake = '-';
	} else {
		std::cerr << "Unexpected Pancake '" << pancake << "'";
	}
}

int main(int argc, char *argv[])
{
	hacks();
    int T,count=0;
	int flipper_size, pancakes_size, current_pos;
	char pancakes[1000 + 1];

    for(std::cin >> T; count < T; count++) {
		clean();
		bool failed = false;
		int flip_count = 0;

		std::cin.getline(pancakes, 1000 + 1, ' ');
		std::cin >> flipper_size;

		pancakes_size = strlen(pancakes);
		current_pos = 0;

		for (int flippable_size = pancakes_size - flipper_size + 1;
				current_pos < flippable_size;
				current_pos ++)
		{
			char& current = pancakes[current_pos];
			if (current == '-') {
				flip_count ++;
				for (int i = 0; i < flipper_size; ++i) {
					flip(pancakes[current_pos + i]);
				}
			}
		}

		for (;current_pos < pancakes_size; current_pos ++) {
			if (pancakes[current_pos] == '-') {
				failed = true;
			}
		}

		std::cout << "Case #" << count + 1 << ": ";
		if (failed) {
			std::cout << "IMPOSSIBLE";
		} else {
			std::cout << flip_count;
		}
		std::cout << '\n';
    }
    return 0;
}
