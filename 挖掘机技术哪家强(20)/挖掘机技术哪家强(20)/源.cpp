#include<cstdlib>
#include<cstdio>
#include<map>
#include<iostream>
/************************************************************************
*
* Map���ص�: 1���洢Key-value��
* 2��֧�ֿ��ٲ��ң����ҵĸ��ӶȻ�����Log(N)
* 3�����ٲ��룬����ɾ���������޸ļ�
*
/************************************************************************/
using namespace std;

map<int, int> m;

int main(int argc, char *argv[]){
	int n;
	cin >> n;
	int max = 0;
	for (int i = 0; i<n; i++){
		int index, score;
		cin >> index >> score;
		m[index] += score;
		if (m[index]>m[max]){
			max = index;
		}
	}
	//map<int, int>::iterator it;
	//int index;
	//int maxscore = -1;
	//for (it = m.begin(); it != m.end(); it++){
	//	if (it->second>maxscore){
	//		index = it->first;
	//		maxscore = it->second;
	//	}
	//}
	cout << max <<" "<< m[max] << endl;


}