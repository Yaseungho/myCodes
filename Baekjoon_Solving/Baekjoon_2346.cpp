#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec;
	int N, val, ind = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> val;
		vec.push_back(val);
	}
	val = vec[ind];
	cout << ind + 1 << " ";
	vec[ind] = 0;
	if (val > 0) ind++;
	else ind = vec.size() - 1;
	N--;
	while (N--) {
		if (val > 0) {
			for (int i = (vec[ind] == 0 ? 0 : 1); i < val; i++) {
				if (ind == (int)vec.size() - 1) {
					ind = 0;
					if (vec[ind] == 0) i--;
				}
				else {
					ind++;
					if (vec[ind] == 0) i--;
				}
			}
		}
		else {
			val *= -1;
			for (int i = (vec[ind] == 0 ? 0 : 1); i < val; i++) {
				if (ind == 0) {
					ind = (int)vec.size() - 1;
					if (vec[ind] == 0) i--;
				}
				else {
					ind--;
					if (vec[ind] == 0) i--;
				}
			}
		}
		val = vec[ind];
		cout << ind + 1 << " ";
		vec[ind] = 0;
		if (val > 0) {
			if (ind + 1 == (int)vec.size()) ind = 0;
			else ind++;
		}
		else {
			if (ind == 0) ind = (int)vec.size() - 1;
			else ind--;
		}
	}
}