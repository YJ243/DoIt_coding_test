#include <iostream>
#include <queue>
using namespace std;
// 우, 하, 좌, 상 (우/하 먼저, 그 이후 좌/상을 넣어야 최소)
static int dx[] = {0,1,0,-1};
static int dy[] = {1, 0, -1, 0};

static int A[101][101]; // N,M <= 100
static bool visited[101][101] = {false}; // 방문 확인 배열
static int N, M;
void BFS(int i, int j);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j =0; j<M; j++){
            A[i][j] = s[j] - '0';
        }
    }
    BFS(0,0); // 시작점으로 완전탐색 시작
    cout << A[N-1][M-1] << '\n';
}

// BFS 구현
void BFS(int i, int j){
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(i,j));

    while(!myqueue.empty()){
        int now[2];
        now[0] = myqueue.front().first;
        now[1] = myqueue.front().second;
        myqueue.pop();
        visited[i][j] = true;

        for(int k=0; k<4; k++){
            int nx = now[0] + dx[k];
            int ny = now[1] + dy[k];

            // 좌표가 유효한 경우에만
            if(nx >= 0 && ny >= 0 && nx <= N-1 && ny <= M-1){
                // 길이 있고, 좌표를 방문하지 않은 경우에 진행
                if(A[nx][ny] == 1 && visited[nx][ny] == false){
                    visited[nx][ny] = true;
                    // 길 담은 배열에 거리를 담기
                    A[nx][ny] = A[now[0]][now[1]] + 1;
                    myqueue.push(make_pair(nx,ny));
                }
            }
        }
    }
}