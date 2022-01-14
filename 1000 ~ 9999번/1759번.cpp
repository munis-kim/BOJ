#include <iostream>
#include <algorithm>

using namespace std;

char arr[16];
char temp[16];
int consonant;
int vowel;
int L, C;

void backtracking(int n, int m) {
	if (n == L) {
		if (consonant >= 2 && vowel >= 1) {
			for (int i = 0; i < L; ++i)
				cout << temp[i];
			cout << '\n';
		}
	}
	else {
		for (int i = m; i < C; ++i) {
			temp[n] = arr[i];
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
				vowel++;
				backtracking(n + 1, i + 1);
				vowel--;
			}
			else {
				consonant++;
				backtracking(n + 1, i + 1);
				consonant--;
			}
		}
	}
}

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; ++i)
		cin >> arr[i];

	sort(arr, arr + C);

	backtracking(0, 0);

	return 0;
}