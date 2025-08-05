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

char arr[5][15]; // �������� �迭 ����� null���ڷ� �ʱ�ȭ

int main()
{
	int maxSize = 0; // ���� int maxSize = -1;
	string sum;

	for (int i = 0; i < 5; i++)
	{
		string s;
		cin >> s;


		// length() �Լ��� uninsigned �� �����ϱ� ������ ���ǽ��� -1 �� �ع����� (size_t)-1�� ����ȯ�� �Ǹ鼭 ��û ū ���� �Ǿ����
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