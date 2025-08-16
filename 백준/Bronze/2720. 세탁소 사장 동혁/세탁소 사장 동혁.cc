#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int change;
		int q, d, ni, p;
		cin >> change;
		
		q = change / 25;
		change = change % 25;

		d = change / 10;
		change = change % 10;

		ni = change / 5;
		change = change % 5;

		p = change / 1;

		cout << q << " " << d << " " << ni << " " << p << endl;
	}
}
