#include <iostream>
#include <string>
using namespace std;

void Boj_2908()
{
	/* 함수 사용 버전*/
	string str1;
	string str2;
	cin >> str1 >> str2;

	swap(str1[0], str1[2]);
	swap(str2[0], str2[2]);

	int res = stoi(str1) > stoi(str2) ? stoi(str1) : stoi(str2);

	cout << res << endl;

	/*char* res = nullptr;
	char str1[4];
	char str2[4];
	cin >> str1 >> str2;

	for (int i = 2; i >= 0; i--)
	{
		if (str1[i] > str2[i])
		{
			res = str1;
			break;
		}
		else if(str1[i] < str2[i])
		{
			res = str2;
			break;
		}
	}

	for (int i = 2; i >= 0; i--)
		cout << res[i];

	cout << endl;
	*/
}