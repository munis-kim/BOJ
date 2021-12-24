#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 20004
#define INF 1000000000

vector<pair<int, int>> v[MAX];
int dist[MAX];

void dijkstra(int start);

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int V, E, K;	cin >> V >> E >> K;

	for (int i = 0; i < E; ++i) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}
	for (int i = 1; i <= V; ++i)		dist[i] = INF;

	dijkstra(K);

	for (int i = 1; i <= V; ++i) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
	return 0;
}

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (pq.empty() == 0) {
		int dist_ = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); ++i) {
			int next = v[cur][i].first;
			int dist_1 = v[cur][i].second;
			if (dist[next] > dist_1 + dist_) {
				dist[next] = dist_1 + dist_;
				pq.push({ dist_1 + dist_, next });
			}
		}
	}
}