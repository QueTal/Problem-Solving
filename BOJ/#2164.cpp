#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int N;
	cin >> N;
	deque<int> d;
	for (int i = 1; i <= N; i++) {
		d.push_back(i);
	}
	while (d.size() > 1) {
		d.pop_front();
		if (d.size() == 1) break;
		d.push_back(d.front());
		d.pop_front();
	}
	cout << d.front() << "\n";
	return 0;
}