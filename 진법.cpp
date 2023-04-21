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
            //0~9�̸� ���ڸ� char�� �ٲپ ���̱�

            ans += remain + '0';
		}
		else{
            // A~Z�� ��ȯ�ؼ� ���̱�
			// ���� 10�̸� A, 11�̸� B��
			ans += remain - 10 +'A';
        }
		n /= b;
	}



	for (int i = ans.size()-1; i >= 0; i--)
		cout << ans[i];
	cout << '\n';
	
    return 0;

}