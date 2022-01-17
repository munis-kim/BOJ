#include <iostream>

using namespace std;

int main() {
	int X;
	cin >> X;
	int count = 0;
	while (X > 0) {
		if ((X & 1) == 1)
			count++;
		X >>= 1;
	}
	cout << count;

	return 0;
}