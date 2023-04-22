#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<pair<int,int>>> a;
vector<bool> visited;
int finish;
int answer;
void dfs(int node);
int main(){
    cin >> n;
    a.resize(n+1);
    visited = vector<bool>(n+1, false);
    for(int i=0; i<n; i++){
        int node;
        cin >> node;
        while(1){
            int s,e;
            cin >> s;
            if(s == -1) break;
            cin >> e;
            a[node].push_back(make_pair(s,e));
        }
    }

    dfs(1);
    visited = vector<bool>(n+1, false);
    answer = 0;
    dfs(finish);
    cout << answer << '\n';
}

void dfs(int node){
    if(visited[node]==true) return;
    visited[node]= true;

    for(int i:a[node].first){

    }
}