#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool brokenKeys[257];

int main(){
	// 存入坏键
	char str[100005];
	memset(brokenKeys, 0, sizeof(brokenKeys));
	//  scanf("%s",str);
	gets(str); //scanf无法读入空串
	for (int i = 0; str[i]; ++i) {
		char ch = str[i];
		brokenKeys[ch] = 1;
		// 小写字母也无法打印
		if (ch >= 'A' && ch <= 'Z') {
			ch = ch - 'A' + 'a';
			brokenKeys[ch] = 1;
		}
	}
	//  if(strlen(str)!=0)getchar();// 过滤换行符 使用scanf的时候需要过滤，使用gets则不需要

	// 处理输入字符
	char ch;
	while (scanf("%c", &ch) != EOF){
		// 判断这个符号能否打出来
		if (brokenKeys[ch] == 0){

			// 如果要打印大写字母，需要额外判断上档键
			if (ch >= 'A' && ch <= 'Z' && brokenKeys['+'] == 1) {
				continue;
			}
			cout << ch;
		}
	}
	return 0;
}