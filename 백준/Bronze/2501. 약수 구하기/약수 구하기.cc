#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n, k;
	int q = 1;
	vector<int> yaksu;
	cin >> n >> k;

	while (true)
	{
		if (n % q == 0)
			yaksu.push_back(q);

		if (n == q)
			break;

		q++;
	}

	if (yaksu.size() >= k)
		cout << yaksu[k - 1] << endl;
	else
		cout << "0" << endl;
}