#include <iostream>
#include <vector>

using namespace std;
static vector<vector<int>> a;
static vector<bool> visited;
void dfs(int node){
    if(visited[node])
        return;
    visited[node] = true;

    for(int i : a[node]){
        if(visited[i] == false)
            dfs(i);
    }

}

int main(){
    int n, m;
    cin >> n >> m;
    a.resize(n+1);
    visited = vector<bool>(n+1, false);
    for(int i=0; i<m; i++){
        int v, w;
        cin >> v >> w;
        a[v].push_back(w);
        a[w].push_back(v);
    }

    int answer = 0;
    for(int i=1; i<=n; i++){
        
        if(visited[i] == false){
            answer++;
            dfs(i);
        }
    }
    cout << answer << '\n';
}