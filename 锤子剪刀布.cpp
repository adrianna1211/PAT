#include <cstdio>
int main()
{
    int n;
    int a1=0,a2=0,a3=0;//甲赢、平局、乙赢
    int aJ=0,aC=0,aB=0;//出什么方式赢得多
  int bJ=0,bC=0,bB=0;
    char x,y,blank;
  scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
    getchar();
  scanf("%c%*c%c",&x,&y);
  if((x=='C')&&(y=='J')) 
    {
      a1++; aC++; 
      continue;
    }
  if((x=='J')&&(y=='B')) 
    {
      a1++; aJ++; 
      continue;
    }
  if((x=='B')&&(y=='C')) 
    {
      a1++; aB++; 
      continue;
    }
  if((x=='C')&&(y=='C')) 
    {
      a2++; 
      continue;
    }
  if((x=='J')&&(y=='J')) 
    {
      a2++; 
      continue;
    }
  if((x=='B')&&(y=='B')) 
    {
      
      a2++; 
      continue;
    }
  if((x=='C')&&(y=='B')) 
    {
      a3++; bB++; 
      continue;
    }
  if((x=='B')&&(y=='J')) 
    {
      a3++; bJ++; 
      continue;
    }
  if((x=='J')&&(y=='C')) 
    {
      a3++; bC++; 
      continue;
    }
    }
  printf("%d %d %d\n",a1,a2,a3);
  printf("%d %d %d\n",a3,a2,a1);
    if((aB>=aC) && (aB>=aJ))
    printf("B");
    else if(aC >= aJ)
  printf("C");
    else
  printf("J");
    if((bB>=bC) && (bB>=bJ))
  printf(" B\n");
    else if(bC>=bJ)
  printf(" C\n");
    else
  printf(" J\n");
    return 0;
}