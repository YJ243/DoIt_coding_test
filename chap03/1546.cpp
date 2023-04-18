#include <iostream>

using namespace std;

int main(){
    int N = 0;
    cin >> N;
    int scores[1000];
    for(int i=0; i<N; i++)
        cin>>scores[i];
    
    int max = 0;
    long sum=0;
    for(int i=0; i<N; i++){
        if(max < scores[i])
            max = scores[i];
        sum += scores[i];
    }
    double results=0;
    results = sum*100.0/max/N;

    printf("%.3f\n", results);
}