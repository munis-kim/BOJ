#include <iostream>
#include <queue>

using namespace std;

int M, N;
int tomato[1002][1002];
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, -1, 0, 1 };
queue <pair<int, int>> q;

void bfs() {
	while (q.empty() == 0) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int next_x = x + dir_x[i];
			int next_y = y + dir_y[i];
			if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N)	continue;
				if (tomato[next_y][next_x] == 0) {
					q.push({ next_y, next_x });
					tomato[next_y][next_x] = tomato[y][x] + 1;
				}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> M >> N;
	int temp, result = 1, day = -1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> temp;
			tomato[i][j] = temp;
			if (tomato[i][j] == 1)
				q.push({ i, j });
		}
	}
	
	bfs();

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (tomato[i][j] == 0)
				result = 0;
			if (day < tomato[i][j])
				day = tomato[i][j];
		}
	}
	if (result == 0)
		cout << -1;
	else
		cout << day - 1;
	
	return 0;
}