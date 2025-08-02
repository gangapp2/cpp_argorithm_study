#include <iostream>
#include <string>
using namespace std;

void Boj_1152()
{
	int count = 1;
	string s;

	getline(cin, s); // 한 줄 단위로 입력을 받음 (공백 포함)

	for (int i = 0; i < s.length(); i++) // 처음과 끝 공백은 제외하고 카운팅
	{
		if (s[i] == ' ')
			count++;
	}

	if (s[0] == ' ')
		count--;
	if (s[s.length() - 1] == ' ')
		count--;

	cout << count;
}