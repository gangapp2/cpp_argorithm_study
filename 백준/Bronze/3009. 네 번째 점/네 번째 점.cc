#include<iostream>
using namespace std;

int main()
{
	// x, y �� �� ��� �������� �ΰ��� ���� �������־����
	int x[3] = {};
	int y[3] = {};

	int n = 3;
	for (int i = 0; i < 3; i++)
	{
		cin >> x[i] >> y[i];
	}

	// ���� x�� �� �ɷ���
	if (x[0] == x[1])
		cout << x[2] << " ";
	else if (x[0] == x[2])
		cout << x[1] << " ";
	else
		cout << x[0] << " ";

	// ���� y�� �� �ɷ���
	if (y[0] == y[1])
		cout << y[2];
	else if (y[0] == y[2])
		cout << y[1];
	else
		cout << y[0];
}