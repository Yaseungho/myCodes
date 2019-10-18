#include <iostream>
#include <string>
int main() {
	int t, a;
	std::cin >> t;
	while (t--) {
		std::string Ps = { 0 };
		std::cin >> Ps;
		a = 0;
		if (Ps.size() >= 2 && Ps.size() <= 50) {
			for (int i = 0; i < Ps.size(); i++) {
				if (Ps[i] == '(') a++;
				if (Ps[i] == ')') a--;
				if (a < 0) a += 999;
			}
			if (a == 0 && Ps[0] == '(' && Ps[Ps.size() - 1] == ')') std::cout << "YES\n";
			else std::cout << "NO\n";
		}
	} return 0;
}