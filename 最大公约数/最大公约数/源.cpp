#include <iostream>
using namespace std;
int greatestCommonDivisor(int a, int b)
{
	int remain, min, max;
	min = (a>b) ? b : a;
	max = (a>b) ? a : b;
	remain = max%min;
	while (remain)
	{
		max = min;
		min = remain;
		remain = max%min;
	}
	return min;
}


int main(){
	int a, b;
	cin >> a >> b;
	int gcd = greatestCommonDivisor(a, b);
	cout << gcd << endl;
	return 0;
}
