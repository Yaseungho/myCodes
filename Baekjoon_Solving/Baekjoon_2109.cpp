#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class lecture {
public:
	int day;
	int pay;
	lecture(int _d, int _p) : day{ _d }, pay{ _p }{}
};
vector<lecture> lectures;
bool arr[10001];
bool compare(const lecture& a, const lecture& b) {
	return a.pay > b.pay;
}

int main() {
	int N, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int p, d;
		cin >> p >> d;
		lectures.push_back(lecture{ d,p });
	}
	sort(lectures.begin(), lectures.end(), compare);
	for (int i = 0; i < N; i++) {
		for (int j = lectures[i].day; j > 0; j--) {
			if (arr[j] == 0) {
				arr[j] = 1;
				sum += lectures[i].pay;
				break;
			}
		}
	}
	cout << sum << "\n";
}