#include <iostream>
#include <deque>

using namespace std;
typedef pair<int, int> Node; // <num, index>
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;
    deque<Node> mydeque;

    for(int i=0; i<N; i++){
        int now;
        cin >> now; // 배열 값

        //cout<< "current size: " << mydeque.size() << '\n';
        // 값이 들어올 떄마다 정렬하지 않고
        // 현재 수보다 큰 값을 덱에서 제거해서 시간 복잡도를 줄임
        while(mydeque.size() && (mydeque.back().first > now)){
            cout << "back: " << mydeque.back().first << '\n';
            mydeque.pop_back();
        }
        mydeque.push_back(Node(now, i));

        // 범위에서 벗어난 값은 덱에서 제거
        if(mydeque.front().second <= i - L){
            mydeque.pop_front();
        }
        cout << mydeque.front().first << ' ';
    }
}