#include <iostream>
#include <string>
using namespace std;

void Boj_2941()
{
	string s;
	cin >> s;
	int count = 0;

	// 반복문의 끝마다 count++ 해준다. 단, 크로아티아 알파벳에 해당하는 경우 i를 증가시켜 반복문에서 건너뛴다
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'c')
		{
			if (s[i + 1] == '=' || s[i + 1] == '-')
				i++;
		}
		else if (s[i] == 'd')
		{
			if (s[i + 1] == '-')
				i++;
			else if (s[i + 1] == 'z')
				if (s[i + 2] == '=')
				{
					i++;
					i++;
				}
		}
		else if (s[i] == 'l')
		{
			if (s[i + 1] == 'j')
				i++;
		}
		else if (s[i] == 'n')
		{
			if (s[i + 1] == 'j')
				i++;
		}
		else if (s[i] == 's')
		{
			if (s[i + 1] == '=')
				i++;
		}
		else if (s[i] == 'z')
		{
			if (s[i + 1] == '=')
				i++;
		}

		count++;
	}

	cout << count;
}
