#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool map[27][27];
bool visit[27][27];
int N;
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, -1, 0, 1 };

int bfs(int y, int x) {
	queue <pair<int, int>> q;
	int count = 0;
	q.push({ y, x });
	visit[y][x] = true;
	while (q.empty() == 0) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int next_x = x + dir_x[i];
			int next_y = y + dir_y[i];
			if (next_x <= 0 || next_x > N || next_y <= 0 || next_y > N)	continue;
			if (map[next_y][next_x] == true && visit[next_y][next_x] == false) {
				q.push({ next_y, next_x });
				count++;
				visit[next_y][next_x] = true;
			}
		}
	}
	return count + 1;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> N;
	string temp;
	int count = 0;
	vector<int> v;
	for (int i = 1; i <= N; ++i) {
		cin >> temp;
		for (int j = 1; j <= N; ++j) {
			map[i][j] = temp[j-1] - '0';
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (map[i][j] == true && visit[i][j] == false) {
				int temp = bfs(i, j);
				v.push_back(temp);
				count++;
			}
		}
	}

	sort(v.begin(), v.end());
	cout << count << endl;
	for (int i : v)
		cout << i << endl;

	return 0;
}