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
    visited = vector<bool>(n,false);
    for(int i=0; i<n; i++){
        if(arrive) break;
        dfs(i,1);

    }
    if(arrive) cout<<1<<'\n';
    else cout<<0<<'\n';

}
void dfs(int node, int depth){
    if(depth==5||arrive){
        arrive = 1;
        return;
    }
    if(visited[node]==true)
        return;
    visited[node] = true;

    for(int i : a[node]){
        if(visited[i]==false){
            dfs(i, depth+1);
        }
    }
    visited[node]=false;
    cout<<node<<'\n';
}