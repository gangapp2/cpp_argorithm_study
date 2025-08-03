#include <iostream>
#include <string>
using namespace std;

void Boj_1157()
{
	// A~Z = 65 ~ 90
	// a~z = 97~122

	string s;
	cin >> s;

	int arr[26] = { 0 };

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			arr[s[i] - 'a']++; // 알파벳 순서대로 지정해놓은 인덱스값의 카운트를 +1
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
		else if (max == arr[i]) // 최댓값이 중복됐으면 ?
			answer = '?';
	}

	cout << answer << endl;
}
