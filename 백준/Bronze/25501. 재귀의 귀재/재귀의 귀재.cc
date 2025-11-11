#include <iostream>
#include <string>
using namespace std;

int cnt = 0;
int recursion(string &s, int l, int r) 
{
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(string &s) 
{
    return recursion(s, 0, s.size()-1);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        cout << isPalindrome(s) << " " << cnt << '\n';
        cnt = 0;
    }
}