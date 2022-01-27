#include <iostream>
#define MAXN 1000000
using namespace std;

int arr[MAXN + 10];
int sorted[MAXN + 10];

void merge_sort(int s, int e) {
	if (s >= e) return;
	int m = (s + e) / 2;

	merge_sort(s, m);
	merge_sort(m + 1, e);

	int l, r, cur;

	l = cur = s, r = m + 1;
	while (l <= m && r <= e) {
		if (arr[l] <= arr[r])
			sorted[cur++] = arr[l++];
		else
			sorted[cur++] = arr[r++];
	}

	while (l <= m)
		sorted[cur++] = arr[l++];

	while (r <= e)
		sorted[cur++] = arr[r++];

	for (int i = s; i <= e; ++i)
		arr[i] = sorted[i];
}


int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	merge_sort(0, N - 1);

	int left = 0;
	int right = arr[N - 1];
	int answer = 0;
	while (left <= right) {
		long long sum = 0;
		int mid = (left + right) / 2;
		
		for (int i = 0; i < N; ++i) {
			if (arr[i] > mid)
				sum += (arr[i] - mid);
		}
		if (sum >= M) {
			left = mid + 1;
			if (answer < mid)
				answer = mid;
		}
		else
			right = mid - 1;
	}

	cout << answer;

	return 0;
}