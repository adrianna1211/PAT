#include <iostream>
#include<string>
using namespace std;

int main(){
	int n, mod;
	char id[20];
	char weight[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char checksum[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };

//	int sum = 0;
	int unpass=0;
	cin >> n;

	for (int i = 0; i<n; i++){
		cin >> id;
		int sum = 0;
		bool error=false;
		for (int j = 0; j<17; j++){
			char ch = id[j];
			if ((ch>='0') &&(ch <= '9')){  //检查是不是都是数字
				ch = ch - '0';
				sum = ch* weight[j] + sum;
			}
			else{
				 error= true;
				 break;
			}
		}
		mod = sum % 11;
		if (checksum[mod] != id[17] || error == true){
			cout << id<<endl;
			unpass++;
		}
	}
	if (unpass == 0){
		cout << "All passed" << endl;
	}
	//system("pause");
	return 0;

}