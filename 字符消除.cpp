#include <iostream>  
#include <string>  
#include <vector>  
using namespace std;  
  
string getString(const string &str)  
{  
    int len = str.size();  
    if(len <= 1)    return str;  
    vector<char> v;  
    for(int i = 0; i + 1 < len; ++i)  
    {  
        if(str[i] == str[i + 1])  
        {  
            while(i + 1 <len && str[i] == str[i + 1])  
                ++i;  
        }  
        else    v.push_back(str[i]);  
    }  
    //最后一个元素  
    if(str[len - 2] != str[len - 1])  
        v.push_back(str[len - 1]); 
        
    return string(v.begin(), v.end());  
}  
int main()  
{  
    int n;  
    string s;  
    cin >> n;
    
    string Insert = "ABC";
    while(n--)  
    {  
        cin >> s;  
        int max = s.size();  
        int min = s.size();  
         
        for(int i = 0; i < s.size(); ++i)  
        {  
            for(int j = 0; j < 3; ++j)  
            {  
                string str = s.substr(0, i + 1) 
                                + Insert[j] + s.substr(i + 1);  
                int len = str.size();
                str = getString(str);
                while(len > str.size())  
                {  
                    len = str.size();
                    str = getString(str);
                }  
                if(min > str.size())  
                    min = str.size();  
            }  
        }  
        int result = max - min + 1;  
        cout << result << endl;  
    }  
    return 0;  
}  
