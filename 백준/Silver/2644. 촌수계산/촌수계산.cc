#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, a, b;

vector<vector<int>> adjacent;
vector<bool> discovered;
vector<int> dist;

void Bfs(int here)
{
	queue<int> q;
	q.push(here);
	discovered[here] = true;
	dist[here] = 0;

	while (!q.empty())
	{
		here = q.front();
		q.pop();
		int size = adjacent[here].size();

		for (int i = 0; i < size; i++)
		{
			int there = adjacent[here][i];

			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;
			dist[there] = dist[here] + 1;
		}
	}
}

int main()
{
	cin >> n >> a >> b >> m;
	adjacent = vector<vector<int>>(n+1);
	discovered = vector<bool>(n + 1,false);
	dist = vector<int>(n + 1,-1);
	for (int i = 0; i < m; i++)
	{
		int p, c;
		cin >> p >> c;
        // 양방향 연결해주어야함
		adjacent[p].push_back(c);
		adjacent[c].push_back(p); 

	}

	Bfs(a);

	cout << dist[b];
}
