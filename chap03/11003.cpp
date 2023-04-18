#include <iostream>
#include <vector>

using namespace std;

void Add(int n);
void Remove(int n);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    int min;
    vector<int> A(N+1,0);

    for(int i=1; i<=N; i++)
        cin >> A[i];
    
    vector<int> D(N+1, 0);
    min = A[1];
    for(int i=1; i<=N; i++){
        int j=i-L+1;
        if(j <= 0){
            //min은 A[1]부터 A[i]까지의 최소인 원소
            min = A[1];
            for(int k=1; k<=i; k++){
                if(min > A[k])
                    min = A[k];
            }
            D[i] = min;
        }
        else{
            // 이제 sliding window 처리
            min = A[j];
            for(int k=j+1; k<=i; k++){
                if(min > A[k]){
                    min = A[k];
                }
                D[i] = min;
            }
        }

    }
    for(int i=1; i<=N; i++)
        cout << D[i] << ' ';

    cout << '\n';

}