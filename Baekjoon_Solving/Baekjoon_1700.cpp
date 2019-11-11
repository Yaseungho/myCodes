#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main() {
	int N, K, i, j, k, cnt = 0;
	bool is = true;
	vector<int> vec;
	vector<int> plug;
	cin >> N >> K;
	while (K--) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	while (N--) plug.push_back(-1);
	for (i = 0; i < vec.size(); i++) {
		is = true;
		for (j = 0; j < plug.size(); j++) {
			if (plug[j] == -1 || plug[j] == vec[i]) {
				//cout << j << "번째 플러그("<< plug[j] <<"였음) 에 " << vec[i] << "를 꽂음\n";
				plug[j] = vec[i];
				is = false;
				break;
			}
		}
		if (is) {
			pair<int, int> max = make_pair(0, -1);
			for (j = 0; j < plug.size(); j++) {
				int D = 0;
				for (k = i; k < vec.size(); k++) {
					if (vec[k] == plug[j]) break;
					else D++;
				}
				if (max.second < D) {
					max.first = j;
					max.second = D;
				}
			}
			//cout << max.first << "번째 플러그(" << plug[max.first] << "였음) 에 " << vec[i] << "를 꽂음**\n";
			plug[max.first] = vec[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}