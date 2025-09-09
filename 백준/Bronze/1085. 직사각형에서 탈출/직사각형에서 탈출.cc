#include<iostream>
using namespace std;

int main()
{
	int x, y, w, h;
	int minX;
	int minY;
	int min;
	cin >> x >> y >> w >> h;

	minX = w - x > x ? x : w - x;
	minY = h - y > y ? y : h - y;

	min = minX > minY ? minY : minX;

	cout << min << endl;
}