#include <iostream>
#include <deque>

using namespace std;
typedef pair<int, int> Node; // (num, index)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;
    deque<Node> mydeque;

    int now;
    for(int i=0; i<N; i++){
        cin >> now;

        while(mydeque.size() && mydeque.back().first > now){
            mydeque.pop_back();
        }
        mydeque.push_back(Node(now, i));

        if(mydeque.front().second <= i-L)
            mydeque.pop_front();
        cout << mydeque.front().first << ' ';
    }

}