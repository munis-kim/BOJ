#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	int i, temp, tmp;

	for (i = 1; i <= N; ++i) {
		tmp = i;
		temp = i;
		while (tmp) {
			temp += tmp % 10;
			tmp /= 10;
		}
		if (temp == N)
			break;
	}
	if (i <= N)	cout << i;
	else	cout << 0;

	return 0;
}