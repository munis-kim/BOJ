#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N;	cin >> N;
	vector<int> v(N);
	vector<int> v2(8001, 0);
	
	int sum = 0;
	int max = -1, min = 0;
	int most = 0;
	bool second = false;
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		sum += v[i];
		v2[v[i] + 4000]++;
		if (v2[v[i] + 4000] > max)
			max = v2[v[i] + 4000];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < 8001; ++i) {
		if (v2[i] == max) {
			most = i - 4000;
			if (second)
				break;
			second = true;
		}
	}

	max = v[N - 1];
	min = v[0];
	
	cout << round(sum/(double)N) << '\n';
	cout << v[N / 2] << '\n';
	cout << most << '\n';
	cout << max - min;

	return 0;
}