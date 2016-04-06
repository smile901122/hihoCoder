#include <iostream>  
#include<string>  
#include<vector>  
using namespace std;  
  
  
int GetString(const string& str)  
{  
    int len=str.size();  
  
    vector<char> v;  
    char pre=NULL;//记录vector中最后一个元素  
    bool flag;//记录vector最后一个元素是否可以消除  
      
    for(int i=0;i<len;++i)  
    {  
        if(pre==str[i])  
        {  
             //后面还有相同的字符，且没和前面的pre挨着  
            if((i+1<len&&str[i+1]==pre)  
                &&flag==false)  
            {  
                v.push_back(str[i]);  
                flag=true;  
                continue;//pre不可以消除  
            }  
            while(i<len&&pre==str[i])  
                ++i;  
            --i;//上面while循环i多加了1，如果不减，for那里又加1，跳过一个字符  
  
            //可以消除最后一个元素  
            {  
                v.pop_back();  
                if(!v.empty())  
                {  
                    flag=false;  
                    pre=v.back();//更新pre  
                }  
                else  
                    pre=NULL;  
            }  
        }  
        else  
        {  
            v.push_back(str[i]);  
            flag=true;  
            pre=str[i];  
        }  
          
    }  
    string test(v.begin(),v.end());  
        return len-v.size();  
}  
int main()  
{  
    int n;  
    string s;  
    cin>>n;  
    string Insert="ABC";  
    while(n--)  
    {  
        cin>>s;  
        int max=0;  
        for(int i=0;i<s.size();++i)  
        {  
            for(int j=0;j<3;++j)  
            {  
                string str=s.substr(0,i+1)+Insert[j]+s.substr(i+1);  
                int n=GetString(str);  
                if(n>max)  
                    max=n;  
            }  
        }  
          
        cout<<max<<endl;  
  
    }  
          
        return 0;  
}
