#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct conference {
	int start;
	int end;
};

bool cmp(conference a, conference b) {
	if (a.end == b.end)
		return a.start < b.start;
	else
		return a.end < b.end;
}

int main() {
	int N;
	cin >> N;
	vector <conference> con(N);

	for (int i = 0; i < N; ++i) {
		cin >> con[i].start >> con[i].end;
	}

	sort(con.begin(), con.end(), cmp);

	int ans = 0;
	int time = 0;

	for (int i = 0; i < N; ++i) {
		if (time <= con[i].start) {
			time = con[i].end;
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}