#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int V;
typedef pair<int, int> Node;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V;
    vector<vector< pair<int,int>>> a(V+1); 
    for(int i=1; i<=V; i++){
        while(1){
            int node, len;
            
            cin >> node;
            if(node == -1)
                break;
            if( node == i) continue;
            cin >>  len;
            a[i].push_back(make_pair(node, len));
        }
    }

    int node_depth[V+1][V+1] = {0};
    /*
    for(int i=1; i<=V; i++){

    }
*/
    cout << a[0][1]<< "\n";
}