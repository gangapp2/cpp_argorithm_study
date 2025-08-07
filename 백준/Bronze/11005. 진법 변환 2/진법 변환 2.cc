#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n,b;
    string res;

    cin >> n >> b;

    while (n>0)
    {
        int temp = n % b;
        if (temp >= 0 && temp <= 9)
            res += (temp + '0');
        else
            res += (temp - 10 + 'A');
        n /= b;
    }

    for (int i = res.length()-1;i>=0; i--)
        cout << res[i];

}
