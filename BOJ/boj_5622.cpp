#include <iostream>
#include <string>
using namespace std;

void Boj_5622()
{
	string s;
	cin >> s;
	int t[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	int sum = 0;

	for (int i = 0; i < s.length(); i++)
	{
		sum += t[s[i] - 'A'];
	}
	cout << sum << endl;
	/*char a = 'A';
	string s;
	cin >> s;

	int time = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] > 86)
			time += 10;
		else if (s[i] > 83)
			time += 9;
		else if (s[i] > 79)
			time += 8;
		else if (s[i] > 76)
			time += 7;
		else if (s[i] > 73)
			time += 6;
		else if (s[i] > 70)
			time += 5;
		else if (s[i] > 67)
			time += 4;
		else
			time += 3;
	}
	cout << time << endl;
	*/
}