#include <iostream>
using namespace std;

int main() {
	int n = 1;
	while (1) {
		int L, P, V, cnt = 0, i;
		cin >> L >> P >> V;
		if (!L && !P && !V) break;
		i = V / P;
		cnt += (i * L);
		cnt += ((V % P) > L ? L : (V % P));
		cout << "Case " << n++ << ": " << cnt << "\n";
	}
	return 0;
}