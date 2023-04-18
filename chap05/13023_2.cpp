#include <iostream>
#include <vector>

using namespace std;

static vector<vector <int>> A;
static vector<bool> visited;
static bool arrive;
void DFS(int now, int depth);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    arrive=false;
    cin >> N >> M;
    A.resize(N);
    visited = vector<bool>(N, false);

    for(int i=0; i<M; i++){
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    for(int i=0; i<N; i++){
        // 각 노드마다 DFS 실행, 처음 depth=1
        DFS(i, 1);
        if(arrive){ // 깊이가 5에 도달한 적이 있다면
            break;
        }
    }
    if(arrive){
        cout << 1 << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
}

void DFS(int now, int depth){
    if (depth == 5 || arrive){
        // 깊이가 5가 되면 프로그램 종료
        arrive = true;
        return;
    }
    visited[now] = true;

    for(int i : A[now]){// 현재 노드의 연결 노드 중 방문하지 않은 노드에 대해 DFS 실행
        if(!visited[i]){
            DFS(i, depth+1); // 재귀 호출 시 depth를 1씩 증가하여 호출
        }
    }
    visited[now] = false;
}