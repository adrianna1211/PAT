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
		if (i == row || i == 1){//����Ƕ�׵ıȽϸ��ӣ�Ҳ���Ե�һ�С����һ��ֱ����������ж��Ƿ�Ϊ���һ�С�
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