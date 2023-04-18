#include <iostream>
#include <vector>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<vector<int>> numbers(N+1, vector<int>(N+1, 0));
    vector<vector<int>> sum(N+1, vector<int>(N+1, 0));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> numbers[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        sum[i][1] = numbers[i][1] + sum[i-1][1];
        sum[1][i] = numbers[1][i] + sum[1][i-1];
    }

    for(int i=2; i<=N; i++){
        for(int j=2; j<=N; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + numbers[i][j];
        }
    }

    for(int i=0; i<M; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
        cout << result << '\n';
    }


}