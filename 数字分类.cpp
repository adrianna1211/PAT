#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
	int N,a[1000],count=0,max=0;
	int flage1=0,flage2=0,flage3=0,flage4=0,flage5=0;
	long sum1=0,sum2=0,sum3=0;
	float sum4=0.0;
	bool mark=true;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}

	for(int j=0;j<N;j++){
		
		if(a[j]%5==0){
			if(a[j]%2==0){
				sum1=sum1+a[j];
				flage1=1; //应该放这里
			}
			//flage1=1; 不能放这里
		}

		if(a[j]%5==1){
			flage2=1;
			if(mark){
				sum2 = sum2+a[j];
				mark=false;
			}else{
				sum2=sum2-a[j];
				mark=true;
			}
			
		}	
		if(a[j]%5==2){
			flage3=1;
			sum3++;
		}
		if(a[j]%5==3){
			flage4=1;
			count++;
			sum4 = sum4+a[j];
		}

		if(a[j]%5==4){
			if(max<a[j]){
				max=a[j];
			}
			flage5=1;
		}
	}
	sum4 = sum4/count;
	
	if(flage1==0){
		cout<<"N"<<" ";
	}else{
		cout<<sum1<<" ";
	}
	if(flage2==0){
		cout<<"N"<<" ";
	}else{
		cout<<sum2<<" ";
	}
	if(flage3==0){
		cout<<"N"<<" ";
	}else{
		cout<<sum3<<" ";
	}
	if(flage4==0){
		cout<<"N"<<" ";
	}else{
		cout<<setiosflags(ios::fixed)<<setprecision(1)<<sum4<<" ";
		//当上面的一大串英文不会写时，就用下面滴printf函数
		//printf("%0.1f ",sum4);
	}

	if(flage5==0){
		cout<<"N";
	}else{
		cout<<max;
	}

	return 0;
}