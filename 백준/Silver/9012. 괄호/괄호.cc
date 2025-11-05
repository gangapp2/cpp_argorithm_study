#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;

	vector<string> vec(t);

	for (int i = 0; i < vec.size(); i++)
	{
		cin >> vec[i];
	}


	for (int i = 0; i < vec.size(); i++)
	{
		int balance = 0;
		bool isFound = false;

		for (int j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j] == '(')
				balance++;
			else
				balance--;

			if (balance < 0)
			{
				cout << "NO" << endl;
				isFound = true;
				break;
			}
		}
		if (balance == 0)
			cout << "YES" << endl;
		else
		{
			if(!isFound)
				cout << "NO" << endl;
		}
	}
	return 0;
}