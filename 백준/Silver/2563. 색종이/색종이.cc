#include <iostream>
using namespace std;

int main()
{
    int arr[101][101] = { 0 };
    int n;
    cin >> n;

    while (n--) {
        int x, y;
        cin >> x >> y;
        for (int i = y; i < y + 10; i++) {
            for (int j = x; j < x + 10; j++) {
                arr[i][j] = 1; // 그냥 색칠
            }
        }
    }

    int area = 0;

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (arr[i][j] == 1)
                area++;
        }
    }

    cout << area << '\n';
}
