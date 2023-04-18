#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static int n;
bool is_prime_number(int check){
    
    for(int i=2; i<=check/2; i++){
        if(check % i == 0){
            return false;
        }
    }
    return true;
}


void DFS(int num, int cur){
    if( cur == n){
        if(is_prime_number(num))
            // 마지막 자리수이고, 소수이면 출력
            cout << num << '\n';
        return;
    }
    
    for(int i=1; i<=5; i++){
        int j = i * 2 -1; // 뒷자리는 1,3,5,7,9 만 확인
        if( is_prime_number(num * 10 + j))// 뒤에 붙는 수 == 홀수 && 소수)
        {
            DFS(num * 10 + j, cur+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int first[4] = {2,3,5,7};

    for(int i: first){
        DFS(i, 1);
    }
}