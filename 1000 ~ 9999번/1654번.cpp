#include <iostream>
#define max 2147483647
typedef long long ll;
using namespace std;

ll N, K;
ll arr[10002];

ll solve(ll left, ll right) {
	ll mid, piece;
	ll ans = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		piece = 0;
		for (int i = 0; i < K; ++i) {
			piece += (arr[i] / mid);
		}
		if (piece >= N) {
			if (ans < mid)	ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return ans;
}

int main() {
	cin >> K >> N;
	for (int i = 0; i < K; ++i)
		cin >> arr[i];

	cout << solve(1, max);

	return 0;
}