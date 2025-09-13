#include<iostream>
using namespace std;

int main()
{
	// x, y 각 축 모두 같은값의 두개의 쌍을 가지고있어야함
	int x[3] = {};
	int y[3] = {};

	int n = 3;
	for (int i = 0; i < 3; i++)
	{
		cin >> x[i] >> y[i];
	}

	// 같은 x축 쌍 걸러줌
	if (x[0] == x[1])
		cout << x[2] << " ";
	else if (x[0] == x[2])
		cout << x[1] << " ";
	else
		cout << x[0] << " ";

	// 같은 y축 쌍 걸러줌
	if (y[0] == y[1])
		cout << y[2];
	else if (y[0] == y[2])
		cout << y[1];
	else
		cout << y[0];
}