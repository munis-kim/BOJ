#include <iostream>

using namespace std;

int main() {
	int r = 31, M = 1234567891, L;
	string word;
	long long H = 0, pow= 1;

	cin >> L >> word;

	for (int i = 0; i < L; ++i) {
		H += ((word[i] - 'a' + 1) * pow) % M;
		H %= M;
		pow *= r;
		pow %= M;
	}

	cout << H;

	return 0;
}