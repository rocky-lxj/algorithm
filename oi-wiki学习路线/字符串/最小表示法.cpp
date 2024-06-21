#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
int s[N];
int n;
int get_ans()
{
    int i=0,j=1,k=0;
    while(i<n&&j<n)
    { 
        if(s[i+k]==s[j+k])k++;
        else 
        {
            if(s[i+k]>s[j+k])
            {
                i+=k+1;
            }
            else 
            {
                j+=k+1;
            }
            if(i==j)j++;
            k=0;
        }
    }
    return min(i,j);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i],s[i+n]=s[i];
    int ans=get_ans();
    for(int i=0;i<n;i++)cout<<s[i+ans]<<" ";
    return 0;
}