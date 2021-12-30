#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	int K, temp, sum = 0;
	cin >> K;

	stack<int> st;

	for (int i = 0; i < K; ++i) {
		cin >> temp;
		if (temp == 0)
			st.pop();
		else
			st.push(temp);
	}

	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}

	cout << sum;

	return 0;
}