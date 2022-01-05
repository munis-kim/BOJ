#include <iostream>

using namespace std;

int N, M;
bool visited[9];
int arr[9];

void solve(int n, int m) {
	if (m == M) {
		for (int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = n; i <= N; ++i) {
			if (visited[i] == false) {
				visited[i] = true;
				arr[m] = i;
				solve(i + 1, m + 1);
				visited[i] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cout.tie(NULL);

	cin >> N >> M;

	solve(1, 0);

	return 0;
}