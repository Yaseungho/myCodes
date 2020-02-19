#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> List;
	int N, K, result = 0, cnt;
	list<int>::iterator iter;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) List.push_back(i); 
	iter = List.begin();
	N--;
	cout << "<";
	while (N--) {
		for (int i = 1; i < K; i++) {
			if (*iter == List.back()) iter = List.begin();
			else iter++;
		}
		if (*iter == List.back()) {
			cout << *iter << ", ";
			List.erase(iter--);
			iter = List.begin();
		}
		else {
			cout << *iter << ", ";
			List.erase(iter++);
		}
	}
	cout << List.front() << ">\n";
}