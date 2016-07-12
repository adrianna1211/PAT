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
				if (cur[i] != org[i]) {//若为插入，则next及之后的元素都与org相同，不同则为merge；
					pro = merge;
					break;
				}
			}
		}
		if (pro == merge)//已确定为merge后不用再看后续
			break;
	}
	if (pro == insert) {
		cout << "Insertion Sort" << endl;
		for (unsigned int i = 0; i < cur.size(); ++i) {
			if (cur[i] < cur[next])//比下一个要插入的元素小的先输出
				cout << cur[i] << " ";
			else {
				cout << cur[next] << " ";//输出下一个要插入的元素
				vector<int>::iterator it = cur.begin() + next;
				cur.erase(it);//迭代器在cur中删除下一个要插入的元素
				for (; i < cur.size(); ++i) {//输出剩下的元素
					cout << cur[i];
					if (i != cur.size() - 1)
						cout << " ";
				}
			}
		}
	}
	else {
		cout << "Merge Sort" << endl;
		for (unsigned int i = 0; i < cur.size() / (next * 2); ++i)//下一次递归，每个有序子序列有2*next个元素
			sort(cur.begin() + i*next * 2, cur.begin() + i*next * 2 + next * 2);
		for (unsigned int i = 0; i < cur.size(); ++i) {
			cout << cur[i];
			if (i != cur.size() - 1)
				cout << " ";
		}
	}

	return 0;
}