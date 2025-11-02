#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
using namespace std;


struct dataset
{
	int num;
	int size;
	int ans;
};

vector<dataset> dSet;
vector<vector<int>> arr;
vector<vector<int>> arr_tmp; // 오름차순으로 정렬된 배열 
vector<vector<int>> arr_rank; // 중복이 제거된 순위 배열

int FindLastIndex(int min,vector<int> arr) // min값의 마지막 index를 리턴
{
	int index = -1;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == min)
			index = i;
	}
	return index;
}

int CountMin(int min, int lastIndex, vector<int> arr) // 이전 최솟값의 마지막 인덱스 뒤에 나오는 현재 최솟값의 개수를 카운트
{
	int count = 0;
	for (int i = lastIndex + 1; i < arr.size(); i++)
	{
		if (min == arr[i])
			count++;
	}
	return count;
}
int main()
{
	int p; // 테스트 케이스의 수
	cin >> p;

	for (int i = 0; i < p; i++)
	{
		dataset d;
		cin >> d.num;
		cin >> d.size;
		dSet.push_back(d);
		arr.push_back({}); // 이중 벡터 초기화
		arr_tmp.push_back({});

		for (int j = 0; j < d.size; j++)
		{
			int n;
			cin >> n;
			arr[i].push_back(n);
			arr_tmp[i].push_back(n);
		}
	}
	// 중복제거한 순위배열 생성
	for (int i = 0; i < p; i++)
	{
		sort(arr_tmp[i].begin(), arr_tmp[i].end());
		arr_rank.push_back({}); // 이중 벡터 초기화

		int temp = arr_tmp[i][0];
		arr_rank[i].push_back(temp);

		for (int j = 0; j < arr_tmp[i].size(); j++)
		{
			if (arr_tmp[i][j] != temp)
			{
				temp = arr_tmp[i][j];
				arr_rank[i].push_back(temp);
			}
		}
	}

	// 
	for (int i = 0; i < p; i++)
	{
		int count = 0;
		int index = -1;
		int temp; 
		bool isFound = false;
		
		for (int j = 0; j < arr_rank[i].size(); j++)
		{
			if (isFound)
				break;
			temp = arr_rank[i][j]; // 각 테스트 케이스의 최솟값

			for (int k = 0; k < arr[i].size(); k++)
			{
				if (temp == arr[i][k]) // 최솟값 발견
				{

					if (index < k) // 순행
					{
						index = k;
						count++;
					}
					else // 역행
					{
						int preMin = arr_rank[i][j - 1]; // 현재 최솟값의 이전 최솟값
						int lastIndex = FindLastIndex(preMin, arr[i]);
						count += CountMin(temp, lastIndex, arr[i]);

						isFound = true;
						dSet[i].ans = arr[i].size() - count;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < p; i++)
	{
		cout << dSet[i].num << " " << dSet[i].ans << endl;
	}
}