#include <iostream>
using namespace std;

long grades[101] = { 0 };//���гɼ�����
long amount(int mark);
int search[101];//��Ҫ��ѯ�ķ���
int main(){
	long n, k;
	cin >> n;
	int mark;
	for (int i = 0; i < n; i++){ //ÿ������ɼ�����Ӧ�ɼ���������1
		cin >> mark;
		grades[mark]++;
	}
	cin >> k;
	for (int j = 0; j < k; j++){
		cin >> search[j];
	}
	for (int j = 0; j < k; j++){
		int markS = search[j];
		cout << amount(markS);
		if (j != k - 1){
			cout << " ";
		}
	}
	
	return 0;
}
long amount(int mark){
		return grades[mark];
	}