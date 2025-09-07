#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	while (1)
	{
		vector<int> factor;
		int n;
		int sum = 0;
		cin >> n;
		if (n == -1)
			break;
		for (int i = 1; i < n; i++)
		{
			if (n % i == 0)
			{
				factor.push_back(i);
				sum += i;
			}
		}


		if (n == sum)
		{
			cout << n << " = ";
			for (int i = 0; i < factor.size(); i++)
			{
				if (i == factor.size() - 1)
					cout << factor[i] << endl;
				else
					cout << factor[i] << " + ";
			}
		}

		else
			cout << n << " is NOT perfect." << endl;
	}
	
}