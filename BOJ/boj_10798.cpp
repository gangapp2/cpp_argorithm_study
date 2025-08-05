#include <iostream>
using namespace std;
void Boj_10798()
{
	char arr[5][15] = { '\0' };

	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	for (int i = 0; i < 15; i++) {
		for (int k = 0; k < 5; k++) {
			if (arr[k][i] != NULL)
				cout << arr[k][i];
		}
	}
}

char arr[5][15]; // 전역으로 배열 선언시 null문자로 초기화

int main()
{
	int maxSize = 0; // 오답 int maxSize = -1;
	string sum;

	for (int i = 0; i < 5; i++)
	{
		string s;
		cin >> s;


		// length() 함수는 uninsigned 를 리턴하기 때문에 조건식을 -1 로 해버리면 (size_t)-1로 형변환이 되면서 엄청 큰 수가 되어버림
		if (maxSize <= s.length())
			maxSize = s.length();

		for (int j = 0; j < s.length(); j++)
			arr[i][j] = s[j];

	}

	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[j][i] == '\0')
				continue;
			sum += arr[j][i];
		}
	}

	cout << sum;
}