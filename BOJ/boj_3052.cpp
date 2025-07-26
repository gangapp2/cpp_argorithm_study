#include<iostream>
using namespace std;
int main()
{
    // bool arr[42] = {}; 기본값은 0 : false
    // n을 입력받고 arr[n % 42] = true로 설정한다
    // 나머지 연산의 결과로 나온 값의 인덱스를 true로 설정한다(체크박스에 체크표시를 해준다고 생각)
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