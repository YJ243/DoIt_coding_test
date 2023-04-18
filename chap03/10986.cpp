#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    long answer = 0;
    vector<long> sum(N+1, 0);
    vector<long> remainder(M, 0);

    for(int i=1; i<=N; i++){
        int tmp;
        cin >> tmp;
        sum[i] = sum[i-1] + tmp;
    }

    for(int i=1; i<=N; i++){
        sum[i] %= M;
        if(sum[i] == 0)
            answer++;
        remainder[sum[i]]++;
    }
    for(int i=0; i<M; i++){
        long temp = remainder[i];
        if(temp > 1)
            answer += (temp)*(temp-1)/2;
    }
    cout << answer << '\n';
}