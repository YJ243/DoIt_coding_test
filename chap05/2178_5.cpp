#include <iostream>
#include <queue>

using namespace std;

static int n, m;
static bool visited[101][101] = {false};
static int a[101][101];

// ��, ��, ��,��
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};


void bfs(int x, int y);
int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            a[i][j] = s[j]-'0';
        }
    }

/*
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
*/
    bfs(0,0);
    cout<<a[n-1][m-1];
}

void bfs(int x, int y){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(x,y));

    while(!myqueue.empty()){
        int cur[2]={0};
        cur[0] = myqueue.front().first;
        cur[1] = myqueue.front().second;

        myqueue.pop();
        //visited[i][j] = true;
        for(int i=0; i<4; i++){
            int nx = cur[0] + dx[i];
            int ny = cur[1] + dy[i];
            // 미로를 벗어나지 않았고
            if(nx >= 0 && ny >= 0 && nx <= n-1 && ny <= m-1){
                if(a[nx][ny] == 1){//이동할 수 있으면
                    // if((a[nx][ny] != 0 && !visited[x][y]))
                    //visited[nx][ny]=true;
                    a[nx][ny] = a[cur[0]][cur[1]]+1;
                    myqueue.push(make_pair(nx,ny));
                }
            }
        }
    }
}