#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adjacent;
vector<bool> discovered(6, false);
vector<int> parent(6, -1);

void CreateGraph()
{
    adjacent.resize(6);
    adjacent[0] = { 1,3 };
    adjacent[1] = { 0,2,3 };
    adjacent[3] = { 4 };
    adjacent[5] = { 4 };
}

void Bfs(int here)
{
    queue<int> q; // 방문 예정 목록
    q.push(here);
    
    discovered[here] = true;
    parent[here] = here;

    while (q.empty() == false)
    {
        here = q.front();
        q.pop();

        // 방문함
        cout << "visited : " << here << endl;
        // 갈 수 잇는 경로 탐색
        for (int i = 0; i < adjacent[here].size(); i++)
        {
            int there = adjacent[here][i];
            // 이미 발견된 곳이면 방문예정목록에 넣지 않음(중복방지)
            if (discovered[there])
                continue;
            
            q.push(there);
            discovered[there] = true;
            parent[there] = here;
        }
    }
}

int main()
{
    CreateGraph();
    Bfs(0);
}

