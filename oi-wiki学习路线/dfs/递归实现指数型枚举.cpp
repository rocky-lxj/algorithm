//https://www.acwing.com/problem/content/94/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
const int M = 3e5+7;
#define ll long long
#define en '\n'
#define debug cout<<"------"
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n;
int ans[N];
void dfs(int c,int len,int id)
{
    if(id==len)
    {
        for(int i=1;i<=len;i++)cout<<ans[i]<<" ";
        cout<<en;
        return ;
    }
    for(int i=c;i<=n;i++)
    {
        ans[id+1]=i;
        dfs(i+1,len,id+1);
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        dfs(1,i,0);
    }
    return  0;
}