// https://www.acwing.com/problem/content/719/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
const int M = 3e5+7;
#define ll long long
#define en '\n'
#define debug cout<<"------"
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int f[N];
int dfs(int l)
{
    if(f[l])return f[l];
    if(l<=2)return l-1;
    f[l]=dfs(l-1)+dfs(l-2);
    return f[l];
}
int main()
{
    int n;
    cin>>n;
    f[2]=1;
    dfs(n);
    for(int i=1;i<=n;i++)cout<<f[i]<<" ";
    return 0;
}