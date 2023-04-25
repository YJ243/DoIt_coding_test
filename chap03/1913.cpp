#include <iostream>

using namespace std;

int x, y,direction;
int pivot=1;
int cnt = 1;
int a[1000][1000];
int main(){
    int N, target;
    cin >> N >> target;

    x = N/2;
    y = N/2;

    a[x][y]=cnt;
    while(cnt < N*N){
        if(direction == 0){
            for(int k =0; k<pivot; k++){
                a[--x][y] = ++cnt;
                if(cnt == N*N) break;
            }
        }
        else if(direction == 1){
            for(int k=0; k<pivot; k++){
                a[x][++y] = ++cnt;
                
            }
            pivot++;
        }
        else if(direction == 2){
            for(int k=0; k<pivot; k++){
                a[++x][y] = ++cnt;
                
            }
        }
        else{
            for(int k=0; k<pivot; k++){
                a[x][--y] = ++cnt;

            }
            pivot++;
        }
        direction = (direction+1)%4;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << a[i][j] << ' ';
            if(a[i][j] == target){
                x = i;
                y = j;
            }
        }
        cout<<'\n';
    }
    cout << x+1 << ' ' << y+1 << '\n';
}