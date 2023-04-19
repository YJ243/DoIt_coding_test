#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
static vector<vector <edge>> A;
static vector<bool> visited;
static vector<int> m_distance;
void BFS(int node);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A.resize(N+1);

    for(int i=0; i<N; i++){
        int S;
        cin >> S;
        while (true){
            int E,V;
            cin >> E;
            if(E == -1)
                break;
            cin >> V;
            A[S].push_back(edge(E,V));
        }
    }
    m_distance = vector<int>(N+1, 0);
    visited = vector<bool>(N+1, 0);
    BFS(1);
    int Max = 1;

    for(int i=2; i<=N; i++){
        if(m_distance[i] >m_distance[Max]){
            Max = i;
        }
    }

    fill(m_distance.begin(), m_distance.end(), 0); // 거리 배열 초기화
    fill(visited.begin(), visited.end(), 0); // 방문 배열 초기화
    BFS(Max); // 거리 배열에서 가장 큰 값을 다시 시작점으로 지정
    Max = 1;
    for(int i=2; i<=N; i++){
        if(m_distance[i] >m_distance[Max]){
            Max = i;
        }
    }
    cout << m_distance[Max] << '\n';
}

void BFS(int start){
    queue<int> myqueue;
    visited[start] = true;
    myqueue.push(start);

    while(!myqueue.empty()){
        int cur = myqueue.front();
        myqueue.pop();

        // 만약 cur과 연결된 리스트의 노드를 방문하지 않았다면
        for(edge i : A[cur]){
            if(visited[i.first] == false){
                visited[i.first] = true;
                myqueue.push(i.first);
                m_distance[i.first] = i.second + m_distance[cur];//이전것//
            }
        }

    }
}