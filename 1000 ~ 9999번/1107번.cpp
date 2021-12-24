#include <iostream>
#include <cmath>
#define MIN(a,b)	(a) > (b) ? (b) : (a)
using namespace std;

bool key[10];

int search(int num) {
	int len = 0; 
	if (num == 0) {
		if (key[0] == false)	return 0;
		else					return 1;
	}
	else {
		while (num > 0) {
			if (key[num % 10] == false)	return 0;
			num /= 10;
			len += 1;
		}
	}
	return len;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 0; i < 10; ++i)
		key[i] = true;

	int N, M;	cin >> N >> M;
	int temp;
	while (M--) {
		cin >> temp;
		key[temp] = false;
	}

	int channel_min = abs(100 - N);

	for (int i = 0; i < 1000000; ++i) {
		int len = search(i);
		if (len > 0) {
			temp = abs(N - i) + len;
			channel_min = MIN(channel_min, temp);
		}
	}

	cout << channel_min;
		
	return 0;
}