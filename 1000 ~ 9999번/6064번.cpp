#include <iostream>

using namespace std;

int upper;

int gcd(int M, int N) {
	if (M < N)
		swap(M, N);

	if (N == 0)
		return M;
	else
		return gcd(N, M % N);
}

int solve(int M, int N, int x, int y) {
	int count = x;
	while ((count % N) != y) {
		if (N == y)
			if (count % N == 0)	return count;
		count += M;
		if (count > upper)	return -1;
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int T, M, N, x, y;
	cin >> T;

	while (T--) {
		cin >> M >> N >> x >> y;

		int temp = gcd(M, N);
		upper = M * N / temp;
		cout << solve(M, N, x, y) << '\n';
	}

	return 0;
}