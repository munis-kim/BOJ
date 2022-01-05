#include <iostream>

using namespace std;

bool visited[8];
int arr[8];
int N, M;

void solve(int n) {
	if (n == M) {
		for (int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= N; ++i) {
			if (visited[i] == false) {
				visited[i] = true;
				arr[n] = i;
				solve(n + 1);
				visited[i] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cout.tie(NULL);
	
	cin >> N >> M;

	solve(0);

	return 0;
}