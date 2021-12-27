#include <iostream>
#include <stack>

using namespace std;

int main() {
	int N;
	cin >> N;
	stack<int> st;

	while (N--) {
		int num;
		string command;
		cin >> command;
		if (command == "push") {
			cin >> num;
			st.push(num);
		}
		else if (command == "top") {
			if (st.empty())
				cout << -1 << endl;
			else
				cout << st.top() << endl;
		}
			
		else if (command == "size")
			cout << st.size() << endl;

		else if (command == "empty")
			cout << st.empty() << endl;

		else if (command == "pop") {
			if (st.empty())
				cout << -1 << endl;
			else {
				cout << st.top() << endl;
				st.pop();
			}
		}

	}

	return 0;
}