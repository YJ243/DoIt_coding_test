#include <iostream>
#include <vector>
using namespace std;

static vector<vector <int>> A;
static vector<bool> visited;
void DFS(int v);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    A.resize(N+1); 
    visited = vector<bool>(N+1, false);

    for(int i=0; i<M; i++){
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }
    int count = 0;
    for(int i=1; i<=N; i++){
        if(visited[i] == false){
            // 방문하지 않았을 경우
            count++;
            cout<<i<<'\n';
            DFS(i);
        }
    }
    cout<<count<<'\n';
}

void DFS(int v){
    if(visited[v] == true)//만약 탐색하려는 노드가 방문했으면
        return; //바로 리턴

    visited[v] = true; // 방문했다 처리

    for(int i : A[v]){
        if(visited[i]==false){// v와 연결된 노드에 대해서 방문하지 않았으면
            //visited[i]=true;//방문했다 표시하고
            DFS(i);//DFS 수행
        }
    }
}