#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){
	string sell;
	string need;
	bool enough = true;
	int less = 0;
	int more = 0;
	int sColor[257] = { 0 };
	int nColor[257] = { 0 };
	cin >> sell >> need;
	int lenS = sell.length();
	int lenN = need.length();
	for (int i = 0; i < lenS; i++){
		char ch = sell[i];
		sColor[ch]++;
	}
	for (int j = 0; j < lenN; j++){
		char ch = need[j];
		nColor[ch]++;
	}
	for (int i = 0; i < 257; i++){
		int diff = sColor[i] - nColor[i];
		if (diff<0){
			enough = false;
			less += abs(diff);
		}
		else if (diff>0){
			more += diff;
		}
	}
	if (enough == true){
		cout << "Yes " << more << endl;
	}
	else{
		cout << "No " << less << endl;
	}

	return 0;
}
