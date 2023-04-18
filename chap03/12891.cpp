#include <iostream>
using namespace std;

int Add(char c);
int Remove(char C);
int answer = 0;
int checkArr[4]={0};
int myArr[4]={0};
int checkSecret=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int S, P;
    cin >> S >> P;
    string str;
    cin >> str;
    for(int i=0; i<4; i++){
        cin >> checkArr[i];
    }


    for(int i=0; i<P; i++){
        
        switch (str[i]){
        case 'A':
            myArr[0]++;
            break;
        case 'C':
            myArr[1]++;
            break;
        case 'G':
            myArr[2]++;
            break;
        case 'T':
            myArr[3]++;
            break;
        }
        
        
    }
    
    for(int i=0; i<4; i++){
        if(myArr[i]>=checkArr[i])
            checkSecret++;
    }
    
    if(checkSecret == 4)
        answer++;
    for(int i=P; i<S; i++){
        int j=i-P;
        Add(str[i]);
        Remove(str[j]);

        if(checkSecret == 4)
            answer++;
    }
    cout << answer << '\n';
}

int Add(char c){
    switch (c){
    case 'A':
        myArr[0]++;
        if(checkArr[0] == myArr[0])
            checkSecret++;
        break;
    case 'C':
        myArr[1]++;
        if(checkArr[1] == myArr[1])
            checkSecret++;
        break;
    case 'G':
        myArr[2]++;
        if(checkArr[2] == myArr[2])
            checkSecret++;
        break;
    case 'T':
        myArr[3]++;
        if(checkArr[3] == myArr[3])
            checkSecret++;
        break;
    }
    return 0;
}   

int Remove(char c){
    switch (c){
    case 'A':
        if(checkArr[0] == myArr[0])
            checkSecret--;
        myArr[0]--;
        break;
    case 'C':
        if(checkArr[1] == myArr[1])
            checkSecret--;
        myArr[1]--;
        break;
    case 'G':
        if(checkArr[2] == myArr[2])
            checkSecret--;
        myArr[2]--;
        break;
    case 'T':
        if(checkArr[3] == myArr[3])
            checkSecret--;
        myArr[3]--;
        break;
    }
    return 0;
}
