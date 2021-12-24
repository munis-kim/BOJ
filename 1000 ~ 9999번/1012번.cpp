#include <iostream>
#include <queue>

using namespace std;

int N, M;
bool map[52][52];
bool visit[52][52];
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, -1, 0, 1 };

void dfs(int start_x, int start_y) {
	queue <pair<int, int>> q;
	q.push({ start_x, start_y });
	visit[start_x][start_y] = true;
	while (q.empty() == 0) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int next_x = x + dir_x[i];
			int next_y = y + dir_y[i];
			if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N)	continue;
			if (map[next_x][next_y] == true && visit[next_x][next_y] == false) {
				q.push({ next_x, next_y });
				visit[next_x][next_y] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int count = 0;
		for(int i = 0; i < 52; ++i)
			for (int j = 0; j < 52; ++j) {
				map[i][j] = false;
				visit[i][j] = false;
			}

		int K, X, Y;
		cin >> M >> N >> K;
		for (int i = 0; i < K; ++i) {
			cin >> X >> Y;
			map[X][Y] = true;
		}

		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (map[i][j] == true && visit[i][j] == false) {
					dfs(i, j);
					count++;
				}
			}
		}
		
		cout << count << endl;
	}



	return 0;
}