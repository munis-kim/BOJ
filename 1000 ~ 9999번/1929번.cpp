#include <iostream>
#include <cmath>

using namespace std;

bool not_prime[1000002];

int main() {
	ios_base::sync_with_stdio(false);	cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	not_prime[0] = true;
	not_prime[1] = true;

	for (int i = 2; i <= sqrt(N); ++i) {
		for (int j = i + i; j <= N; j += i)
			not_prime[j] = true;
	}

	for (int i = M; i <= N; ++i) {
		if (not_prime[i] == false)
			cout << i << '\n';
	}

	return 0;
}