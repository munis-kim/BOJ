#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int arr[1000002];

void failFunc(string s) {
	memset(arr, 0, sizeof(arr));
	int j = 0;
	int length = s.length();
	for (int i = 1; i < length; ++i) {
		while (s[i] != s[j] && j > 0)	j = arr[j - 1];
		if (s[i] == s[j])
			arr[i] = ++j;
	}
}

int main() {
	string s;
	while (1) {
		cin >> s;
		if (s == ".")
			break;
		failFunc(s);
		int length = s.length();
		int arr_repeat = arr[length - 1];
		if (length % (length - arr_repeat) != 0)
			cout << 1 << '\n';
		else
			cout << (length / (length - arr_repeat)) << '\n';
	}
	return 0;
}