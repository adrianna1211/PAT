#include <iostream>
#include <string>
//#include <vector>
using namespace std;


int main(){
	string s;
	cin >> s;
	int len = s.size();
	//三重循环超时
	/*  for (long i = 0; i < len; i++){
	if (s[i] == 'P'){
	for (long j = i+1; j < len; j++)
	{
	if (s[j] == 'A'){
	for (long k = j+1; k < len; k++)
	{
	if (s[k] == 'T'){
	amount++;
	amount = amount % 1000000007;
	}
	}
	}
	}
	}
	}
	*/
	long p = 0;
	long pa = 0;
	long pat = 0;
	for (int i = 0; i<len; i++)
	{
		if (s[i] == 'P')
		{
			p++;
		}
		else if (s[i] == 'A')
		{
			pa = p + pa;
			pa = pa % 1000000007;
		}
		else if (s[i] == 'T')
		{
			pat = pat + pa;
			pat = pat % 1000000007;
		}
	}
	cout << pat;
	return 0;
}