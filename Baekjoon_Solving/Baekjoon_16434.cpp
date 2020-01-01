#include <iostream>
#include <vector>
using namespace std;

class Floor {
public:
	int Statement;
	long long ATK;
	long long HP;
	Floor(int _Statement, int _ATK, int _HP) : Statement{ _Statement }, ATK{ _ATK }, HP{ _HP } {}
};
vector<Floor> vec;
long long ATK;
long long GetTurn(long long HP, long long ATK) {return HP / ATK + (HP % ATK ? 1 : 0);}
bool Game(long long MaxHP) {
	long long CurHP = MaxHP, CurATK = ATK;
	Floor Nfloor = Floor(0, 0, 0);
	for (int i = 0; i < vec.size(); i++) {
		Nfloor = vec[i];
		if (Nfloor.Statement == 1) {
			long long pt = GetTurn(Nfloor.HP, CurATK), et = GetTurn(CurHP, Nfloor.ATK);
			if (et >= pt) CurHP -= (pt - 1) * Nfloor.ATK;
			else return false;
		}
		else if (Nfloor.Statement == 2) {
			if (CurHP + Nfloor.HP > MaxHP) CurHP = MaxHP;
			else CurHP += Nfloor.HP;
			CurATK += Nfloor.ATK;
		}
	}
	return true;
}
int main() {
	long long N, t, a, h, Start = 0, End = 9223372036854775807, mid, result;
	bool temp;
	cin >> N >> ATK;
	while (N--) {
		cin >> t >> a >> h;
		vec.push_back(Floor(t, a, h));
	}
	while (End - Start > 1) {
		mid = (Start + End) / 2;
		temp = Game(mid);
		cout << Start << " " << End << " " << mid << " " << temp << "\n";
		if (temp) {
			result = mid;
			End = mid;
		}
		else Start = mid;
	}
	cout << result;
	return 0;
}