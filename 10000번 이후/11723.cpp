#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int M;	cin >> M;
	int n = 0, temp;
	string s;
	while (M--) {
		cin >> s;
		if (s == "add") {
			cin >> temp;
			n |= (1 << temp);
		}
		else if (s == "remove") {
			cin >> temp;
			n &= ~(1 << temp);
		}
		else if (s == "check") {
			cin >> temp;
			if (n & (1 << temp))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "toggle") {
			cin >> temp;
			n ^= (1 << temp);
		}
		else if (s == "all")
			n = (1 << 21) - 1;
		else if (s == "empty")
			n = 0;
	}

	return 0;
}
