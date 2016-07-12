//#include <cstdio>
//#include <map>
#include <iostream>
#include <cstring> 

using namespace std;

int main(){

	char str1[85], str2[85];
//	char str[85];
	int ascii[200];

	cin >> str1 >> str2;

	memset(ascii, 0, sizeof(ascii));
//	memset(str, 0, sizeof(str));

	int length = (int)strlen(str1);
	int cnt = 0;
	for (int i = 0; i < length; ++i) {
		if (str2[cnt] != str1[i]) {
			char ch = str1[i];
			// 转为大写
			ch = toupper(ch);

			// 插入到map中,避免重复
			if (ascii[ch] == 0) {
				++ascii[ch];
				//int len = (int)strlen(str);
				//str[len] = ch;
				cout << ch;
			}
		}
		else{
			++cnt;
		}
	}
	system("pause");
	//printf("%s\n", str);
	return 0;
}