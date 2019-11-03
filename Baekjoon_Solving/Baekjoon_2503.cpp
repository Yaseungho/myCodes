#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool arr[9][9][9];

class Number {
public:
	int first;
	int second;
	int third;
	Number(int f, int s, int t) : first{ f }, second{ s }, third{ t }{}
};

int NumOfSame(Number temp1, Number temp2) {
	int sum = 0;
	if (temp1.first == temp2.first) sum++;
	if (temp1.first == temp2.second) sum++;
	if (temp1.first == temp2.third) sum++;
	if (temp1.second == temp2.first) sum++;
	if (temp1.second == temp2.second) sum++;
	if (temp1.second == temp2.third) sum++;
	if (temp1.third == temp2.first) sum++;
	if (temp1.third == temp2.second) sum++;
	if (temp1.third == temp2.third) sum++;
	return sum;
}

int NumOfStrike(Number temp1, Number temp2) {
	int sum = 0;
	if (temp1.first == temp2.first) sum++;
	if (temp1.second == temp2.second) sum++;
	if (temp1.third == temp2.third) sum++;
	return sum;
}

void eraseFalse(Number solve, int strike, int ball) {
	int sum = strike + ball;
	int i, j, k;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			for (k = 1; k <= 9; k++) {
				Number temp(i, j, k);
				if (NumOfSame(temp, solve) != sum && !arr[i - 1][j - 1][k - 1]) {
					arr[i - 1][j - 1][k - 1] = true;
				}
				if (NumOfStrike(temp, solve) != strike && !arr[i - 1][j - 1][k - 1]) {
					arr[i - 1][j - 1][k - 1] = true;
				}
			}
		}
	}
}

int main() {
	int T, strike, ball, i, j, k, ret = 0;
	
	for (i = 0; i < 9; i++) {
		arr[i][i][i] = true;
		for (j = 0; j < 9; j++) {
			arr[i][j][j] = true;
			arr[j][i][j] = true;
			arr[j][j][i] = true;
		}
	}
	cin >> T;
	while (T--) {
		string number;
		cin >> number;
		Number solve(number[0] - 48, number[1] - 48, number[2] - 48);
		cin >> strike >> ball;
		eraseFalse(solve, strike, ball);
	}
	ret = 0;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			for (k = 0; k < 9; k++) {
				if (!arr[i][j][k]) ret++;
			}
		}
	}
	cout << ret;
	return 0;
}