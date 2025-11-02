#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    iota(v.begin(), v.end(), 1); // 1..n

    cout << "<";

    int idx = 0; // 현재 가리키는 위치(다음 제거 시작점)
    while (!v.empty()) {
        idx = (idx + k - 1) % v.size(); // k번째 사람의 인덱스
        cout << v[idx];
        v.erase(v.begin() + idx);       // 제거 (다음 시작점은 idx 그대로)

        if (!v.empty()) cout << ", ";
    }

    cout << ">";
    return 0;
}