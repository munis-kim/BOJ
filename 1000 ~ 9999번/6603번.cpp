#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[7];

void solve(vector<int> v, int k, int n, int m) {
	if (m == 6) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = n; i < k; ++i) {
			arr[m] = v[i];
			solve(v, k, i + 1, m + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	while (true) {
		int k, temp;
		vector<int> v;
		cin >> k;
		if (k == 0)
			return 0;
		for (int i = 0; i < k; ++i) {
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());

		solve(v, k, 0, 0);
		cout << '\n';
	}

	return 0;
}