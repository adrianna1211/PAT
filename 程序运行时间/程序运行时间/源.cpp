#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	long c1, c2, allSec,sec, min, hour;
	long remain;

	cin >> c1 >> c2;
	allSec = (c2 - c1) / 100;
	remain = (c2 - c1) % 100;
	if (remain >= 50)
		allSec++;
	if (allSec < 60){
		if (allSec >= 10)
			cout << "00:00:" << allSec << endl;
		else
			cout << "00:00:0" << allSec << endl;
	}
	else if (allSec < 3600){
		min = allSec / 60;
		sec = allSec % 60;
		if (min >= 10){
			if (sec>=10)
				cout << "00:" << min <<":"<< sec<< endl;
			else{
				cout << "00:" << min << ":0" << sec << endl;
			}
		}
		else{//min<10
			if (sec >= 10){
				cout << "00:0" << min << ":" << sec << endl;
			}
			else{
				cout << "00:0" << min << ":0" << sec << endl;
			}
		}
	}
	else{//ÓÐÐ¡Ê±
		hour = allSec / 3600;
		min = (allSec % 3600)/60;
		sec = (allSec % 3600)%60;
		if (hour >= 10){
			if (min >= 10){
				if (sec >= 10)
					cout << hour <<":"<< min << ":" << sec << endl;
				else{
					cout << hour<<":" << min << ":0" << sec << endl;
				}
			}
			else{//min<10
				if (sec >= 10){
					cout <<hour<<":0" << min << ":" << sec << endl;
				}
				else{
					cout <<hour<< ":0" << min << ":0" << sec << endl;
				}
			}
			//cout << allSec/3600

		}
		else{
			if (min >= 10){
				if (sec >= 10)
					cout <<"0"<< hour << ":" << min << ":" << sec << endl;
				else{
					cout <<"0"<< hour << ":" << min << ":0" << sec << endl;
				}
			}
			else{//min<10
				if (sec >= 10){
					cout <<"0"<< hour << ":0" << min << ":" << sec << endl;
				}
				else{
					cout << "0"<<hour << ":0" << min << ":0" << sec << endl;
				}
			}
			//cout << allSec/3600
		}
		
	}
	system("pause");
	return 0;
}