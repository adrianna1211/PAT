#include <iostream>
#include <string>
using namespace std;

int main(){
	long a[10] = {0};
	string n;
	cin >> n;
	for (int i = 0; i < n.length(); i++){
		int t = (n[i] - '0');
		a[t]++;
	}
	//cout << a[0];
	//system("pause");
	for (int j = 0; j < 10; j++){
		if (a[j] != 0)
		cout << j<<":"<< a[j] << endl;
	}
	system("pause");
	return 0;
}
