#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
static vector<bool>visited;
static vector<vector<int>> a;



void dfs(int node){
    if(visited[node]==true)
        return;
    visited[node] = true;
    cout<< node << ' ' ;
    for(int i : a[node])
    {
        if(visited[i]==false){
            dfs(i);
        }
    }
}

void bfs(int node){
    visited[node]=true;
    queue<int> myqueue;
    myqueue.push(node);

    while(!myqueue.empty()){
        int cur = myqueue.front();
        myqueue.pop();
        cout<< cur << ' ';
        for(int i : a[cur]){
            if(visited[i]==false){
                visited[i] = true;
                myqueue.push(i);
            }
        }
    }
}

int main(){
    int n, m, v;
    cin >> n >> m >> v;
    a.resize(n+1);
    visited = vector<bool>(n+1,false);
    for(int i=0; i<m; i++){
        int v, e;
        cin >> v >> e;
        a[v].push_back(e);
        a[e].push_back(v);
    }
    for(int i=1; i<=n; i++){
        sort(a[i].begin(), a[i].end());
    }
    dfs(v);
    visited = vector<bool>(n+1,false);
    cout<<'\n';
    bfs(v);
}