#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	// A~Z = 65 ~ 90
	// a~z = 97~122

	string s;
	cin >> s;

	int arr[26] = { 0 };
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			arr[s[i] - 'a']++;
		else
			arr[s[i] - 'A']++;
	}

	int max = arr[0];
	char answer = 'A';

	for (int i = 1; i < 26; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			answer = 'A' + i;
		}
		else if (max == arr[i])
			answer = '?';
	}

	cout << answer << endl;


}