#include <iostream>

using namespace std;

int house[15][15];

int main() {
	int T, n, k;
	cin >> T;

	for (int i = 0; i < 14; ++i) {
		house[0][i] = i + 1;
		house[i + 1][0] = 1;
	}
	for (int i = 1; i < 14; ++i) {
		for (int j = 1; j < 15; ++j)
			house[j][i] = house[j][i - 1] + house[j - 1][i];
	}

	while (T--) {
		cin >> n >> k;
		cout << house[n][k - 1] << endl;
	}

	return 0;
}