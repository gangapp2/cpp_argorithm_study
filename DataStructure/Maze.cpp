#include "pch.h"
#include "Player.h"
#include "Board.h"
void Player::Init(Board* board)
{
	_pos = board->GetEnterPos(); // ���� ��ġ
	_board = board;
	CalculatePath_AStar();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;

	// 0.1�ʴ����� ����ǵ�����
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
	_path.push_back(_pos); // ���� ��ġ ����

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
		int32 newDir = (_dir + 1) % DIR_COUNT; // ���� �������� ���������� ȸ���� ��Ȳ
		// 1.�ٶ󺸴� ���� �������� ���������� ���� �ִ°��
		if (Cango(pos + front[newDir]))
		{
			// ������ ���� �ٲ���
			_dir = newDir;
			// ������ 1�� ����
			pos += front[newDir];
			// Vector�� ��� ����
			_path.push_back(pos);
		}
		// 2.�ٶ󺸴� ���� �������� ������ ���� �ִ°��
		else if (Cango(pos + front[_dir]))
		{
			// ������ 1�� ����
			pos += front[_dir];
			// Vector�� ��� ����
			_path.push_back(pos);
		}
		// 3. ������ �������� 90�� ȸ��
		else
		{
			// ������ ���� �ٲ���
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
	// ��� ������ ����, ��� ������ Ž���ϱ���
	// ���� �������� parent�� �������Ͽ� ��θ� �˾Ƴ��� �� ��δ� �ִܰ�ΰ� ��
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		if (pos == dest) // ������ ������
			break;

		for (int i = 0; i < DIR_COUNT; i++)
		{
			Pos nextPos = pos + front[i];

			// ���� �����ִ� ��� ��ŵ
			if (Cango(nextPos) == false)
				continue;

			// �̹� �߰ߵ� ������ skip
			if (discovered[nextPos.y][nextPos.x])
				continue;

			// �߰�����!! �湮 ���� ��Ͽ� �߰�
			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos.y][nextPos.x] = pos;
		}

	}

	_path.clear();
	
	while (true) // ������ ������ ��θ� �������Ͽ� _path�� ����
	{
		_path.push_back(pos);

		if (pos == parent[pos.y][pos.x]) // �������� ����
			break;

		pos = parent[pos.y][pos.x]; // ������ ã�� ������ ������
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

	// OpenList : �湮 ���� ���
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;
	// �����α��� �ִܰŸ�
	vector<vector<int>> best(size, vector<int>(size, INT32_MAX));
	// Closed List : ���� �湮 ����
	vector<vector<bool>> closed(size, vector<bool>(size, false));
	// ������ �θ�����
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1,-1)));

	// ��� ���� �ʱ�ȭ, push
	{
		int32 g = 0;
		// ���������� ��� ������ (�޸���ƽ)
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.x - start.x));

		pq.push(PQNode(g + h, g, start));
		best[start.y][start.x] = g+h;
		parent[start.y][start.x] = start;
	}

	while (pq.empty() == false)
	{
		PQNode node = pq.top();
		pq.pop();

		// pop�� ��ΰ� ������� �߰ߵ� ������ ��ΰ� �´°�?
		if (best[node.pos.y][node.pos.x] < node.f)
			continue;
		if (closed[node.pos.y][node.pos.x])
			continue;

		// ������ �湮ó��
		closed[node.pos.y][node.pos.x] = true;

		if (node.pos == dest)
			break;

		// �湮 ���� ���� ��θ� Ž��
		for (int dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = node.pos + front[dir];

			// ���� ��η� �� �� �ִ°�?
			if (Cango(nextPos) == false)
				continue;
			if (closed[nextPos.y][nextPos.x])
				continue;

			// nextPos�� ������ ��ΰ� �´°�?
			int32 g = best[node.pos.y][node.pos.x] + cost[dir];
			int32 h = 10 * (abs(dest.x - nextPos.x) + abs(dest.y - nextPos.y));

			if (best[nextPos.y][nextPos.x] <= g + h)
				continue;

			// �´ٸ� pq�� push
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
