#include <iostream>

using namespace std;

int N, M;
int arr[8];

void solve(int m) {
	if (m == M) {
		for (int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= N; ++i) {
				arr[m] = i;
				solve(m + 1);
			}
		}
	}

int main() {
	ios_base::sync_with_stdio(false);	cout.tie(NULL);

	cin >> N >> M;

	solve(0);

	return 0;
}