#include<iostream>
using namespace std;
int main()
{
    // bool arr[42] = {}; �⺻���� 0 : false
    // n�� �Է¹ް� arr[n % 42] = true�� �����Ѵ�
    // ������ ������ ����� ���� ���� �ε����� true�� �����Ѵ�(üũ�ڽ��� üũǥ�ø� ���شٰ� ����)
    bool arr[42] = {};
    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;
        arr[n % 42] = true;
    }

    for (int i = 0; i < 42; i++)
        if (arr[i])
            count++;

    cout << count << endl;
}