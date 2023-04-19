#include <iostream>
#include <queue>

using namespace std;

static int N, M;
static int a[101][101]={0};
static bool visited[101][101]={false};
void BFS(int x, int y);
// 이동 좌표
// 오른쪽, 아래/ 왼쪽, 위
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    // 미로 채우기
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            a[i][j] = s[j] - '0';
        }
    }

    // 처음 위치를 시작점으로 하여 완전탐색
    BFS(0,0);

    // 가장 먼저 도착한 depth 출력
    cout << a[N-1][M-1]<< '\n';
}

void BFS(int x, int y){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(x, y));
    visited[x][y] = true;

    while(!myqueue.empty()){
        // 큐에서 pop 하여 탐색
        int cur_x = myqueue.front().first;
        int cur_y = myqueue.front().second;

        myqueue.pop();

        // 상하좌우 보면서 탐색
        for(int i=0;i<4; i++){
            // 좌표 넣기
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            // 먼저 미로 안에 있고
            if(nx >=0 && ny >= 0 && nx <= N-1 && ny <= M-1){
                // 길이 갈 수 있고 방문하지 않았다면
                if((a[nx][ny] == 1) && (visited[nx][ny] == false)){
                    visited[nx][ny] == true;
                    myqueue.push(make_pair(nx,ny));
                    a[nx][ny] = a[cur_x][cur_y] + 1;
                }
            }
        }
    }
}

