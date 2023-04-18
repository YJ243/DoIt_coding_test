#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    string a;
    cin >> a;

    int sum = 0;
    for(int i=0; i<a.length(); i++){
        sum += a[i] - 48;
    }    

    cout << sum << '\n';
}