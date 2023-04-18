#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> a(N,0);
    
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    
    int start_index = 0;
    int end_index = 0;
    int sum = 0;
    int count = 0;
    
    while(start_index != (N-1)){
        sum = a[start_index];
        for(end_index=start_index; end_index<N; end_index++){
            sum += a[end_index];
            if(sum == M){
                count++;
                sum -= a[end_index];            
            }
            else{
                sum -= a[end_index];
            }
        }
        sum -= a[start_index];
        start_index++;
    }

    cout<< count << '\n';
}