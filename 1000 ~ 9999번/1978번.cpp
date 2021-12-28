#include <iostream>
#include <cmath>

#define num 1000
using namespace std;

bool prime[1001];
int arr[101];

void find_prime() {
	for (int i = 2; i <= num; ++i)
		prime[i] = true;

	for (int i = 2; i <= sqrt(num); ++i) {
		if (prime[i] == false)
			continue;
		for (int j = i + i; j <= num; j += i)
			prime[j] = false;
	}
}

int main() {
	int N, count = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	find_prime();

	for (int i = 0; i < N; ++i) {
		if (prime[arr[i]] == true)
			count++;
	}

	cout << count;

	return 0;
}