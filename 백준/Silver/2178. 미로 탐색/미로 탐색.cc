#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<string> vec;
vector<vector<bool>> discovered;
vector<vector<int>> dist;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m;


bool Cango(int y, int x)
{
	if (x < 0 || x >= m)
		return false;
	if (y < 0 || y >= n)
		return false;
	if (vec[y][x] != '1') // 0일때
		return false;
	if (discovered[y][x])
		return false;

	return true;
}

void Bfs(int y, int x)
{
	queue<pair<int,int>> q;
	q.push(make_pair(y,x));
	discovered[y][x] = true;
	dist[y][x] = 1;

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			if (Cango(p.first + dy[i], p.second + dx[i]))
			{
				q.push(make_pair(p.first + dy[i], p.second + dx[i]));
				discovered[p.first + dy[i]][p.second + dx[i]] = true;
				dist[p.first + dy[i]][p.second + dx[i]] = dist[p.first][p.second] + 1;
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	vec = vector<string>(n);
	discovered = vector<vector<bool>>(n, vector<bool>(m, false));
	dist = vector<vector<int>>(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	Bfs(0,0);

	cout << dist[n - 1][m - 1];
}