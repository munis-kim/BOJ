#include <iostream>

using namespace std;

int arr[21];

int main() {
	int n;
	cin >> n;
	
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i < 20; ++i)
		arr[i] = arr[i - 1] + arr[i - 2];

	cout << arr[n];


	return 0;
}