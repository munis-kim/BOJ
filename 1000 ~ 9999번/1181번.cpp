#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	else
		return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N;	cin >> N;
	vector<string> v;
	string temp;
	for(int i = 0; i < N; ++i) {
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), compare);

	temp = v[0];
	cout << v[0] << '\n';

	for (int i = 1; i < N; ++i) {
		if (temp == v[i])	continue;
		cout << v[i] << '\n';
		temp = v[i];
	}

	return 0;
}