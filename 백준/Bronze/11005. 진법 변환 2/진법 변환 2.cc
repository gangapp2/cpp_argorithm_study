#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, b;
	cin >> n >> b;
	string res;

	while (n > 0)
	{
		int temp = n % b;

		if (temp >= 0 && temp <= 9)
			res += (temp + '0'); // 아스키코드 '0'~'9'로 변환해주어야 하므로 'a'만큼 더해준다
		else
			res += (temp - 10 + 'A'); // 10이 출발점이므로 temp-10 이후 + 'A'

		n /= b; // 나눠진 몫으로 n을 초기화
	}

	for(int i = res.length() - 1; i >= 0; i--) // 역순출력
		cout << res[i];
}
