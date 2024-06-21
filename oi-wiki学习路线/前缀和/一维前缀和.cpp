#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
const int M = 3e5+7;
#define ll long long
#define en '\n'
#define debug cout<<"------"
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<en;
    }
    return 0;
}