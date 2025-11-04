#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;

    vector<pair<int,int>> vec;
    vec.reserve(N);

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        vec.emplace_back(x, y);
    }

    // y 오름차순, y 같으면 x 오름차순
    sort(vec.begin(), vec.end(),
         [](const pair<int,int>& a, const pair<int,int>& b) {
             if (a.second != b.second) return a.second < b.second; // y
             return a.first < b.first;                             // x
         });

    for (const auto& [x, y] : vec) {
        cout << x << ' ' << y << '\n';
    }
    return 0;
}
