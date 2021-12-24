#include <iostream>
#include <string>
using namespace std;

#define endl '\n'

int arr[1000002];
int ans[1000002];

void fail(string P, int P_length) {
	int j = 0;
	for (int i = 1; i < P_length; ++i) {
		while (P[i] != P[j] && j > 0)
			j = arr[j - 1];
		if (P[i] == P[j])
			arr[i] = ++j;
	}
}

int KMP(string T, string P, int T_length, int P_length) {
	int j = 0, index = 0, count = 0;
	for (int i = 0; i < T_length; ++i) {
		while (T[i] != P[j] && j > 0)
			j = arr[j - 1];
		if (T[i] == P[j]) {
			if (j == P_length - 1) {
				ans[index++] = i - P_length + 2;
				count++;
				j = arr[j];
			}
			else	j++;
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string T, P;
	int T_length, P_length, sum;
	getline(cin, T);
	getline(cin, P);
	T_length = T.length();
	P_length = P.length();

	fail(P, P_length);
	sum = KMP(T, P, T_length, P_length);
	cout << sum << endl;
	for (int i = 0; i < sum; ++i)
		cout << ans[i] << " ";
	return 0;
}