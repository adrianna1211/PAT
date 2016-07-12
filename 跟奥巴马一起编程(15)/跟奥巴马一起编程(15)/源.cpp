#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n;
	char c;
	cin >> n >> c;
	int col = n;
	int k;
	int row = floor((double)col / 2 + 0.5);
	for (int i = row; i>0; i--){
		if (i == row || i == 1){//这里嵌套的比较复杂，也可以第一行、最后一行直接输出，不判断是否为最后一行。
			k=n;
			while (k>0){
				cout << c;
				k--;
			}
			cout << endl;
		}
		else{
			for (int j = col; j > 0; j--){
				if (j == col){
					cout << c;
				}
				else if (j == 1){
					cout <<c<< endl;
				}
				else {
					cout << ' ';
				}
			}
		}
	}


	return 0;
}