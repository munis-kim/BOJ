#include <iostream>

using namespace std;

int arr[5001];

int main() {
	int N;	cin >> N;

	for (int i = 0; i <= 5001; ++i)
		arr[i] = 9876;

	arr[3] = arr[5] = 1;

	for (int i = 6; i <= N; ++i)
		arr[i] = min(arr[i - 3], arr[i - 5]) + 1;

	if (arr[N] >= 9876)
		cout << -1;
	else
		cout << arr[N];

	return 0;
}