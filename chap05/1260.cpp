#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static vector<vector <int>> a;
static vector<bool> visited;
static vector<bool> visited_2;
void DFS(int v);
void BFS(int v);


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    a.resize(N+1);
    visited = vector<bool>(N+1, false);
    visited_2 = vector<bool>(N+1, false);
    for(int i=0; i<M; i++){
        int s,e;
        cin >> s >> e;
    
        a[s].push_back(e);
        a[e].push_back(s);
    }
    for(int i=1; i<=N; i++){
        sort(a[i].begin(), a[i].end());
    }
    // 시작 노드부터 탐색 시작
    DFS(V);
    cout << '\n';
    BFS(V);
}

void DFS(int v){
    if(visited[v] == true){
        return;
    }
    visited[v] = true;
    cout << v << ' ';
    for(auto i : a[v]){
        if(visited[i] == false){
            DFS(i);
        }
    }
}

void BFS(int v){
    queue<int> q;
    visited_2[v] = true;

    q.push(v);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int i : a[cur]){
            if(visited_2[i] == false){
                visited_2[i] = true;
                q.push(i);
            }
        }
    }
    cout << '\n';
}