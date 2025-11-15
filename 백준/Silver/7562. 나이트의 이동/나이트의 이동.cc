#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int l, destX, destY; // 배열 l*l
// vector<vector<int>> adjacent;
vector<vector<bool>> discovered;
vector<vector<int>> dist;

int dX[8] = {2,2,-2,-2,1,-1,1,-1};
int dY[8] = {1,-1,1,-1,2,2,-2,-2};
bool Cango(int x, int y)
{
	// 상하좌우 + 2 >> (상 하) x+-1 , (좌 우) y+-1
	if (x < 0 || x >= l)
		return false;
	if (y < 0 || y >= l)
		return false;
	// 이미 가기로 예정된 길인 경우 큐에 넣지 않음
	if (discovered[y][x])
		return false;

	return true;
}
void Bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	discovered[y][x] = true;
	dist[y][x] = 0;

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		if (p.first == destX && p.second == destY)
			break;
		for (int i = 0; i < 8; i++)
		{
			int nextX = p.first + dX[i];
			int nextY = p.second + dY[i];

			if (Cango(nextX, nextY))
			{
				discovered[nextY][nextX] = true;
				dist[nextY][nextX] = dist[p.second][p.first] + 1;
				q.push(make_pair(nextX, nextY));
			}

		}
	}
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int startX, startY;
		cin >> l >> startX >> startY >> destX >> destY;
		discovered = vector<vector<bool>>(l, vector<bool>(l, false));
		dist = vector<vector<int>>(l, vector<int>(l,-1));
		Bfs(startX, startY);

		cout << dist[destY][destX] << endl;
	}
	return 0;
}