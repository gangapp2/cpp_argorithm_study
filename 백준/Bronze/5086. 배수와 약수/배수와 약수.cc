#include<iostream>
using namespace std;

int main()
{
	while (true)
	{
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
			break;

		if (a > b)
		{
			if (a % b)
				cout << "neither" << endl;
			else
				cout << "multiple" << endl;
		}
		else if (b > a)
		{
			if (b % a)
				cout << "neither" << endl;
			else
				cout << "factor" << endl;
		}

	}

}