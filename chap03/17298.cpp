#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N+1, 0);
    vector<int> answer(N+1, -1);
    
    for(int i=1; i<=N; i++)
        cin >> a[i];

    for(int i=1; i<N; i++){
        vector<int> stack;
        for(int j=i+1; j<=N; j++){
            if(a[i] < a[j])
                stack.push_back(a[j]);
        }
        // 만약 큰수가 없다면
        if(stack.size() == 0)
            answer[i]=-1;
        else{
            int min = stack[0];
            for(int j=1; j<stack.size(); j++){
                if(min > stack[j]){
                    min = stack[j];
                }
            }
            answer[i] = min;
        }
    }

    for(int i=1; i<=N; i++)
        cout << answer[i] << ' ';
    cout << '\n';
}