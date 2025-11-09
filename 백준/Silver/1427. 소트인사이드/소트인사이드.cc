#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>v;
int main(void)
{
	int n;
	cin >> n;
	while (1)
	{
		v.push_back(n % 10);
		n /= 10;
		if (n < 1)
			break;
	}
	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	return 0;
}