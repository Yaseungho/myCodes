#include <bits/stdc++.h>
using namespace std;
bool arr[26];

bool Check(string str) {
	for (int i = 0; i < str.length(); i++) {
		int ind = str[i] - 'a';
		if (i > 0 && str[i - 1] != str[i] && arr[ind] == true) return false;
		else arr[ind] = true;
	}
	return true;
}

int main() {
	int n, res = 0;
	cin >> n;
	while (n--) {
		memset(arr, 0, sizeof(arr));
		string str;
		cin >> str;
		if (Check(str)) res++;
	}
	cout << res << "\n";
}