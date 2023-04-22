#include <iostream>
#include <vector>

using namespace std;

void DFS(int number, int jarisu);
bool isPrime(int num);
static int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    DFS(2,1);
    DFS(3,1);
    DFS(5,1);
    DFS(7,1);
}

bool isPrime(int num){
    for(int i=2; i<=num/2; i++){
        if(num%i==0){ // 2부터 증가시키는데, 나눠진다면 소수가 아니므로
            return false;
        }
    }
    return true; // 나눠지는 수가 없다면 참
}

void DFS(int number, int jarisu){
    if(jarisu==N){ // 마지막 자릿수까지 왔는데
        if(isPrime(number)){ // 그 수가 소수이면
            cout << number<<'\n';
        }
        return;
    }
    for(int i=1; i<=5; i++){
        int k = i * 2 -1;
        if(isPrime(number*10 + k)){ // 소수이면 탐색
            DFS(number*10+k, jarisu+1);
        }
    }
}