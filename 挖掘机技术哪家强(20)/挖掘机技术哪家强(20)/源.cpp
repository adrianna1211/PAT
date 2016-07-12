#include<cstdlib>
#include<cstdio>
#include<map>
#include<iostream>
/************************************************************************
*
* Map的特点: 1、存储Key-value对
* 2、支持快速查找，查找的复杂度基本是Log(N)
* 3、快速插入，快速删除，快速修改记
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