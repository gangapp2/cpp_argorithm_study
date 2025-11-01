#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>

using namespace std;

stringstream out;

unordered_set<int> us;

int visited[1006] = { 0 };

vector<int> vecs;

int findNextMin(int mind) {
	us.erase(mind);
	int NextMin = 2147000000;
	for (int a : us) {
		NextMin = min(NextMin, a);
	}
	return NextMin;

}
void visitedclaer(int N) {
	for (int i = 0; i < N; ++i) {
		visited[i] = 0;
	}
}

int findLastMin(int mindata) { //
	int index = 0;
	for (int i = 0; i < vecs.size(); ++i) {
		if (mindata == vecs[i]) index = i;
	}
	return index;

}


int calcul( int mindata) {
	int mind = mindata;
	int ans = 0;
	vector<int> temp;
	unordered_set<int> tempSet;
	int start = 0;
		for (int i = 0; i < vecs.size(); ++i) {
			if (mind == vecs[i]) {
				visited[i] = 1;
				int lastMinIndex = findLastMin(mind);

				if (lastMinIndex == i) {
					if (tempSet.find(mind) != tempSet.end()) {
						for (int k = lastMinIndex+1; k < vecs.size(); ++k) {
							if(!visited[k]){
								visited[k] = 1;
								ans++;
							}
						}
						ans += temp.size();
							return ans;
					}// 앞에서 찾았고 마지막이면 -> 
					mind = findNextMin(mind);
				}

			}
			else {
				if (!visited[i]) {
					visited[i] = 1;
					temp.push_back(vecs[i]);
					tempSet.insert(vecs[i]);
				}

			}
		}
		ans += temp.size();
	return ans;

}

vector<vector<int>> datasets;
int main() {
	
	int P, K, N;
	int data;
	cin >> P;
	for (int i = 0; i < P; ++i) {
		cin >> K >> N;
		int mindata = 2147000000;
		datasets.push_back({});
		vecs.clear();
		for (int j = 0; j < N; j++) {
			cin >> data;
			us.insert(data);
			mindata = min(mindata, data);
			datasets[i].push_back(data);
		}
		vecs = datasets[i];
		out << i+1<<" "<<calcul(mindata) << endl; 
		us.clear();
		visitedclaer(N);

	}

	cout << out.str();

	return 0;
}