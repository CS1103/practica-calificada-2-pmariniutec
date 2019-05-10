#include <iostream>
#include "arena.h"

int main() {
	Arena arena{};
	arena.load_fights("peleas.txt");
	arena.run();
    return 0;
}
