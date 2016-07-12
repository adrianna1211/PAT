#include<iostream>
#include<string>
using namespace std;
int len, len2;
int main(){
	bool brokenKey[257] = { false }; //ASCII码使用指定的7位或8位二进制数组合来表示128或256种可能的字符。
	string suppose;
	string bStr;
	cin >> bStr;	
	len = bStr.length();
	for (int i = 0; i < len; i++){
		brokenKey[bStr[i]] = true;//标记坏键
		if (bStr[i] >= 'A'&&bStr[i] <= 'Z'){//如果是大写字母，小写字母也无法输出
			char lower = tolower(bStr[i]);
			brokenKey[lower] =true;
		}
	}
	cin >> suppose;
	len2 = suppose.length();
	for (int j = 0; j < len2; j++){
		char ch = suppose[j];
		if (!brokenKey['+']){//uppercase键没坏
			if (!brokenKey[ch]){//没被标记坏键
				cout << ch;
			}
		}
		//uppercase坏了，所有大写字母都无法输出
		else{
			if (ch >= 'A'&&ch <= 'Z'){//所有大写字母都无法输出
				continue;
			}
			else if (!brokenKey[ch]){//没被标记坏键
					cout << ch;
			}
		}
	}
	cout << endl;
	return 0;	
}