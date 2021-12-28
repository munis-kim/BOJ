#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	deque<int> dq;
	string command;
	int N, num;
	cin >> N;

	while (N--) {
		cin >> command;
		if (command == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (command == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (command == "pop_front") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (command == "pop_back") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (command == "size")
			cout << dq.size() << '\n';

		else if (command == "empty") {
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (command == "front") {
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.front() << '\n';
		}
		else if (command == "back") {
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.back() << '\n';
		}
	}

	return 0;
}