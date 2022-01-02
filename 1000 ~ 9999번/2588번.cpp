#include <iostream>

using namespace std;

int main() {
	int a, b, temp = 10;
	cin >> a >> b;

	int b_1 = b;
	for (int i = 0; i < 3; ++i) {
		cout << a * (b_1 % temp) << endl;
		b_1 /= 10;
	}

	cout << a * b;
	
	return 0;
}