#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int a, b, v;
	int day = 1;
	cin >> a >> b >> v;

	// 목표 거리를 하루에 가는 거리로 나누어 소요되는 총 일수를 구한다
	day += (v - a) / (a - b); // v-a = 도착 목표 지점, a-b = 하루에 가는 거리

	if ((v - a) % (a - b)) // 달팽이가 도착점을 지나치는 경우는 날짜가 하루 더 소요됨
		cout << day + 1; //
	else
		cout << day;	// 달팽이가 도착점에 딱 맞게 도달하는 경우
}