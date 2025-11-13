#include<iostream>
#include<cmath>
using namespace std;

long long a,b,c;

long long Div(long long b)
{
	if (b == 0)
		return 1;

	if (b == 1)
		return a % c;

	long long k = Div(b / 2) % c;

	if (b % 2 == 0)
		return k * k % c;
	else
		return k * k % c * a % c;
}

int main()
{
	cin >> a >> b >> c;

	cout << Div(b);
}