#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> vec;
vector<vector<bool>> visited;
int cnt = 0;
int t, m, n, k;

bool CanGo(int y, int x)
{
	if (x < 0 || x >= m)
		return false;
	if (y < 0 || y >= n)
		return false;

	return true;
}
void Dfs(int y, int x)
{
	visited[y][x] = true;

	// x, y값이 +-1 인 곳의 배열 값이 1인지 검사
	if (CanGo(y, x + 1) && vec[y][x+1] == 1 && !visited[y][x + 1])
		Dfs(y, x + 1);

	if (CanGo(y, x - 1) && vec[y][x - 1] == 1 && !visited[y][x - 1])
		Dfs(y, x - 1);

	if (CanGo(y + 1, x) && vec[y + 1][x] == 1 && !visited[y + 1][x])
		Dfs(y + 1, x);

	if (CanGo(y - 1, x) && vec[y - 1][x] == 1 && !visited[y - 1][x])
		Dfs(y - 1, x);
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