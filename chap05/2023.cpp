#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime_number(int x){
    
    if (x == 1)
        return false;

    if (x == 2)
        return true;
    for(int i=2; i<=sqrt(x)+1; i++){
        // x가 해당 수로 나누어 떨어진다면
        if (x % i == 0){
            return false; // 소수가 아님
        }
    }
    return true; // 소수임
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int answer = 0;
    // 신기한 소수 찾기
    for(int i=pow(10,n-1); i<=pow(10,n)-1; i++){
        // 모든 n자리 수에 대해 체크
        bool check = true;
        for(int j=1; j<=n; j++){
            int num = i / pow(10, n-j);
            if( is_prime_number(num) == true){
                check *= true;
            }
            else
            {
                check *= false;
            }
        }
        if(check){
            cout << i << '\n';
        }   
    }

}