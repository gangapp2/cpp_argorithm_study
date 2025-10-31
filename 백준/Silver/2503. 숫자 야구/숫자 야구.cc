#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

bool Card_Num[1000];

struct Game
{
	int num;
	int s;
	int b;
};
vector<Game> Round;
int main()
{
	memset(Card_Num, true, sizeof(Card_Num));
	for (int i = 123; i < 1000; i++)
	{
		string tmp = to_string(i); // 배열의 인덱스 값을 세자리 수로 사용중, 자릿수 비교에 용이하게 string으로 변경

		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2]) // 자릿수가 중복되면 안됨
			Card_Num[i] = false;
		if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0') // 자릿수가 0이 될수 없음
			Card_Num[i] = false;
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
	// 민혁이가 질문한 수의 볼카운트와  각 숫자들의 볼카운트가 일치하는지 비교
	for (int i = 0; i < n; i++)
	{
		string num = to_string(Round[i].num);
		int strike = Round[i].s;
		int ball = Round[i].b;

		for (int j = 123; j < 1000; j++)
		{
			if (Card_Num[j]) // card_num == true
			{
				string tmp_num = to_string(j);
				int tmp_strike = 0;
				int tmp_ball = 0;
				// 볼카운트 비교
				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						// strike
						if (a == b && tmp_num[a] == num[b])
							tmp_strike++;
						// ball
						if (a != b && tmp_num[a] == num[b])
							tmp_ball++;
					}
				}
				if (strike != tmp_strike || ball != tmp_ball)
					Card_Num[j] = false;
			}
		}
	
	}

	int ans=0;
	for (int i = 123; i < 1000; i++)
	{
		if (Card_Num[i])
			ans++;
	}
	cout << ans;
}