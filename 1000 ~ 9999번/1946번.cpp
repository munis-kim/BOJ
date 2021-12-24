#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N;
	int a, b;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> N;
		vector<pair<int, int>> v(N);
		int ans = 0;
		for (int j = 0; j < N; ++j) {
			cin >> a >> b;
			v[j].first = a;
			v[j].second = b;
		}
		sort(v.begin(), v.end());
		
		int min = 1000000;
		for (int j = 0; j < N; ++j) {
			if (min > v[j].second) {
				ans++;
				min = v[j].second;
			}
		}

		cout << ans << endl;
	}

	return 0;
}