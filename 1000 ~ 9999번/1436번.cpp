#include <iostream>

using namespace std;

int arr[10002];

int main() {
	int N;	cin >> N;
	int temp, count, max, j = 1;

	for (int i = 666;; ++i) {
		temp = i;
		count = 0;
		max = 0;
		while (temp > 0) {
			if (temp % 10 == 6) {
				count++;
				if (max < count)
					max = count;
			}
			else
				count = 0;
			temp /= 10;
		}
		if (max >= 3)
			arr[j++] = i;
		if (arr[N] != 0)	break;
	}
	cout << arr[N];

	return 0;
}