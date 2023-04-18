#include <iostream>

using namespace std;

int main(){
    long N;
    long answer=0;
    cin >> N;
    int divide = 0;
    
    for(int i=0; i<N; i++){
        if(N % (1+(2*i)) == 0){
            answer++;
        }
    }

    cout << answer << '\n';    
}