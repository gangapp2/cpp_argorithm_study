#include <iostream>
#include <string>
using namespace std;
int main()
{
	char arr[5][15] = { '\0' };

	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	for (int i = 0; i < 15; i++) {
		for (int k = 0; k < 5; k++) {
			if (arr[k][i] != NULL)
				cout << arr[k][i];
		}
	}
}
