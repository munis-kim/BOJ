#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, temp;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; ++i) {
		cout << v[i] << '\n';
	}

	return 0;
}