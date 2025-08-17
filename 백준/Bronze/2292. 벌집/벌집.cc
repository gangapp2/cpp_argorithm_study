#include <iostream>
using namespace std;

int main()
{
	int distance = 1;
	int gap = 6;
	int min = 1;
	int max = 1;
	int n;
	cin >> n;

	while (true)
	{
		if (n >= min && n <= max)
			break;
		distance++;
		min = max + 1;
		max = min + gap - 1;
		gap += 6;
	}

	cout << distance << endl;
	
}
