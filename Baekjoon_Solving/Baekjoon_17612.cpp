#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class member {
public:
	int time;//��꿡 �ɸ��� �� �ð�
	int number;//�� ���� �ִ� ������ id
	int id;//�� ���� id
	member(int _t, int _n, int _i) : time{ _t }, number{ _n }, id{ _i } {}
};
vector< member > members;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > counters;
//�� ���븦 �켱���� ������ �̾ƾ���(first : �� ������ ���ð�, second : �� ������ id)

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
		//��õ���� ������ ���ð��� ��ȣ ����
		temp.first += time;
		members.push_back(member(temp.first, temp.second, id));
		//�� �ð�, ����id, ��id ����
		counters.pop();
		counters.push(temp);
		//�� ������ �Էµ� ����� ����
	}
	sort(members.begin(), members.end(), compare);

	for (int i = 0; i < members.size(); i++) {
		result += ((i + 1) * (unsigned long long)members[i].id);
	}
	cout << result << "\n";
}