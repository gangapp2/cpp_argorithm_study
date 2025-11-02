#include<iostream>
#include<list>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	
	list<int> l;

	for (int i = 1; i <= n; i++)
		l.push_back(i);

	auto it = l.begin();

	cout << "<";

	while (true)
	{
		for (int i = 0; i < k-1; i++)
		{
			++it;
			if (it == l.end()) // 범위를 벗어나면 처음으로 돌아감
				it = l.begin();
		}
		cout << *it;
		it = l.erase(it); // 다음 원소의 iterator 반환
		if (it == l.end())
		{
			if (l.size() == 0)
				break;
			it = l.begin();
		}
		cout << ", ";
	}
	cout << ">";

}