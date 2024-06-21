#include <bits/stdc++.h>
using namespace std;
const int N =1e6+7;
int vis[N],prime[N];
int main()
{
    int n,c=0;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])prime[++c]=i;
        for(int j=1;prime[j]<=n/i;j++){
            vis[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
    printf("%d",c);
    return 0;
}