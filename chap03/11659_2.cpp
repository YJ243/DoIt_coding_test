#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int suNo, quizNo;
    cin >>suNo >> quizNo;

    int num[100001] = {};
    for(int i=1; i<=suNo; i++){
        int tmp;
        cin >> tmp;
        num[i] = num[i-1]+tmp;
    }

    for(int i=0; i<quizNo; i++){
        int start, end;
        cin >> start >> end;
        cout << num[end] - num[start-1] << '\n';
        
    }
}