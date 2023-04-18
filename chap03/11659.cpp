#include <iostream>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int array[100000];
    for(int i=0; i<N; i++){
        cin >> array[i];
    }
    int sum[100000]={0};
    sum[0] = array[0];
    for(int i=1; i<N; i++){
        sum[i] = sum[i-1]+array[i];
    }

    int num[100000][2];
    for(int i=0; i<M; i++){
        cin >> num[i][0] >> num[i][1];
    }
    for(int i=0; i<M; i++){
        if(num[i][0] == 1){
            cout << sum[num[i][1]-1];
        }
        else if(num[i][0] == num[i][1]){
            cout << array[num[i][0]-1];
        }
        else{

            cout << sum[num[i][1]-1] - sum[num[i][0]-2];
        }
        cout<<'\n';
    }

    
}