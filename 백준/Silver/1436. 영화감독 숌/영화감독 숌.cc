#include<iostream>
int main() 
{
    int n, cnt = 0;
    std::cin >> n;
    for (int i = 666;; i++) 
    {
        int tmp = i;
        while (tmp >= 666) 
        {
            if (tmp % 1000 == 666) 
            {
                cnt++;
                break;
            }
            tmp /= 10;
        }
        if (n == cnt) 
        {
            std::cout << i;
            break;
        }
    }
}