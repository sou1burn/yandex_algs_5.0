#include <iostream>
#include <algorithm>
#include <sstream>
#include<vector>



int main() {

	std::string s1;
	std::string s2;
	int home;

	std::cin >> s1;
	std::cin >> s2;
	std::cin >> home;
	std::vector<int> first_match(2);
	std::vector<int> second_match(2);
	int j = 0;
	int k = 0;

	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] >= '0' && s1[i] <= '5') {
			first_match[j] = s1[i] - '0';
			j++;
		}
	}
	for (int i = 0; i < s2.size(); ++i) {
		if (s2[i] >= '0' && s2[i] <= '5') {
			second_match[k] = s2[i] - '0';
			k++;
		}
	}
	
	int team1_goals = first_match[0] + second_match[0];
	int team2_goals = first_match[1] + second_match[1];

	int team1_away = (home == 1) ? second_match[0] : first_match[0];
	int team2_away = (home == 1) ? first_match[1] : second_match[1];

	int needed = 0;

	while (true) {
		int final_goals = team1_goals + needed;
		if (final_goals > team2_goals || (final_goals == team2_goals && team1_away + needed > team2_away) ||
			(final_goals > team2_goals && team1_away + needed - team2_away < final_goals - team2_goals)) {
			break;
		}
		needed++;
	}
	std::cout << needed;



	return 0;
}