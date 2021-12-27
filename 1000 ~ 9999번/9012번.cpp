#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string input;
		cin >> input;
		stack<char> st;
		int lpar = 0, rpar = 0;
		bool result = true;
		for (int i = 0; i < input.size(); ++i)
			st.push(input[i]);

		while (!st.empty()) {
			char c = st.top();
			st.pop();
			if (c == ')')
				rpar++;
			else if (c == '(')
				lpar++;
			if (lpar > rpar)
				result = false;
		}
		if (rpar != lpar)
			result = false;

		if (result)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}