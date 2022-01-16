#include <iostream>

using namespace std;

int arr[1002];
int dp[1002];

int main() {
	int N;	cin >> N;
	int max = 0;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	dp[0] = arr[0];
	max = arr[0];
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j])
				if (dp[i] < dp[j])
					dp[i] = dp[j];
		}
		dp[i] += arr[i];
		if (max < dp[i])	max = dp[i];
	}

	
	cout << max;

	return 0;
}