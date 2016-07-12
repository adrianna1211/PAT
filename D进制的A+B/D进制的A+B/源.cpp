#include<iostream>
#include<math.h>
using namespace std;
#define MAX 1000  
int main(){
	long long A, B, D,sum;
	cin >> A >> B >> D;
	int array[MAX];
	sum= A + B;
	//s = 0;
	long long i,j;
	i = 0;
	if (sum == 0)
		cout << 0 << endl;
	else{
		while (sum){
			array[i] = sum%D;
			sum = sum / D;
			i++;
		}
		i--;
		for (; i >= 0; i--)
		{
			cout << array[i];
		}
		
	}
	return 0;

}