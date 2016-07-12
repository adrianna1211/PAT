#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, next = 0;
	cin >> N;
	vector<int> org, cur;
	enum property{insert, merge}pro = insert;
	for (int i = 0; i < N; ++i){
		int temp;
		cin >> temp;
		org.push_back(temp);
	}
	for (int i = 0; i < N; ++i){
		int temp;
		cin >> temp;
		cur.push_back(temp);
	}
		
	for (unsigned int i = 1; i < cur.size(); ++i) {
		if (cur[i] < cur[i - 1]) {
			next = i;
			for (; i < cur.size(); ++i) {
				if (cur[i] != org[i]) {//��Ϊ���룬��next��֮���Ԫ�ض���org��ͬ����ͬ��Ϊmerge��
					pro = merge;
					break;
				}
			}
		}
		if (pro == merge)//��ȷ��Ϊmerge�����ٿ�����
			break;
	}
	if (pro == insert) {
		cout << "Insertion Sort" << endl;
		for (unsigned int i = 0; i < cur.size(); ++i) {
			if (cur[i] < cur[next])//����һ��Ҫ�����Ԫ��С�������
				cout << cur[i] << " ";
			else {
				cout << cur[next] << " ";//�����һ��Ҫ�����Ԫ��
				vector<int>::iterator it = cur.begin() + next;
				cur.erase(it);//��������cur��ɾ����һ��Ҫ�����Ԫ��
				for (; i < cur.size(); ++i) {//���ʣ�µ�Ԫ��
					cout << cur[i];
					if (i != cur.size() - 1)
						cout << " ";
				}
			}
		}
	}
	else {
		cout << "Merge Sort" << endl;
		for (unsigned int i = 0; i < cur.size() / (next * 2); ++i)//��һ�εݹ飬ÿ��������������2*next��Ԫ��
			sort(cur.begin() + i*next * 2, cur.begin() + i*next * 2 + next * 2);
		for (unsigned int i = 0; i < cur.size(); ++i) {
			cout << cur[i];
			if (i != cur.size() - 1)
				cout << " ";
		}
	}

	return 0;
}