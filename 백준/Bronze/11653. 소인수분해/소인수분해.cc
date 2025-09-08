#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    // 1) 2로 나눌 수 있을 만큼 먼저 모두 나누기
    while (n % 2 == 0) {
        cout << 2 << '\n';
        n /= 2;
    }

    // 2) 홀수만 검사: i*i <= n까지만
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }

    // 3) 남은 n이 1보다 크면 n 자체가 마지막 소수
    if (n > 1) cout << n << '\n';

    return 0;
}
