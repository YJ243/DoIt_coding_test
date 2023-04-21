#include <iostream>
#include <vector>

using namespace std;
static vector<bool> visited;
static vector<vector<int>> a;
int n, m;
int arrive=0;
void dfs(int node, int depth);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    a.resize(n);
    for(int i=0; i<m; i++){
        int v, e;
        cin >> v >> e;
        a[v].push_back(e);
        a[e].push_back(v);

    }

    for(int i=0; i<n; i++){
        visited = vector<bool>(n, false);
        int depth = 1;
        dfs(i, depth);
        if(arrive) break;
    }
    if(arrive) cout<< "1" << '\n';
    else cout<<"0"<<'\n';
}

void dfs(int node, int depth){
    if(depth==5||arrive){
        arrive=true;
        return;
    }
    visited[node] = true;
    
    for(int i : a[node]){
        // 현재 노드에 연결된 노드에 대해서 탐색
        if(visited[i] == false){
            dfs(i, depth+1);
        }
    }

}