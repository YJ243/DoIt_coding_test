#include <iostream>
#include <vector>

using namespace std;

void DFS(int node, vector<vector <int>> a, vector<int> visited, int* depth, bool answer){
    if(*depth == 4){
        // 각 노드부터 시작해서 끝까지 탐색하는 과정 중 depth가 4이면 return
        cout << "1" << '\n';
    
        /*
        cout << "depth " << depth << '\n';
        answer = true;
        */
        return;
    }
    if(visited[node]){
        return;
    }
    visited[node]=true;

    for(int i : a[node]){
        if(visited[i] == false){
            DFS(i, a, visited, depth+1, answer);
        }
    }

}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector <int>> a(n);

    for(int i=0; i<m; i++){
        int v,s;
        cin >> v >> s;

        // 인접리스트로 그래프 표현
        a[v].push_back(s);
        a[s].push_back(v);
    }
    //vector<int> visited(n, 0);
    // DFS 탐색을 하면서 node는 5개, depth는 4인 그래프가 있는지 확인
    for(int i=0; i<n; i++){
        // 각 노드에 대해서 연결된 노드 개수 확인--> 5개이면 answer++
        vector<int> visited(n, 0);
        int *depth = 0;
        bool answer = false;
        DFS(i, a, visited, depth, answer);
        if(answer == true){
            cout << '1' << '\n';
            return 0;
        }
    }
    cout << '0' << '\n';
}