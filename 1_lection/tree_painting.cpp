#include <iostream>
#include <algorithm>

void tree_paint(int p, int v, int q, int m) {

	int start_v = p - v;
	int end_v = p + v;

	int start_m = q - m;
	int end_m = q + m;
	
	int common_start = std::max(start_v, start_m);
	int common_end = std::min(end_v, end_m);

	int trees_painted = 0;
	
	if (common_start <= common_end) {
		trees_painted = std::abs(std::max(end_v,end_m) - std::min(start_m, start_v)) + 1;
	}

	else {
		trees_painted = std::abs(start_v - end_v) + std::abs(start_m - end_m) + 2;
	}

	std::cout << trees_painted;

}


int main() {

	int p, v, q, m;

	std::cin >> p >> v;

	std::cin >> q >> m;

	tree_paint(p, v, q, m);

	return 0;
}
