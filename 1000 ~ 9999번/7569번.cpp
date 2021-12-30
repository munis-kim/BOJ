#include <iostream>
#include <queue>

using namespace std;

int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };
int dir_z[2] = { -1, 1 };

int tomato[102][102][102];
int day[102][102][102];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	int M, N, H;
	cin >> M >> N >> H;

	int max = -1, bp = 0;
	queue<pair<int, pair<int, int>>> q;

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					q.push({ i, { j,k } });
					day[i][j][k] = 1;
				}
				if (tomato[i][j][k] == -1)
					day[i][j][k] = -1;
			}
		}
	}

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second.first;
		int c = q.front().second.second;
		q.pop();
		
		for (int i = 0; i < 4; ++i) {
			int x = c + dir_x[i];
			int y = b + dir_y[i];

			if (x < 0 || x >= M || y < 0 || y >= N) continue;
			if (day[a][y][x] == -1)	continue;
			if (day[a][y][x] == 0) {
				q.push({ a, {y, x} });
				day[a][y][x] = day[a][b][c] + 1;
			}
		}

		for (int i = 0; i < 2; ++i) {
			int z = a + dir_z[i];

			if (z < 0 || z >= H)	continue;
			if (day[z][b][c] == -1) continue;
			if (day[z][b][c] == 0) {
				q.push({ z, {b, c} });
				day[z][b][c] = day[a][b][c] + 1;
			}
		}
	}

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if (day[i][j][k] == 0) {
					max = 0;
					bp = 1;
					break;
				}
				else {
					if (max < day[i][j][k])
						max = day[i][j][k];
				}
			}
			if (bp == 1)
				break;
		}
		if (bp == 1)
			break;
	}


	cout << max - 1;


	return 0;
}