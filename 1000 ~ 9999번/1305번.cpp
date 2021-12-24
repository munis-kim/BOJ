#include <iostream>
#include <string>
using namespace std;

int arr[1000002];

int main() {
	int length, j;
	string ad;
	cin >> length >> ad;
	j = 0;
	for (int i = 1; i < length; ++i) {
		while ((j > 0) && (ad[i] != ad[j]))
			j = arr[j - 1];
		if (ad[i] == ad[j])
			arr[i] = ++j;
	}

	cout << length - arr[length - 1] << endl;

	return 0;
}