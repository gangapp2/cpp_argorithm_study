#include <iostream>
using namespace std;

int main()
{
	int x;
	int line = 1;
	cin >> x;

	while (x-line > 0)
	{
		x -= line;
		line++;
	}

	if (line % 2 == 0) // 짝수 대각선인 경우
		cout << x << "/" << line + 1 - x << endl;
	else
		cout << line + 1 - x << "/" << x << endl;
}
