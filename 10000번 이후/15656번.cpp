#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
int arr[8];

void solve(int n) {
	if (n == M) {
		for (int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 0; i < N; ++i) {
			arr[n] = v[i];
			solve(n + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	solve(0);

	return 0;
}