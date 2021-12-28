#include <iostream>

using namespace std;

int main() {
	int N, num, count = 1;
	cin >> N;

	num = 6;
	
	for (int i = 1; i < N; i += num, num += 6)
		count++;

	cout << count;

}