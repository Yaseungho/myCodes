#include <iostream>
#include <vector>
using namespace std;
string DP[1001];//dp[N] : N을 만드는 최소 길이, 사전순으로 앞서는 괄호 문자열
string ddd[4] = { "", "ab", "cd", "ef" };


string compare(string str1, string str2) {
	if (str1 == "") return str2;
	if (str2 == "") return str1;
	if (str1.size() > str2.size()) return str2;
	else if (str1.size() < str2.size()) return str1;
	else {
		if (str1 < str2) return str1;
		else return str2;
	}
}

string solve(int n) {
	if (n <= 3) return ddd[n];
	if (!DP[n].empty()) return DP[n];
	string ret = "";
	if (n % 2 == 0) ret = compare(ret, "a" + solve(n / 2) + "b");
	if (n % 3 == 0) ret = compare(ret, "c" + solve(n / 3) + "d");
	if (n % 5 == 0) ret = compare(ret, "e" + solve(n / 5) + "f");
	for (int i = 1; i < n; i++) ret = compare(ret, solve(i) + solve(n - i));
	return DP[n] = ret;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string res = solve(n);
		for (int i = 0; i < res.size(); i++) {
			if (res[i] == 'a') cout << "(";
			if (res[i] == 'b') cout << ")";
			if (res[i] == 'c') cout << "{";
			if (res[i] == 'd') cout << "}";
			if (res[i] == 'e') cout << "[";
			if (res[i] == 'f') cout << "]";
		}
		cout << "\n";
	}
}