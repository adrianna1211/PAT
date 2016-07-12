#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string N;
	int b,curr=0,q=0;
	vector<int> shang;
	cin>>N>>b;
	curr=N[0]-'0';
	if((N[0]-'0')>b){    //第一个数值大于除数
		shang.push_back((N[0]-'0')/b);
	}
	for(int i=1;i<N.length();i++){
		q= curr % b; //余数
		curr = q*10+(N[i]-'0');
		shang.push_back(curr/b); //商
	}
	q=curr%b; //余数
	if(N.length()==1&&(N[0]-'0')<b){
		cout<<"0 "<<N;
	}else{
		for(int n=0; n!=shang.size();n++){
			cout<<shang[n];
		}
		cout<<" "<<q;	
	}
	return 0;
}

