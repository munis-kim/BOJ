#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int n;	cin >> n;
	stack<pair<int, int>> tower;
	for (int i = 1; i <= n; ++i) {
		int temp;	cin >> temp;
		while (!tower.empty()) {
			if (tower.top().second > temp) {
				cout << tower.top().first << ' ';
				break;
			}
			tower.pop();
		}
		if (tower.empty())
			cout << "0 ";
		tower.push({ i, temp });
	}

	return 0;
}