#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool brokenKeys[257];

int main(){
	// ���뻵��
	char str[100005];
	memset(brokenKeys, 0, sizeof(brokenKeys));
	//  scanf("%s",str);
	gets(str); //scanf�޷�����մ�
	for (int i = 0; str[i]; ++i) {
		char ch = str[i];
		brokenKeys[ch] = 1;
		// Сд��ĸҲ�޷���ӡ
		if (ch >= 'A' && ch <= 'Z') {
			ch = ch - 'A' + 'a';
			brokenKeys[ch] = 1;
		}
	}
	//  if(strlen(str)!=0)getchar();// ���˻��з� ʹ��scanf��ʱ����Ҫ���ˣ�ʹ��gets����Ҫ

	// ���������ַ�
	char ch;
	while (scanf("%c", &ch) != EOF){
		// �ж���������ܷ�����
		if (brokenKeys[ch] == 0){

			// ���Ҫ��ӡ��д��ĸ����Ҫ�����ж��ϵ���
			if (ch >= 'A' && ch <= 'Z' && brokenKeys['+'] == 1) {
				continue;
			}
			cout << ch;
		}
	}
	return 0;
}