#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	int b;
	cin >> n >> b;
	string ans;

	while(n>0) {
		int remain = n % b;
		if (remain < 10) {
            //0~9이면 숫자를 char로 바꾸어서 붙이기

            ans += remain + '0';
		}
		else{
            // A~Z로 변환해서 붙이기
			// 만약 10이면 A, 11이면 B로
			ans += remain - 10 +'A';
        }
		n /= b;
	}



	for (int i = ans.size()-1; i >= 0; i--)
		cout << ans[i];
	cout << '\n';
	
    return 0;

}