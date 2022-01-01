#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, int> m;
	vector<string> answer;
	string temp;

	for (int i = 0; i < N; ++i) {
		cin >> temp;
		m[temp] = 0;
	}
	for (int i = 0; i < M; ++i) {
		cin >> temp;
		if (m.find(temp) != m.end()) {
			answer.push_back(temp);
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << '\n';


	return 0;
}