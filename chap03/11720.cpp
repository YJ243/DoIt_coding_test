#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    int sum = 0;
    
    for(int i=0; i<s.size(); i++){
        int cur = s[i]-'0';
        sum += cur;
    }
    cout << sum << '\n';
}