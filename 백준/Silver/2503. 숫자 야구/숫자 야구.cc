#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

struct Game
{
	int num;
	int s; //strike
	int b; // ball
};

bool Can_Num[1000]; // 111~999까지 숫자들을 담을 배열
vector<Game> Round;


int main()
{
	// 자릿수 중복, 0이 포함되는 수들은 사용 불가
	memset(Can_Num, true, sizeof(Can_Num));
	for (int i = 123; i < 1000; i++)
	{
		string tmp = to_string(i);
		// 각 자릿수가 중복되면 false
		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
			Can_Num[i] = false;
		// 0이 포함되면 flase
		if(tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
			Can_Num[i] = false;
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		Game g;
		cin >> g.num;
		cin >> g.s;
		cin >> g.b;
		Round.push_back(g);
	}

	for (int i = 0; i < n; i++)
	{
		string num = to_string(Round[i].num);
		int strike = Round[i].s;
		int ball = Round[i].b;

		for (int j = 123; j < 1000; j++) // 현재 라운드의 볼카운트가 일치하지 않는 수를 찾아낸다
		{
			int tmp_strike = 0;
			int tmp_ball = 0;
			if (Can_Num[j] == true)
			{
				string tmp = to_string(j); // 현재 라운드의 숫자와 비교할 숫자 = 인덱스값 j
				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						// strike인 경우
						if (a == b && num[a] == tmp[b])
							tmp_strike++;
						// ball인 경우
						if (a != b && num[a] == tmp[b])
							tmp_ball++;
					}
				}
			}
			if (strike != tmp_strike || ball != tmp_ball)
				Can_Num[j] = false;
		}
	}
	int ans = 0;
	for (int i = 123; i < 1000; i++)
	{
		if (Can_Num[i])
			ans++;
	}
	cout << ans;
}