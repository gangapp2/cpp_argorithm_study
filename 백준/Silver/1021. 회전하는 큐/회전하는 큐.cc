#include<iostream>
#include<vector>
using namespace std;

vector<int> vec;

int PopFirst();
void PushLeft();
void PushRight();

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		vec.push_back(i + 1);

	int count = 0;
	while (m--)
	{
		int num;
		cin >> num;

		int index;

		for (int i = 0; i < vec.size(); i++)
		{
			if (num == vec[i])
				index = i;
		}

		if (index == 0)
			PopFirst();

		else
		{
			int left = index;
			int right = vec.size() - 1 - index;

			if (left <= right)
			{
				for(int i=0;i<left;i++)
				{
					PushLeft();
					count++;
				}
			}
			else
			{
				for (int i = 0; i < right + 1; i++)
				{
					PushRight();
					count++;
				}
			}

			PopFirst();
		}
	}

	
	

	cout << count;
}

int PopFirst()
{
	int ret = vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		vec[i - 1] = vec[i];
	}
	vec.pop_back();

	return ret;
}
void PushLeft()
{
	int temp = vec[0]; // 젤 첫번째 값

	for (int i = 1; i < vec.size(); i++) // 두번째 값부터 전부 왼쪽으로 한칸씩 밀어줌
	{
		vec[i - 1] = vec[i];
	}

	vec[vec.size()-1] = temp; // 젤 끝값으로 temp를 밀어줌
}

void PushRight()
{
	int temp = vec[vec.size()-1];

	for (int i = vec.size()-2; i >= 0 ; i--)
		vec[i + 1] = vec[i];

	vec[0] = temp;
}