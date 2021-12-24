#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define endl "\n"
#define INF 1000000000

bool maze[102][102];
bool visit[102][102];
int mov[102][102];
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, -1, 0, 1 };
int N, M;

void find() {
	queue <pair<int, int>> q;
	q.push({ 1, 1 });
	mov[1][1] = 1;
	visit[1][1] = true;
	while (q.empty() == 0) {
		int x, y;
		x = q.front().second;
		y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int move_x = x + dir_x[i];
			int move_y = y + dir_y[i];
			if (move_x <= 0 || move_x > M || move_y <= 0 || move_y > N)	continue;
			if (maze[move_y][move_x] == true && visit[move_y][move_x] == 0) {
				q.push({ move_y, move_x });
				mov[move_y][move_x] = mov[y][x] + 1;
				visit[move_y][move_x] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> N >> M;
	string temp;

	for (int i = 1; i <= N; ++i) {	// 입력 부분
		cin >> temp;
		for (int j = 1; j <= M; ++j) {
			maze[i][j] = temp[j - 1] - '0';
		}
	}

	for (int i = 0; i <= 101; ++i) {
		for (int j = 0; j <= 101; ++j)
			mov[i][j] = INF;
	}

	find();
	cout << mov[N][M];

	return 0;
}