#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, p;
	int seq[100005];
	int num = 1;
	cin >> n >> p;

	for (int i = 0; i<n; i++){
		cin >> seq[i];
	}
	sort(seq, seq + n);

	for (int i = 0; i<n; i++){
		for (int j = i + num - 1; j<n; j++){
			if (seq[j] <= seq[i] * p){
				num = j - i + 1;
			}
			else{
				break;
			}
		}

	}
	cout << num;
	system("pause");
	return 0;
}