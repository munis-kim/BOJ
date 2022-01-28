#include <iostream>
#include <algorithm>

using namespace std;

int card[500002];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N, M, temp;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> card[i];

	sort(card, card + N);

	cin >> M;
	for (int i = 0; i < M; ++i) {
		int result = 0;
		int left = 0, right = N - 1;
		cin >> temp;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (card[mid] > temp)
				right = mid - 1;
			else if (card[mid] < temp)
				left = mid + 1;
			else {
				result = 1;
				break;
			}
		}
		cout << result << ' ';
	}

	return 0;
}