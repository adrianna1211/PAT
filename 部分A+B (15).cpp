#include<stdio.h>  
#include<string>  
#include<iostream>  
#include<vector>  
  
using namespace std;  
  
int main(void)  
{  
    char *A = new char[11];  
    char *B = new char[11];  
    int pa = 0, pb = 0;  
  
    int da,db;  
  
    scanf("%s %d %s %d", A, &da, B, &db);  
      
    for(int ia = 0; A[ia] != '\0'; ia++)  
    {  
        if((A[ia]-'0') == da)  
            pa=pa*10+da;  
    }  
    for(int ib = 0; B[ib] != '\0'; ib++)  
    {  
        if((B[ib]-'0') == db)  
            pb=pb*10+db;  
    }  
    cout<<pa+pb<<endl;  
  
  
    return 0;  
}  