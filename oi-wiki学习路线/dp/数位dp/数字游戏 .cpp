#include <bits/stdc++.h>
using namespace std;
const int M = 1e6+6;
const int N = 3e5+7;
#define ll long long
#define en '\n'
#define debug cout<<"------"
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int dp[32][108];
int d[32];
int l,r,m,len;
int dfs(int len,int sum,bool f)
{
    //长度，抵达当前位置的总和模上mod，是否有限制，即不能超过当前数位
    if(len==0)return sum==0;//如果已经到底，就看sum是否为0
    //如果有限制，那么当前位置的答案数量是具有限制性的
    if(!f&&~dp[len][sum])return dp[len][sum];//如果此时没有限制，并且我们已经记录过当前位置上的值
    int ed=(f==1?d[len]:9);
    int ans=0;
    for(int i=0;i<=ed;i++)
    {
        ans+=dfs(len-1,(i+sum)%m,(f&&i==ed));
    }
    if(!f)dp[len][sum]=ans;
    return ans;
}
int calc(int x)
{
    len=0;
    while(x)
    {
        d[++len]=x%10;
        x/=10;
    }
    return dfs(len,0,1);
}
int main()
{
    fast
    while(cin>>l>>r>>m)
    {
        memset(dp,-1,sizeof dp);
        cout<<calc(r)-calc(l-1)<<en;
    }
    return 0;
}