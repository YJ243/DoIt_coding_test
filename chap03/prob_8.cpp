#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> a(N, 0);

    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int count = 0;
    int K = 0;
    for(int i=0; i<N; i++){
        K = a[i];
        int start_index = 0;
        int end_index = N-1;
        while(start_index<end_index){
            if(a[start_index] + a[end_index] == K){
                if(start_index != i && end_index != i){
                    count++;
                    break;
                }
                else if(start_index == i)
                    start_index++;
                else if(end_index == i)
                    end_index--;
            }
            else if(a[start_index]+a[end_index] < K){
                start_index++;
            }
            else{
                end_index--;
            }
        }
    }

    cout << count << '\n';
}
