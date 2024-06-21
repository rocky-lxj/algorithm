// https://www.acwing.com/problem/content/description/732/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
const int M = 3e5+7;
#define ll long long
#define en '\n'
#define debug cout<<"------"
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int a[N];
int n;
bool check(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(x>a[i])x-=a[i];
        else x=x+x-a[i];
        if(x<0)return 0;
    }
    return 1;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=0,r=1e9;
    int ans=1e9;
    while(l<r)
    {
        int mid = (l+r)>>1;
        cout<<l<<" "<<r<<" "<<mid<<en;
        if(check(mid))r=mid,ans=min(ans,mid);
        else l=mid+1;
    }

    return 0;
}