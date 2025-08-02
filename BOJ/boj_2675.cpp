#include <iostream>
#include <string>
using namespace std;

void Boj_2675()
{
	int t;
	cin >> t;

	while (t--)
	{
		int i = 0;
		int r;
		char str[21];
		string s;

		cin >> r >> str;

		while (*(str + i))
		{
			for (int k = 0; k < r; k++)
				s.push_back(*(str + i));

			i++;
		}

		cout << s << endl;
	}
}