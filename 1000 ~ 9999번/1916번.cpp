#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1002
#define INF 1000000000

vector <pair<int, int>> v[MAX];
int cost[MAX];

void dijkstra(int start) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	cost[start] = 0;

	while (pq.empty() == 0) {
		int cost_ = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost[cur] < cost_)	continue;

		for (int i = 0; i < v[cur].size(); ++i) {
			int next = v[cur][i].first;
			int cost_1 = v[cur][i].second;
			int cost_f = cost_ + cost_1;
			if (cost[next] > cost_f) {
				cost[next] = cost_f;
				pq.push({ cost_f, next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N, M, start, end;
	cin >> N >> M;
	
	for (int i = 0; i < M; ++i) {
		int a, b, c;	cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}

	cin >> start >> end;

	for (int i = 0; i < MAX; ++i)	cost[i] = INF;

	dijkstra(start);

	cout << cost[end];
	return 0;
}