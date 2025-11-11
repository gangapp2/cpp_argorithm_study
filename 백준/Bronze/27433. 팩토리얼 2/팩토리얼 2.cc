#include<iostream>
using namespace std;

long long ans = 1;
void Factorial(int n)
{
	if (n <= 0)
		return;
	ans *= n;
	Factorial(--n);
}
int main()
{
	int n;
	cin >> n;
	Factorial(n);
	cout << ans;
}