#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<long> P;
//long A[100005];
//long T[100005];
vector<long> A;
vector<long> T;
string s;
long amount = 0;
int main(){
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++){
		if (s[i] == 'P'){
			P.push_back(i);
		}
		else if (s[i]=='A')
		{
			A.push_back(i);
		}
		else if (s[i] == 'T'){
			T.push_back(i);
		}
	}
	long sP, sA, sT;
	sP = P.size();
	sA = A.size();
	sT = T.size();
	bool hasP = 0;
	long np = 0;
	long nt = 0;
	for (int i = 0; i < sA; i++){
		for (int j = 0; j < sP; j++){
			if (P[j] < A[i]){
				hasP = true;
				continue;
			}
			else
			{
				if (hasP){
					np = j;//有np个P在A前面
				}
				break;

			}
		}
		if (!hasP){ //A前没有P，执行下一个循环，看下一个A
			continue;
		}
		for (int k = 0; k < sT; k++){
			if (T[k] < A[i]){
				continue;
			}
			else
			{
				nt++;
			}
		}
		amount += np*nt;
	}
	cout << amount;
	return 0;
}