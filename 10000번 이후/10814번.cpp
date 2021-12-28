#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N;
	cin >> N;

	int age;
	string name;

	vector <vector<string>> v(201);
	for (int i = 0; i < N; ++i) {
		cin >> age >> name;
		v[age].push_back(name);
	}

	for (int i = 1; i < 201; ++i) {
		if (v[i].size() > 0) {
			for (int j = 0; j < v[i].size(); ++j) {
				cout << i << " " << v[i][j] << '\n';
			}
		}
	}

	return 0;
}