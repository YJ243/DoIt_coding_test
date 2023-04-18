#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int scores[1001] = {0};
    double max = 0;
    double sum = 0;
    double answer = 0.0;
    for(int i=0; i<N; i++){
        cin >> scores[i];
        if(max < scores[i])
            max = scores[i];
        sum += scores[i];
    }
    answer = (sum /max) * 100 / N;
    cout << answer;
}