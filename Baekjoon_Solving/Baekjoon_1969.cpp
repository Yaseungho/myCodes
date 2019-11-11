#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N, i, j, M, sum = 0;
	vector<string> vec;
	cin >> N >> M;
	while (N--) {
		string str;
		cin >> str;
		vec.push_back(str);
	}
	string result;
	for (i = 0; i < M; i++) {
		int numA = 0;
		int numC = 0;
		int numG = 0;
		int numT = 0;
		for (j = 0; j < (int)vec.size(); j++) {
			if (vec[j][i] == 'A') numA++;
			if (vec[j][i] == 'C') numC++;
			if (vec[j][i] == 'G') numG++;
			if (vec[j][i] == 'T') numT++;
		}
		pair<char,int> max = make_pair('A',numA);
		if (max.second < numC) max = make_pair('C', numC);
		if (max.second < numG) max = make_pair('G', numG);
		if (max.second < numT) max = make_pair('T', numT);
		result.push_back(max.first);
		sum += ((int)vec.size() - max.second);
	}
	cout << result << "\n" << sum;
	return 0;
}