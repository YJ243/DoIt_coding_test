#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    int numbers[100001]={0};

    for(int i=1; i<=N; i++){
        int tmp;
        cin >> tmp; 
        numbers[i] = tmp + numbers[i-1];
    }
    for(int i=0; i<M; i++){
        int front, end;
        cin >>front >> end;
        cout<< numbers[end]-numbers[front-1] << '\n';
        
    }
}