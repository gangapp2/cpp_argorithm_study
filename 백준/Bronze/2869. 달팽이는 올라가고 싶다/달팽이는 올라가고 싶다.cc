#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int a, b, v;
	int day = 1;
	cin >> a >> b >> v;

	day += (v - a) / (a - b);

	if ((v - a) % (a - b)) // 달팽이가 도착점을 지나치는 경우
		cout << day + 1;
	else
		cout << day;	// 달팽이가 도착점에 딱 맞게 도달하는 경우
}