#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int n,top,number;
deque<pair<int, int>> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		dq.push_back(make_pair(i, num));
	}

	number = dq.front().second;
	cout << dq.front().first << " ";

	dq.pop_front(); // 터진거 제거

	while (!dq.empty()) {
		if (number > 0) { // 양
			for (int i = 0; i < number - 1; i++) { // 터진거 빼고 다시 deque생성
				dq.push_back(dq.front());
				dq.pop_front();
			}
			number = dq.front().second;
			cout << dq.front().first << " ";
			dq.pop_front();
		}
		else { // 음
			for (int i = 0; i > number + 1; i--) { // 반대로 deque생성
				dq.push_front(dq.back());
				dq.pop_back(); // -1 2 1 -> 1 -1 2 1 -> 1 -1 2 -> 2 1 -1 2 -> 2 1 -1
			}
			number = dq.back().second;
			cout << dq.back().first << " ";
			dq.pop_back();
		}

	}
}