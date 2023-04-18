#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b;
    vector<char> answer;
    int num=1;
    int flag=0;    
    for(int i=0; i<n; i++){
        cin >> a[i];
        while(num <= a[i]){
            b.push_back(num);
            answer.push_back('+');        
            num++;    
        }
        if(b.back() > a[i]){
            flag = 1;
            
        }
        b.pop_back();
        answer.push_back('-');

    }
    if(flag == 1){
        cout << "NO" << '\n';
        return 0;
    }
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << ' ' ;
    }
    cout << '\n';
}