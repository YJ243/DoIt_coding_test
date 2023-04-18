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
            // ������ �ڸ����̰�, �Ҽ��̸� ���
            cout << num << '\n';
        return;
    }
    
    for(int i=1; i<=5; i++){
        int j = i * 2 -1; // ���ڸ��� 1,3,5,7,9 �� Ȯ��
        if( is_prime_number(num * 10 + j))// �ڿ� �ٴ� �� == Ȧ�� && �Ҽ�)
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