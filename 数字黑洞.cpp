#include<iostream>  
#include<algorithm>  
using namespace std;  
static int a,b;  
  
void arrange(int n)  
{  
    int temp[4];  
    temp[0]=n/1000;  
    temp[1]=n/100%10;  
    temp[2]=n/10%10;  
    temp[3]=n%10;  
    sort(temp,temp+4);  
    a=temp[0]*1000+temp[1]*100+temp[2]*10+temp[3];  
    b=temp[3]*1000+temp[2]*100+temp[1]*10+temp[0];  
}  
  
int main()  
{  
    int n,result;  
    scanf("%d",&n);  
    if(n%1111==0)  
    {  
        printf("%04d - %04d = 0000\n",n,n);  
        return 0;  
    }  
    do{  
        arrange(n);  
        result=b-a;  
        printf("%04d - %04d = %04d\n",b,a,result);  
        n=result;  
    }while(result!=6174);  
    return 0;  
}  