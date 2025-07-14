#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adjacent;
vector<int> best(6, INT32_MAX);
vector<int> parent(6, -1);

struct VertexCost
{
    VertexCost(int cost, int vertex) :cost(cost),vertex(vertex){}
    bool operator<(const VertexCost& other) const { return cost < other.cost; }
    bool operator>(const VertexCost& other) const { return cost > other.cost; }
    int cost;
    int vertex;
};

void CreateGraph()
{
    adjacent = vector<vector<int>>(6, vector<int>(6, -1));
    adjacent[0][1] = adjacent[1][0] = 15;
    adjacent[0][3] = adjacent[3][0] = 35;
    adjacent[1][2] = adjacent[2][1] = 5;
    adjacent[1][3] = adjacent[3][1] = 10;
    adjacent[3][4] = adjacent[4][3] = 5;
    adjacent[5][4] = adjacent[4][5] = 5;
}

void Dijkstra(int here)
{
    // Pred_greater를 사용해 cost값이 작을 수록 우선정렬된다(기본값은 less)
    priority_queue<VertexCost,vector<VertexCost>, greater<VertexCost>> pq;
    pq.push(VertexCost(0, here));
    best[here] = 0;
    parent[here] = here;

    while (pq.empty() == false)
    {
        VertexCost v = pq.top();
        pq.pop();

        int cost = v.cost;
        here = v.vertex;

        // pop된 경로가 최단거리가 아닌 경우 스킵해준다(큐에 경로가 여러개 push될 경우 중복방문방지)
        if (best[here] < cost)
            continue;

        // 방문처리
        cout << "visited : " << here << endl;
        
        for (int there = 0; there < 6; there++)
        {
            // 갈 수 있는 길인지 탐색
            if (adjacent[here][there] == -1)
                continue;

            // 발견된 경로가 최단거리이냐?
            int nextCost = best[here] + adjacent[here][there]; // 다음 경로까지 소요 비용
            if (best[there] <= nextCost)
                continue;

            // 여기까지 왔다면 최단경로가 맞으므로 방문예정 목록에 추가
            pq.push(VertexCost(nextCost, there));
            best[there] = nextCost;
            parent[there] = here;
        }
    }
}
int main()
{
    CreateGraph();
    Dijkstra(0);
}

