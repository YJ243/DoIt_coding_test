#include <iostream>
#include <queue>

using namespace std;

static int n, m;
static bool visited[100][100];
static int a[100][100];

// 동, 남, 서,북
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void bfs(int x, int y){
    queue<pair<int,int>> myqueue;
    visited[x][y] = true;
    myqueue.push(make_pair(x,y));

    while(!myqueue.empty()){
        int cur_x = myqueue.front().first;
        int cur_y = myqueue.front().second;
        myqueue.pop();

        for(int i=0; i<4;i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(nx >=0 && ny>=0 && nx<=n-1 && ny <=m-1){
                if(visited[nx][ny] == false && a[nx][ny]==1){
                    a[nx][ny] = a[cur_x][cur_y]+1;
                    myqueue.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }    
}


int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            a[i][j] = s[j]-'0';
        }
    }

    bfs(0,0);
    cout << a[n-1][m-1]<< '\n';
}