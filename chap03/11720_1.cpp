#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
	int nCount = 0;
	int sum = 0;
	vector<int> intarray;

	cin >> nCount;
    string numbers;
	cin >> numbers;
	char array[nCount];
	//cout << numbers.substr(0,1);
	for (int i = 0; i<numbers.size(); i++) {
		array[i] = numbers[i];
	}
	for (int i = 0; i<nCount; i++) {
		intarray.push_back(array[i]);
		
		sum +=(intarray[i]-48);
	}
	cout << sum;
	return 0;
}