#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int arr[5002];
int count_arr[5002];

int failFunc(string str) {
	memset(arr, 0, sizeof(arr));
	int j = 0, max = 0;
	int length = str.length();
	for (int i = 1; i < length; ++i) {
		while (str[i] != str[j] && j > 0)	j = arr[j - 1];
		if (str[i] == str[j])
			arr[i] = ++j;
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

void KMP_solve(string str) {
	int ans = 0, temp;
	int length = str.length();
	for (int i = 0; i < length; ++i) {
		temp = failFunc(str.substr(i));
		ans = (ans > temp) ? ans : temp;
	}
	cout << ans << endl;
}

int main() {
	string str;		cin >> str;
	KMP_solve(str);
	return 0;
}