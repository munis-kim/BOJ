#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check[1002];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int count = 0;
	int N, M, u, v;
	cin >> N >> M;

	vector<vector<int>> component(N+1);
	queue<int> q;

	for (int i = 0; i < M; ++i) {
		cin >> u >> v;
		component[u].push_back(v);
		component[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i) {
		if (check[i] == true)
			continue;
		
		else {
			count++;
			q.push(i);
			while (!q.empty()) {
				int front = q.front();
				q.pop();
				if (check[front] == true)
					continue;
				else {
					check[front] = true;
					for (int j = 0; j < component[front].size(); ++j) {
						if (component[front][j] == true)
							continue;
						else
							q.push(component[front][j]);
					}
				}
			}
		}
	}

	cout << count;

	return 0;
}