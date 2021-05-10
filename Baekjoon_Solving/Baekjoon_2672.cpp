#include <bits/stdc++.h>
using namespace std;

class Rect
{
public:
	double x1, y1, x2, y2;
};
vector<Rect> Rects;
vector<double> xPos;

bool IsIncluded(double s1, double e1, double s2, double e2) {
	if (e1 <= s2 || e2 <= s1) return false;
	else return true;
}

int main() {
	int N;
	double res = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		double x, y, w, h;
		cin >> x >> y >> w >> h;
		Rects.push_back(Rect{ x, y, x + w, y + h });
		xPos.push_back(x);
		xPos.push_back(x + w);
	}
	sort(xPos.begin(), xPos.end());
	xPos.erase(unique(xPos.begin(), xPos.end()), xPos.end());
	for (int i = 1; i < (int)xPos.size(); i++) {
		double ps = xPos[i - 1], pe = xPos[i];//구간
		vector<pair<double, double>> included;//구간안에 포함된 직사각형들의 y좌표 저장
		for (int j = 0; j < N; j++) {
			if (IsIncluded(Rects[j].x1, Rects[j].x2, ps, pe)) {
				included.push_back({ Rects[j].y1, Rects[j].y2 });
			}
		}
		sort(included.begin(), included.end());
		double s = -1, e = -1, cnt = 0;
		for (int j = 0; j < (int)included.size(); j++) {
			double ns = included[j].first, ne = included[j].second;
			if (IsIncluded(s, e, ns, ne)) {
				s = min(s, ns);
				e = max(e, ne);
			}
			else {
				cnt += (e - s);
				s = ns;
				e = ne;
			}
		}
		cnt += (e - s);
		res += (pe - ps) * cnt;
	}
	if (res == (int)res) cout << res << "\n";
	else {
		cout << fixed;
		cout.precision(2);
		cout << res << "\n";
	}
}