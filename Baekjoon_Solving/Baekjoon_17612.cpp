#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class member {
public:
	int time;//계산에 걸리는 총 시간
	int number;//이 고객이 있는 계산대의 id
	int id;//이 고객의 id
	member(int _t, int _n, int _i) : time{ _t }, number{ _n }, id{ _i } {}
};
vector< member > members;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > counters;
//각 계산대를 우선순위 순으로 뽑아쓰기(first : 이 계산대의 대기시간, second : 이 계산대의 id)

bool compare(const member& temp1, const member& temp2) {
	if (temp1.time == temp2.time) return temp1.number > temp2.number;
	else return temp1.time < temp2.time;
}

int main() {
	unsigned long long result = 0;
	int N, k;
	cin >> N >> k;
	for (int i = 1; i <= k; i++) {
		counters.push({ 0,i });
	}
	for (int i = 0; i < N; i++) {
		int id, time;
		cin >> id >> time;
		pair<int, int> temp = counters.top();
		//추천받은 계산대의 대기시간과 번호 저장
		temp.first += time;
		members.push_back(member(temp.first, temp.second, id));
		//총 시간, 계산대id, 고객id 저장
		counters.pop();
		counters.push(temp);
		//새 정보가 입력된 계산대로 변경
	}
	sort(members.begin(), members.end(), compare);

	for (int i = 0; i < members.size(); i++) {
		result += ((i + 1) * (unsigned long long)members[i].id);
	}
	cout << result << "\n";
}