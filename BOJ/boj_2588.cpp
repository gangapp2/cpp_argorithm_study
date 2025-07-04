#include <iostream>
using namespace std;
// 
int main()
{
    int a, b;

    cin >> a;
    cin >> b;

    int c = b % 10; // b의 일의 자릿수
    int d = (b / 10) % 10; // b의 십의 자릿수
    int e = b / 100; // b의 백의 자릿수

    cout << a * c << endl; // a * 일의 자릿수
    cout << a * d << endl; // b * 십의 자릿수
    cout << a * e << endl; // c * 백의 자릿수

    cout << (a * c) + (a * d)*10 + (a * e)*100 << endl; // d, e 는 각각 십,백의 자릿수이므로 10, 100을 더 곱해줘야함
}
