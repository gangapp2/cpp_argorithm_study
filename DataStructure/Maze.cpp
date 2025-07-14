#include "pch.h"
#include "Player.h"
#include "Board.h"
void Player::Init(Board* board)
{
	_pos = board->GetEnterPos(); // 시작 위치
	_board = board;
	CalculatePath_AStar();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;

	// 0.1초단위로 실행되도록함
	if (_sumTick >= MOVE_TICK) 
	{
		SetPos(_path[_pathIndex]);
		_pathIndex++;		
		_sumTick = 0;
	}
	
}

bool Player::Cango(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

void Player::CalculatePath()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(_pos); // 시작 위치 설정

	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos(0,-1),
		Pos(1,0),
		Pos(0,1),
		Pos(-1,0),
	};

	while (pos != dest)
	{
		int32 newDir = (_dir + 1) % DIR_COUNT; // 현재 기준으로 오른쪽으로 회전한 상황
		// 1.바라보는 방향 기준으로 오른쪽으로 갈수 있는경우
		if (Cango(pos + front[newDir]))
		{
			// 방향을 새로 바꿔줌
			_dir = newDir;
			// 앞으로 1보 전진
			pos += front[newDir];
			// Vector에 경로 저장
			_path.push_back(pos);
		}
		// 2.바라보는 방향 기준으로 앞으로 갈수 있는경우
		else if (Cango(pos + front[_dir]))
		{
			// 앞으로 1보 전진
			pos += front[_dir];
			// Vector에 경로 저장
			_path.push_back(pos);
		}
		// 3. 방향을 왼쪽으로 90도 회전
		else
		{
			// 방향을 새로 바꿔줌
			_dir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;

		}

	}
}

void Player::CalculatePath_BFS()
{
	Pos pos = _pos;

	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos(0,-1),
		Pos(1,0),
		Pos(0,1),
		Pos(-1,0),
	};

	int size = _board->GetSize();

	queue<Pos> q;
	vector<vector<bool>> discovered(size, vector<bool>(size, false));
	// 경로 추적용 벡터, 모든 정점을 탐색하긴함
	// 도착 정점에서 parent를 역추적하여 경로를 알아내면 그 경로는 최단경로가 됨
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		if (pos == dest) // 목적지 도착함
			break;

		for (int i = 0; i < DIR_COUNT; i++)
		{
			Pos nextPos = pos + front[i];

			// 길이 막혀있는 경우 스킵
			if (Cango(nextPos) == false)
				continue;

			// 이미 발견된 정점도 skip
			if (discovered[nextPos.y][nextPos.x])
				continue;

			// 발견했음!! 방문 예정 목록에 추가
			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos.y][nextPos.x] = pos;
		}

	}

	_path.clear();
	
	while (true) // 도착지 까지의 경로를 역추적하여 _path에 저장
	{
		_path.push_back(pos);

		if (pos == parent[pos.y][pos.x]) // 시작점에 도달
			break;

		pos = parent[pos.y][pos.x]; // 본인을 찾은 정점을 역추적
	}

	std::reverse(_path.begin(), _path.end());
}

struct PQNode
{
	PQNode(int32 f, int32 g, Pos pos) :f(f), g(g), pos(pos) {}
	bool operator>(const PQNode& other) const { return f > other.f; }
	bool operator<(const PQNode& other) const { return f < other.f; }
	int32 f;
	int32 g;
	Pos pos;
};


void Player::CalculatePath_AStar()
{
	Pos start = _pos;

	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos(0,-1),
		Pos(1,0),
		Pos(0,1),
		Pos(-1,0),
	};

	int cost[4] =
	{
		10,
		10,
		10,
		10,
	};

	int size = _board->GetSize();

	// OpenList : 방문 예정 목록
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;
	// 현재경로까지 최단거리
	vector<vector<int>> best(size, vector<int>(size, INT32_MAX));
	// Closed List : 실제 방문 여부
	vector<vector<bool>> closed(size, vector<bool>(size, false));
	// 추적용 부모정점
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1,-1)));

	// 출발 정점 초기화, push
	{
		int32 g = 0;
		// 목적지까지 드는 예상비용 (휴리스틱)
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.x - start.x));

		pq.push(PQNode(g + h, g, start));
		best[start.y][start.x] = g+h;
		parent[start.y][start.x] = start;
	}

	while (pq.empty() == false)
	{
		PQNode node = pq.top();
		pq.pop();

		// pop된 경로가 현재까지 발견된 최적의 경로가 맞는가?
		if (best[node.pos.y][node.pos.x] < node.f)
			continue;
		if (closed[node.pos.y][node.pos.x])
			continue;

		// 맞으면 방문처리
		closed[node.pos.y][node.pos.x] = true;

		if (node.pos == dest)
			break;

		// 방문 이후 다음 경로를 탐색
		for (int dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = node.pos + front[dir];

			// 다음 경로로 갈 수 있는가?
			if (Cango(nextPos) == false)
				continue;
			if (closed[nextPos.y][nextPos.x])
				continue;

			// nextPos이 최적의 경로가 맞는가?
			int32 g = best[node.pos.y][node.pos.x] + cost[dir];
			int32 h = 10 * (abs(dest.x - nextPos.x) + abs(dest.y - nextPos.y));

			if (best[nextPos.y][nextPos.x] <= g + h)
				continue;

			// 맞다면 pq에 push
			pq.push(PQNode(g + h, g, nextPos));
			best[nextPos.y][nextPos.x] = g + h;
			parent[nextPos.y][nextPos.x] = node.pos;
		}
	}

	Pos pos = dest;
	_path.clear();

	while (true)
	{
		_path.push_back(pos);

		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x];
	}

	std::reverse(_path.begin(),_path.end());
}
