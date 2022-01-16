#include <iostream>

using namespace std;

int arr[1002];
int dp[1002];

int main() {
	int N;	cin >> N;
	int max = 0, temp;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	dp[0] = 1;
	for (int i = 1; i < N; ++i) {
		temp = 0;
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j])
				if (temp < dp[j])	temp = dp[j];
		}
		dp[i] = temp + 1;
		if (max < dp[i])	max = dp[i];
	}
	if (N == 1)	cout << 1;
	else
		cout << max;
	
	return 0;
}