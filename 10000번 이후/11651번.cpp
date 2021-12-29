#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N;	cin >> N;
	int x, y;

	vector<pair<int, int>> v;

	for(int i = 0; i < N; ++i) {
		cin >> x >> y;
		v.push_back({ y,x });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; ++i)
		cout << v[i].second << " " << v[i].first << '\n';

	return 0;
}