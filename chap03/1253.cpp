#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N,0);
    vector<int> good(N,0);
    int count = 0;
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            for(int k = 0;k<N; k++){
                if(a[i]+a[j] == a[k]){
                    good[k] = 1;
                    break;
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        if(good[i] == 1)
            count++;
    }
    cout << count << '\n';

}