#include <bits/stdc++.h>
using namespace std;
vector<int> A, B;
int N, DP[2][402][402], temp;
//DP[n][a][b] = n���� ���� ��������, ���� ���� a��, �Ʒ��� ���� b�� �������� ������

int main() {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 401; j++)
			for (int k = 0; k < 401; k++)
				DP[i][j][k] = -200000;
	DP[0][0][0] = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp) A.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp) B.push_back(temp);
	}
	int Asz = A.size(), Bsz = B.size();
	for (int i = 1; i <= N; i++) {
		for (int a = 0; a <= Asz; a++) {
			for (int b = 0; b <= Bsz; b++) {
				int& now = DP[i % 2][a][b];
				now = DP[(i - 1) % 2][a][b];
				if (a > 0) now = max(now, DP[(i - 1) % 2][a - 1][b]);
				if (b > 0) now = max(now, DP[(i - 1) % 2][a][b - 1]);
				if (a > 0 && b > 0) now = max(now, A[Asz - a] * B[Bsz - b] + DP[(i - 1) % 2][a - 1][b - 1]);
			}
		}
	}
	cout << DP[N % 2][Asz][Bsz] << "\n";
}