#include<iostream>
#include<cmath>
using namespace std;

int main(){
	long n, line,cpline,remain;
	char sign;
	double temp;
	long blank, stemp,btemp;
	cin >> n >> sign;
	temp = (n + 1) / 2;
	line = sqrt(temp);
	remain = n - (2 * line * line - 1);
	cpline = line;
	blank = 0;
	for (; line > 0; line--){
		btemp = blank;
		stemp = 2 * line - 1;
		while (btemp){
			cout << " ";
			btemp--;
		}
		while (stemp){
			cout << sign;
			stemp--;
		}
		cout << endl;
		blank++;
	}
	blank = blank - 2;
	for (line=2; line<=cpline; line++){
		btemp = blank;
		stemp = 2 * line - 1;
		while (btemp){
			cout << " ";
			btemp--;
		}
		while (stemp){
			cout << sign;
			stemp--;
		}
		cout << endl;
		blank--;
	}
	cout << remain << endl;
	system("pause");
	return 0;
}