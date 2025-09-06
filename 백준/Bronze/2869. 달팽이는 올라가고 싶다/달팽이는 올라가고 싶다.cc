#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); 

	int a, b, v;
	int day = 1;
	cin >> a >> b >> v;

	day += (v - a) / (a - b);

	if ((v - a) % (a - b)) 
		cout << day + 1;
	else
		cout << day;
}