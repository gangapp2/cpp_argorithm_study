#include <iostream>
using namespace std;

void Boj_10811()
{
	int n, m;
	cin >> n >> m;

	int* arr = new int[n + 1]; // 배열 크기를 1 늘려주고 인덱스를 1부터 시작(arr[0]은 비워둠)

	for (int i = 1; i < n + 1; i++)
		arr[i] = i;

	while (m--) // 0이 되면 false
	{
		int x, y;
		cin >> x >> y;
		if (x != y)
			for (int i = 0; i <= (y - x) / 2; i++)
			{
				if (x + i != y + i)
					swap(arr[x + i], arr[y - i]);

			}
	}
	for (int i = 1; i < n + 1; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void Boj_1546()
{
	int n;
	int m = INT32_MIN;
	double totalScore = 0;
	cin >> n;
	double* arr = new double[n];

	for (int i = 0; i < n; i++)
	{
		double score;
		cin >> score;
		arr[i] = score;
		if (score > m)
			m = score;
	}
	for (int i = 0; i < n; i++)
	{
		double score = arr[i];
		score = score / m * 100;
		totalScore += score;
	}

	cout << totalScore / n << endl;
}
int main()
{
	Boj_10811();
}
