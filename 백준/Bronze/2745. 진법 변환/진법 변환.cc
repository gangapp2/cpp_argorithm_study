#include <iostream>
#include <string>
#include<cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int b;
    int res = 0;
    string n;
    cin >> n >> b;

    for(int i=0;i<n.length();i++)
    {
        int num;

        if (n[i] >= '0' && n[i] <= '9') 
            res += (n[i] - '0')* pow(b, n.length() - (i + 1));
        else if (n[i] >= 'A' && n[i] <= 'Z') // 10진법 이상인 경우
            res += (n[i] - 'A' + 10) * pow(b, n.length() - (i + 1));
    }

    cout << res;
}
