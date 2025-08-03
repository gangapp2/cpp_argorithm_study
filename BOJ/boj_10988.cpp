#include <iostream>
#include <string>
using namespace std;

void Boj_10988()
{
	string s;
	cin >> s;
	bool isPalindrome = true;

	for (int i = 0; i < (s.length() + 1) / 2; i++)
	{
		if (s[i] != s[s.length() - 1 - i])
		{
			isPalindrome = false;
			break;
		}
	}

	cout << isPalindrome;
}