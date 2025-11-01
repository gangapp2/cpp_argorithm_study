#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;
unordered_map<char, vector<char>> um;

ostringstream out;

bool find(char start, char end) {
	vector<char> temp;
	for (char target : um[start]) {
		if (target == end) {
			return true;
		}
		temp.push_back(target);
	}
	for (char newtarget : temp) {
		if(find(newtarget, end)) return true;
	}
	return false;
}
int main() {
	int N, M;
	cin>> N;

	string a;
	string is;
	string b;
	for (int i = 0; i < N; ++i) {
		cin>> a>>is>>b;
		vector<char> s;
		um[a[0]] = s;
		um[a[0]].push_back(b[0]);
	}
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> a >> is >> b;
		char start = a[0];
		char end = b[0];
		if (find(start, end)) {
			out << "T" << "\n";
		}
		else {
			out << "F" << "\n";
		}

	}
	

	cout << out.str();



	return 0;
}