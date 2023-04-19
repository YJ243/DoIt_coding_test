#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Position{
    int x, y, distance;
};

static int N, M;

int BFS(int x, int y, vector<vector<int>> &a, vector<vector<int>> &visited);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<vector <int>> a(N+1, vector<int>(M+1,0));
    vector<vector <int>> visited(N+1, vector<int>(M+1, 0));
    for(int i=1; i<=N; i++){
        string r;
        cin >> r;
        for(int j=1; j<=M; j++){
            a[i][j] = r[j-1]-'0';
        }
    }
    int answer = BFS(1, 1, a, visited);
    cout << answer << '\n';
}

int BFS(int x, int y, vector<vector<int>> &a, vector<vector<int>> &visited){
    visited[x][y] = 1;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    int nx = 0;
    int ny = 0;
    queue<Position> myqueue;
    myqueue.push({x,y,1});
    cout << 'a' << '\n';
    while(!myqueue.empty()){
        cout << 'b' << '\n';
        struct Position cur = myqueue.front();
        myqueue.pop();
        if(cur.x == N && cur.y == M){
            cout << 'c' << '\n';
            return cur.distance;
        }
        cout << 'd' << '\n';
        for(int i=0; i<4; i++){
            nx = cur.x + dx[i];
            ny = cur.y + dy[i];
            cout << 'e' << '\n';
            if(nx < 1 || nx > N || ny < 1 || ny > M){
                cout << 'f' << '\n';
                break;
            }
            if(a[nx][ny] == 1 && visited[nx][ny] == 0){
                visited[nx][ny]= 1;
                myqueue.push({nx, ny, cur.distance+1});
            }
        }
    }
/*
    while(x != N || y != M ){
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > N || ny < 1 || ny > M){
                break;
            }
            if (a[nx][ny] == 1 && visited[nx][ny] == 0){
                // 길이 1이고, 아직 방문하지 않았다면
                answer++;
                x = nx;
                y = ny;
            }
        }
    }
    */
}