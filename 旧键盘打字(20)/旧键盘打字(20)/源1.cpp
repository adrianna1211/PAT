#include<iostream>
#include<string>
using namespace std;
int len, len2;
int main(){
	bool brokenKey[257] = { false }; //ASCII��ʹ��ָ����7λ��8λ���������������ʾ128��256�ֿ��ܵ��ַ���
	string suppose;
	string bStr;
	cin >> bStr;	
	len = bStr.length();
	for (int i = 0; i < len; i++){
		brokenKey[bStr[i]] = true;//��ǻ���
		if (bStr[i] >= 'A'&&bStr[i] <= 'Z'){//����Ǵ�д��ĸ��Сд��ĸҲ�޷����
			char lower = tolower(bStr[i]);
			brokenKey[lower] =true;
		}
	}
	cin >> suppose;
	len2 = suppose.length();
	for (int j = 0; j < len2; j++){
		char ch = suppose[j];
		if (!brokenKey['+']){//uppercase��û��
			if (!brokenKey[ch]){//û����ǻ���
				cout << ch;
			}
		}
		//uppercase���ˣ����д�д��ĸ���޷����
		else{
			if (ch >= 'A'&&ch <= 'Z'){//���д�д��ĸ���޷����
				continue;
			}
			else if (!brokenKey[ch]){//û����ǻ���
					cout << ch;
			}
		}
	}
	cout << endl;
	return 0;	
}