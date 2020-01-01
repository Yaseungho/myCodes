#include <iostream>
#include <vector>
using namespace std;
long long D;
class Rule {
public:
	long long A;
	long long B;
	long long C;
	Rule(long long _A, long long _B, long long _C) : A{ _A }, B{ _B }, C{ _C }{}
};
vector<Rule> Rules;

bool func(long long key) {
	long long temp = 0;
	for (long long i = 0; i < Rules.size(); i++) {
		if (key < Rules[i].A) continue;
		if (key > Rules[i].B) {
			temp += (Rules[i].B - Rules[i].A) / Rules[i].C + 1;
		}
		else {
			temp += (key - Rules[i].A) / Rules[i].C + 1;
		}
	}
	if (temp >= D) return true;
	return false;
}

int main() {
	long long N, K, A, B, C, Start = 0, End, mid, result = 0;
	cin >> N >> K >> D;
	End = N + 1;
	while (K--) {
		cin >> A >> B >> C;
		Rules.push_back(Rule(A, B, C));
	}
	while (End - Start > 1) {
		mid = (Start + End) / 2;
		if (func(mid)) {
			result = mid;
			End = mid;
		}
		else Start = mid;
	}

	cout << result;

	return 0;
}