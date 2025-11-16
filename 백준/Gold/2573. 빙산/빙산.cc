#include<iostream>
#include<vector>
using namespace std;

int n, m;
int year = 0;

vector<vector<int>> bingsan;
vector<vector<bool>> visited;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool Cango(int y,int x)
{
	// 배열 범위 체크
	if (x < 0 || x >= m)
		return false;
	if (y < 0 || y >= n)
		return false;

	// 이미 방문한 곳인지 체크
	if (visited[y][x])
		return false;

	// 바닷가인지 체크
	if (bingsan[y][x] == 0)
		return false;

	return true;
}

int IsZero(int y, int x)
{
	if (x < 0 || x >= m)
		return 0;
	if (y < 0 || y >= n)
		return 0;

	if (bingsan[y][x] == 0)
		return 1;
	else
		return 0;
}

void Dfs(int y,int x)
{
	int cnt = 0;

	visited[y][x] = true;

	// 인접한 빙하 갯수에 따라 빙하를 녹임
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		cnt += IsZero(nextY, nextX);
	}

	// 다음 정점으로 이동
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (Cango(nextY, nextX))
		{
			Dfs(nextY, nextX);
		}
	}

	bingsan[y][x] -= cnt;

	if (bingsan[y][x] < 0)
		bingsan[y][x] = 0;

	cnt = 0;
}

void DfsAll()
{
	while (1)
	{
		bool isDivided = false;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (bingsan[i][j] != 0 && visited[i][j] == false)
				{
					if (isDivided)
					{
						cout << year;
						return;
					}
					Dfs(i, j);
					isDivided = true;
				}
			}
		}

		if (!isDivided) // 더이상 탐색할 빙산이 없고 그 전까지 분리가 한번도 안된 경우
		{
			cout << 0;
			return;
		}

		// visited 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if(bingsan[i][j] != 0)
					visited[i][j] = false;
			}
		}
		year++;
	}
}

int main()
{
	cin >> n >> m;
	bingsan = vector<vector<int>>(n, vector<int>(m));
	visited = vector<vector<bool>>(n, vector<bool>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> bingsan[i][j];
		}
	}


	DfsAll();
	
	return 0;
}