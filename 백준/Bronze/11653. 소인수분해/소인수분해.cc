#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	long long n;
	cin >> n;

	// 짝수 인수를 모두 제거
	while (n % 2 == 0)
	{
		cout << 2 << endl;
		n /= 2;
	}

	// 홀수만 검사 : i<= 루트n까지
	// n이 합성수일때 약수는 항상 쌍으로 나타남
	// 항상 약수쌍의 작은쪽은 루트n이하, 큰쪽은 루트n이상임 
	// i<=루트n 조건을 만족하는 약수가 더 이상 없는 경우 모든 약수를 검사했다는 뜻임
	// ex) i > 루트n일때 다른 쌍은 반드시 루트n보다 작아야 하는데,
	//  조건문을 벗어났다는 것은 이미 루트n보다 작은 수는 모두 검사가 끝났따는 뜻이므로 모순

	for (int i = 3; i * i <= n; i += 2)
	{
		while (n % i == 0)
		{
			cout << i << endl;
			n /= i;
		}
	}

	// 모든 약수가 걸러진 상태
	if (n > 1)
		cout << n << endl;
}