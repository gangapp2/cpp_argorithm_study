#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int a, b, v;
	int day = 1;
	cin >> a >> b >> v;

	// ��ǥ �Ÿ��� �Ϸ翡 ���� �Ÿ��� ������ �ҿ�Ǵ� �� �ϼ��� ���Ѵ�
	day += (v - a) / (a - b); // v-a = ���� ��ǥ ����, a-b = �Ϸ翡 ���� �Ÿ�

	if ((v - a) % (a - b)) // �����̰� �������� ����ġ�� ���� ��¥�� �Ϸ� �� �ҿ��
		cout << day + 1; //
	else
		cout << day;	// �����̰� �������� �� �°� �����ϴ� ���
}