#include<iostream>  
#include<string>  
#include<iomanip>  
using namespace std;  
int main()  
{  
    int k=0;  
    string str1,str2,str3,str4;  
    cin>>str1>>str2>>str3>>str4;  
      
    for(int i=0;i<str1.length(),i<str2.length();i++)  
    {  
        if(str1[i]==str2[i]&&k==1&&str1[i]>='A'&&str1[i]<='N')  
        {  
            cout<<str1[i]-'A'+10<<":";  
            k++;  
            break;  
        }  
        if(str1[i]==str2[i]&&k==1&&str1[i]>='0'&&str1[i]<='9')  
        {  
            cout<<'0'<<str1[i]-'0'<<":";  
            k++;  
            break;  
        }  
        if(str1[i]==str2[i]&&k==0&&str1[i]>='A'&&str1[i]<='G')  
        {             
            switch(str1[i]-'A')  
            {  
                case 0:  
                    cout<<"MON ";  
                    break;  
                case 1:  
                    cout<<"TUE ";  
                    break;  
                case 2:  
                    cout<<"WED ";  
                    break;  
                case 3:  
                    cout<<"THU ";  
                    break;  
                case 4:  
                    cout<<"FRI ";  
                    break;  
                case 5:  
                    cout<<"SAT ";  
                    break;  
                case 6:  
                    cout<<"SUN ";  
                    break;  
            }  
            k++;              
        }  
    }  
    for(int j=0;j<str3.length(),j<str4.length();j++)  
    {         
        if(str3[j]==str4[j]&&(str3[j]>='a'&&str3[j]<='z'||str3[j]>='A'&&str3[j]<='Z'))  
        {  
            cout<<setw(2)<<setfill('0')<<j<<endl;  
            break;  
        }  
    }  
    return 0;  
}  
  