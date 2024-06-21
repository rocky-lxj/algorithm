// https://www.acwing.com/problem/content/96/
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
bool vis[N];
void dfs(int len)
{
    if(len==n)
    {
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<en;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans[len+1]=i;
            dfs(len+1);
            vis[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    dfs(0);
    return 0;
}