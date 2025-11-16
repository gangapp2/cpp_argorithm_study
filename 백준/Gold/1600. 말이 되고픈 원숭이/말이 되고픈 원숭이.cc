#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int k, w, h;

vector<vector<int>> board;
int dist[201][201];
bool discovered[201][201][31] = { false, };

int dx_monkey[4] = {1,-1,0,0};
int dy_monkey[4] = {0,0,1,-1};

int dx_horse[8] = { 2,2,-2,-2,1,-1,1,-1 };
int dy_horse[8] = { 1,-1,1,-1,2,2,-2,-2 };

bool Cango_M(int x, int y, int usedK) // 원숭이
{
	// 범위 초과하는가
	if (x < 0 || x >= w)
		return false;
	if (y < 0 || y >= h)
		return false;
	// 장애물이 없는가
	if (board[y][x] == 1)
		return false;
	// 이미 발견된 길인가
	if (discovered[y][x][usedK])
		return false;

	return true;
}

bool Cango_H(int x, int y, int usedK) // 말
{
	// 범위 초과하는가
	if (x < 0 || x >= w)
		return false;
	if (y < 0 || y >= h)
		return false;
	// 장애물이 없는가
	if (board[y][x] == 1)
		return false;

	// 이미 발견된 길인가
	if (discovered[y][x][usedK])
		return false;		

	return true;
}

void Bfs(int x, int y)
{
	queue<pair<pair<int, int>, int>> q;

	q.push(make_pair(make_pair(x,y),0));

	dist[y][x] = 0;
	discovered[y][x][0] = true;

	while (!q.empty())
	{
		pair<pair<int, int>, int> p = q.front();
		q.pop();

		int cx = p.first.first;
		int cy = p.first.second;
		int ck = p.second;

		if (cx == w - 1 && cy == h - 1) // 시작 시점에 비교하여 (1,1)인 경우도 바로 체크
		{
			cout << dist[cy][cx];
			return;
		}

		// 원숭이 움직임
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx_monkey[i];
			int ny = cy + dy_monkey[i];

			if (Cango_M(nx, ny, ck))
			{
				discovered[ny][nx][ck] = true;
				dist[ny][nx] = dist[cy][cx] + 1;
				q.push(make_pair(make_pair(nx, ny), ck));
			}
		}

		if (ck < k)
		{
			// 말 움직임 (k가 남아있는 경우에 가능
			for (int i = 0; i < 8; i++)
			{
				int nx = cx + dx_horse[i];
				int ny = cy + dy_horse[i];

				if (Cango_H(nx, ny, ck + 1))
				{
					discovered[ny][nx][ck + 1] = true;
					dist[ny][nx] = dist[cy][cx] + 1;
					q.push(make_pair(make_pair(nx, ny), ck + 1));
				}
			}
		}
	}
	cout << -1;
}

int main()
{
	cin >> k >> w >> h;
	board = vector<vector<int>>(h, vector<int>(w));
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> board[i][j];
		}
	}

	Bfs(0, 0);

	return 0;
}