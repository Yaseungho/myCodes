#include <iostream>
#include <ctime>
using namespace std;

int main() {
	clock_t start1, end1, start2, end2;
	float result1 = 0.0, result2 = 0.0;

	start1 = clock();
	for (int i = 0; i < 100; i++) cout << i << endl;
	end1 = clock();

	result1 = (float)(end1 - result1) / CLOCKS_PER_SEC;

	cout.tie(NULL);
	start2 = clock();
	for (int i = 0; i < 100; i++) cout << i << "\n";
	end2 = clock();

	result2 = (float)(end2 - start2) / CLOCKS_PER_SEC;
	cout << "cout, endl : " << result1 << "ÃÊ\n";
	cout << "cout.tie(NULL), \\n : " << result2 << "ÃÊ\n";
}