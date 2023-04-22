#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >>k;
    vector<int> a(n,0);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    int answer = 0;
    for(int i=0; i<n; i++){
        if(k == 0)
            break;
        if(a[i] > k)
            continue;
        else
        {
            answer += (k/a[i]);
            k = k % a[i];   
        }
    }
    cout << answer << '\n';    
}