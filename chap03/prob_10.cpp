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
        cin >> now; // �迭 ��

        //cout<< "current size: " << mydeque.size() << '\n';
        // ���� ���� ������ �������� �ʰ�
        // ���� ������ ū ���� ������ �����ؼ� �ð� ���⵵�� ����
        while(mydeque.size() && (mydeque.back().first > now)){
            cout << "back: " << mydeque.back().first << '\n';
            mydeque.pop_back();
        }
        mydeque.push_back(Node(now, i));

        // �������� ��� ���� ������ ����
        if(mydeque.front().second <= i - L){
            mydeque.pop_front();
        }
        cout << mydeque.front().first << ' ';
    }
}