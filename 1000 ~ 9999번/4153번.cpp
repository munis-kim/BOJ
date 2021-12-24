#include <iostream>
#include <cmath>

#define SWAP(X, Y, Z)  ((Z = X), (X = Y), (Y = Z))

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int a, b, c, temp;
	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		if (a > c)	SWAP(a, c, temp);
		if (b > c)	SWAP(b, c, temp);

		if (pow(c, 2) == (pow(a, 2) + pow(b, 2)))
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}