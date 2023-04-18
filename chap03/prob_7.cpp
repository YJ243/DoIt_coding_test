#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    vector<int> a(N, 0);

    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int i=0;
    int j=N-1;
    int count = 0;
    while(i<j){
        if(a[i]+a[j] > M){
            j--;
        }
        else if(a[i]+a[j] < M){
            i++;
        }
        else if(a[i]+a[j] == M){
            count++;
            i++;
            j--;
        }
    }
    cout << count << '\n';
}