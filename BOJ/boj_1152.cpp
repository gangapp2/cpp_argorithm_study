#include <iostream>
#include <string>
using namespace std;

void Boj_1152()
{
	int count = 1;
	string s;

	getline(cin, s); // �� �� ������ �Է��� ���� (���� ����)

	for (int i = 0; i < s.length(); i++) // ó���� �� ������ �����ϰ� ī����
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