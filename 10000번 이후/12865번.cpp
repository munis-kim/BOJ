#include <iostream>

using namespace std;

int thing[102];
int weight[102];
int dp[102][100002];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
		cin >> weight[i] >> thing[i];

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			if (j >= weight[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + thing[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];

	return 0;
}