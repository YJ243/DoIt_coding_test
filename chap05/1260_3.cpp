#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
static vector<bool>visited;
static vector<vector<int>> a;

void dfs(int start){
    if(visited[start]==true)
        return;
    visited[start] = true;
    cout << start << ' ';
    for(int i : a[start]){
        if(visited[i] == false){
            dfs(i);
        }
    }
}

void bfs(int start){
    visited[start] = true;
    queue<int> myqueue;
    myqueue.push(start);

    while(!myqueue.empty()){
        int cur = myqueue.front();
        myqueue.pop();
        cout << cur << ' ';
        for(auto i : a[cur]){
            if(visited[i]==false){
                visited[i]=true;
                myqueue.push(i);
            }
        }
    }
}
int main(){
    int n, m, v;
    cin >> n >> m >> v;
    a.resize(n+1);
    visited = vector<bool>(n,false);
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
    visited = vector<bool>(n, false);
    cout << '\n';
    bfs(v);
    
}
