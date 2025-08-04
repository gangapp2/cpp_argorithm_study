#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Boj_1316()
{
    string s;
    int n;
    cin >> n;

    int count = 0;

    while (n--)
    {
        vector<char> v;

        bool isGroup = true;

        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == s[i + 1])
                continue;

            v.push_back(s[i]);
            for (auto data : v)
            {
                if (i == s.length() - 1)
                    break;

                if (data == s[i + 1])
                    isGroup = false;
            }
        }
        if (isGroup)
            count++;
    }

    cout << count;
}
