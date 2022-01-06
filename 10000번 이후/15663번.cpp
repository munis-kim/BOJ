#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
int arr[9];
bool visited[9];

void solve(int n) {
	if (n == M) {
		for (int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else {
		int check = -1;
		for (int i = 0; i < N; ++i) {
			if (visited[i] == false && check != v[i]) {
				check = v[i];
				arr[n] = v[i];
				visited[i] = true;
				solve(n + 1);
				visited[i] = false;
			}
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