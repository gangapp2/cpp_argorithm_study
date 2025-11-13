#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> vec;
vector<vector<bool>> visited;
int cnt = 0;
int t, m, n, k;
int dx[4] = { 0, 0, 1, -1 }; // 상하좌우를 배열의 인덱스 값으로 표현
int dy[4] = { 1, -1, 0, 0 };

bool CanGo(int y, int x)
{
	if (x < 0 || x >= m)
		return false;
	if (y < 0 || y >= n)
		return false;
	if (vec[y][x] != 1)
		return false;
	if (visited[y][x])
		return false;

	return true;
}
void Dfs(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		if (CanGo(y + dy[i], x + dx[i]))
			Dfs(y + dy[i], x + dx[i]);
	}
}
int main()
{
	cin >> t;

	while (t--)
	{
		cin >> m >> n >> k;
		vec = vector<vector<int>>(n, vector<int>(m, 0));
		visited = vector<vector<bool>>(n, vector<bool>(m, false));

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			vec[y][x] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (vec[i][j] == 1 && visited[i][j] == false)
				{
					Dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
		cnt = 0;
	}
	return 0;
}