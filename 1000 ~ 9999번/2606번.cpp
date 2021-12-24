#include <iostream>
#include <queue>

using namespace std;

bool computer[102][102];
bool visit[102];
int N, M;

int bfs() {
	queue <int> q;
	q.push(1);
	visit[1] = true;
	int count = 0;
	while (q.empty() == 0) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= N; ++i) {
			if (computer[x][i] == true && visit[i] == false) {
				q.push(i);
				count++;
				visit[i] = true;
			}
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	cin >> N >> M;
	int count = 0;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		computer[a][b] = true;
		computer[b][a] = true;
	}

	count = bfs();
	
	cout << count;

	return 0;
}