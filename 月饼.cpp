#include<iostream>  
#include<algorithm>  
using namespace std;  
struct mp{           //包含每种月饼的数量总价单价  
    float num;  
    float tot;  
    float pri;  
} pie[1001];  
  
bool greater_pri(mp pie1,mp pie2)   //根据单价降序排序  
{  
    return pie1.pri>pie2.pri;  
}  
  
int main()  
{  
    int n,m,i,j;  
    float result=0.0;  
    scanf("%d%d",&n,&m);  
  
    for(i=0;i<n;i++)  
        scanf("%f",&pie[i].num);  
  
    for(i=0;i<n;i++)  
        scanf("%f",&pie[i].tot);  
  
    for(i=0;i<n;i++)  
        pie[i].pri=pie[i].tot/pie[i].num;  
  
    sort(pie,pie+n,greater_pri);  
      
    for(j=0;j<n;j++)  
    {  
        if(m>pie[j].num)  
        {  
            m-=pie[j].num;  
            result+=pie[j].tot;  
        }  
        else  
        {  
            result+=pie[j].pri*m;  
            m-=pie[j].num;  
        }  
        if(m<0)  
            break;  
    }  
  
    printf("%.2f\n",result);  
    return 0;  
}  
