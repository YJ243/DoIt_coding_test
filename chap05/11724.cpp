#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int start_node, int* visited, vector<vector<int>> a){
    vector<int> stack;
    visited[start_node]=1;
    stack.push_back(start_node);
    while(!stack.empty()){
        int v = stack.back();
        stack.pop_back();
        for(int i=0; i<a[v].size(); i++){
            int node = a[v][i];
            if (visited[node] == 0){
                visited[node] = 1;
                stack.push_back(node);
            }
        }
    }

}

int main(){
    int n, m;
    cin >> n >> m;
    int answer = 0;    
    vector<vector<int>> a(n+1); 
    int visited[n+1] = {0};    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(visited[i] == 0){ /
            DFS(i, visited, a);
            answer++;
        }

    }
    cout << answer << '\n';
}