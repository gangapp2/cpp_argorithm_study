#include<iostream>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;

#define MAX 236196

int p;
vector<bool> visited;
vector<int> dist;

int nextValue(int a)
{
	stack<int> s;
	int ret = 0;
	while (a > 0)
	{
		s.push(a % 10);
		a /= 10;
	}

	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		ret += pow(s.top(), p);
		s.pop();
	}

	return ret;
}

void Dfs(int a)
{
	visited[a] = true;

	int nextV = nextValue(a);

	if (visited[nextV])
	{
		cout << dist[nextV];
		return;
	}

	dist[nextV] = dist[a] + 1;

	Dfs(nextV);
}

int main()
{
	int a;
	cin >> a >> p;

	visited.resize(MAX + 1, false);
	dist.resize(MAX + 1);
	dist[a] = 0;

	Dfs(a);
}