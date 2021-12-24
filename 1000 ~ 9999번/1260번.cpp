#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define endl "\n"
typedef long long ll;

vector<vector<int>> v(1001);
bool visited[1001];

void dfs(int start) {
	visited[start] = true;
	cout << start << " ";
	for (int i : v[start]) {
		if (visited[i] == false)
			dfs(i);
	}
}

void bfs(int start) {
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (q.empty() == 0) {
		int node = q.front();
		cout << node << ' ';
		q.pop();
		for (int i : v[node]) {
			if (visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;
	int start, end;
	for (int i = 0; i < M; ++i) {
		cin >> start >> end;
		v[start].push_back(end);
		v[end].push_back(start);
	}
	for (int i = 0; i < 1001; ++i)
		sort(v[i].begin(), v[i].end());

	dfs(V);
	for (int i = 0; i < 1001; ++i)
		visited[i] = false;
	cout << endl;
	bfs(V);

	return 0;
}