#include <iostream>
using namespace std;

#define MOD 1000000000;                                                                    
long long d[101][10];
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N;
    cin >> N;

    for(int i = 1; i<= 9; i++) d[1][i] = 1;
    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= 9; j++){
            switch(j){
                case(0):
                d[i][j] = d[i-1][1]% MOD;
                break;                      
                case(9):
                d[i][j] = d[i-1][8] % MOD;
                break;
                default:
                d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) %MOD;
                break;
            }
        }
    }
    long long answer = 0;
    for(int i = 0; i <= 9; i++) answer += d[N][i];

    cout << answer % MOD;
}