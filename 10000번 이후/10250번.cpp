#include <iostream>

using namespace std;

int main() {
	int T, H, W, N;
	int row, column;
	cin >> T;
	while (T--) {
		cin >> H >> W >> N;
		if (N > H) {
			column = N / H;
			row = N % H;
			if (row == 0) {
				row = H;
				column -= 1;
			}
			cout << row * 100 + column + 1 << endl;
		}
		else
			cout << N * 100 + 1 << endl;
	}

	return 0;
}