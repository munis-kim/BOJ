#include <iostream>

using namespace std;

long long arr[102] = { 0, 1, 1, 1, 2};

int main() {
	int T, N;

	cin >> T;

	for (int i = 5; i < 101; ++i)
		arr[i] = arr[i - 1] + arr[i - 5];

	for (int i = 0; i < T; ++i) {
		cin >> N;
		cout << arr[N] << '\n';
	}

	return 0;
}