#include<iostream>
using namespace std;

int main()
{
	int a, b, v;
	cin >> a >> b >> v;

	int day = 1;

	day += (v - a) / (a - b);

	if ((v - a) % (a - b))
		cout << day + 1;
	else
		cout << day;

}