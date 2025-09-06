#include <iostream>
using namespace std;

int main()
{
	int x; // 해당 라인의 몇번째 분수인가
	int line = 1; // 현재 라인
	cin >> x;

	// line의 값과 해당 line에 속하는 요소의 갯수가 일치함
	// x값은 몇번째 순서의 분모인지를 나타냄
	// 고로 x - line <= 0 이 되면 해당 line에 x값이 속한다는 의미가 됨
	while (x-line > 0)
	{
		x -= line; // 지나친 순서 만큼 빼줌으로서 남은 순서가 얼마나 되는지 x를 갱신
		line++; // line 갱신
	}

	if (line % 2 == 0) // 짝수 대각선인 경우
		// 분자 : x         분모 : line+1 -x 
		cout << x << "/" << line + 1 - x << endl;
	else
		// 진행방향이 반대이므로 분자와 분모값을 역으로 취함
		cout << line + 1 - x << "/" << x << endl;
}
