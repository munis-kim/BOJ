#include <iostream>
#include <queue>

using namespace std;

char lake[1501][1501];
bool visited[1501][1501];
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

bool find_;
int day = 0;
int R, C;

queue<pair<int, int>> swan;
queue<pair<int, int>> water;
queue<pair<int, int>> new_water;
queue<pair<int, int>> swan_go;

void swan_find() {
	while (find_ == false) {

		while (!swan.empty()) {
			pair<int, int> p = swan.front();
			swan.pop();
			int x = p.second;
			int y = p.first;
			for (int i = 0; i < 4; ++i) {
				int next_x = x + dir_x[i];
				int next_y = y + dir_y[i];
				if (next_x < 0 || next_x >= C || next_y < 0 || next_y >= R || visited[next_y][next_x] == true)
					continue;
				if (lake[next_y][next_x] == '.')
					swan.push({ next_y, next_x });
				else if (lake[next_y][next_x] == 'X')
					swan_go.push({ next_y, next_x });
				else if (lake[next_y][next_x] == 'L') {
					find_ = true;
					return;
				}
				visited[next_y][next_x] = true;
			}
		}

		while (!water.empty()) {
			pair<int, int> p = water.front();
			water.pop();
			int x = p.second;
			int y = p.first;
			for (int i = 0; i < 4; ++i) {
				int next_x = x + dir_x[i];
				int next_y = y + dir_y[i];
				if (next_x < 0 || next_x >= C || next_y < 0 || next_y >= R)
					continue;
				if (lake[next_y][next_x] == 'X') {
					new_water.push({ next_y, next_x });
					lake[next_y][next_x] = '.';
				}
			}
		}

		while (!swan_go.empty()) {
			swan.push(swan_go.front());
			swan_go.pop();
		}

		while (!new_water.empty()) {
			water.push(new_water.front());
			new_water.pop();
		}

		day++;
	}

}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	cin >> R >> C;
	bool check = true;


	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> lake[i][j];
			if (lake[i][j] != 'X')
				water.push({ i,j });
			if (lake[i][j] == 'L')
				if (check == true) {
					swan.push({ i,j });
					check = false;
					visited[i][j] = true;
				}
		}
	}

	swan_find();

	cout << day;

	return 0;
}