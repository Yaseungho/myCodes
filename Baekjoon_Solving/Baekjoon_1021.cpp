#include <iostream>
#include <list>
using namespace std;
list<int> List;

void Two() {
	List.push_back(List.front());
	List.pop_front();
}

void Three() {
	List.push_front(List.back());
	List.pop_back();
}

int main() {
	int N, M, val, result = 0, cnt;
	list<int>::iterator iter;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) List.push_back(i);
	while (M--) {
		cin >> val;
		iter = List.begin();
		cnt = 1;
		while (1) {
			if (*iter == val) {
				if (cnt * 2 <= N + 2) {
					for (int i = 1; i < cnt; i++) {
						Two();
						result++;
					}
					List.pop_front();
					N--;
				}
				else {
					for (int i = 0; i <= N - cnt; i++) {
						Three();
						result++;
					}
					List.pop_front();
					N--;
				}
				break;
			}
			else iter++, cnt++;
		}
	}
	cout << result;
}