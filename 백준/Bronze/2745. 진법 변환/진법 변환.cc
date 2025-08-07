#include <iostream>
#include <string>
#include<cmath>
using namespace std;

int main()
{
    int b;
    int dec = 0;
    string n;
    cin >> n >> b;

    for(int i=0;i<n.length();i++)
    {
        int num;

        if (n[i] >= '0' && n[i] <= '9') 
            num = n[i] - '0';
        else if (n[i] >= 'A' && n[i] <= 'Z') // 10진법 이상인 경우
            num = n[i] - 55;

        dec += num * pow(b, n.length() - (i + 1)); // 
    }

    cout << dec;
}