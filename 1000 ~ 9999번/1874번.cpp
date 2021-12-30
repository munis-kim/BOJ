#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int n;	cin >> n;
	int num, num_1 = 1;
	stack<int> st;
	vector<char> v;

	while (n--) {
		cin >> num;
		while (num_1 <= num) {
			st.push(num_1++);
			v.push_back('+');
		}

		if (st.top() == num) {
			st.pop();
			v.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	int temp = v.size();
	for (int i = 0; i < temp; ++i)
		cout << v[i] << '\n';


	return 0;
}