#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m,v;
vector<vector<int>> vec;
vector<bool> visited;
vector<bool> discovered;

void Dfs(int here)
{
	visited[here] = true;
	cout << here << " ";

	for (int i = 0; i < vec[here].size(); i++)
	{
		int there = vec[here][i];
		if (visited[there])
			continue;
		visited[there] = true;
		Dfs(there);
	}
}
void Bfs(int here)
{
	queue<int> q;
	q.push(here);
	discovered[here] = true;

	while (!q.empty())
	{
		here = q.front();
		cout << here << " ";
		q.pop();

		for (int i = 0; i < vec[here].size(); i++)
		{
			int there = vec[here][i];
			if (discovered[there])
				continue;
			discovered[there] = true;
			q.push(there);
		}
	}
}

int main()
{
	cin >> n >> m >> v;
	vec = vector<vector<int>>(n+1);
	visited = vector<bool>(n+1, false);
	discovered = vector<bool>(n+1, false);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	// 인접 리스트 정렬(값이 작은 순으로 방문)
	for (int i = 0; i < vec.size(); i++)
	{
		sort(vec[i].begin(), vec[i].end());
	}

	Dfs(v);
	cout << '\n';
	Bfs(v);
	cout << '\n';

	return 0;
}