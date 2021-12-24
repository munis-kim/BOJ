#include <iostream>
#include <algorithm>
#define max 987654321
using namespace std;

int N, M;
int arr[300002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N >> M;
	int left = 1, right =0;
	for (int i = 0; i < M; ++i) {
		cin >> arr[i];
		if (arr[i] > right)	right = arr[i];
	}

	int mid, ans = max;

	while (left <= right) {
		mid = (left + right) / 2;
		int num = 0;
		for (int i = 0; i < M; ++i) {
			int div = arr[i] / mid;
			int rem = arr[i] % mid;

			if (rem)
				num += div + 1;
			else
				num += div;
		}

		if (num > N) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			if (ans > mid)
				ans = mid;
		}

	}
	
	cout << ans;

	return 0;
}