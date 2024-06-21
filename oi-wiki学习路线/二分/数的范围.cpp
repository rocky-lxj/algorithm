// https://www.acwing.com/problem/content/791/
#include <bits/stdc++.h>
using namespace std;
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
const int N = 1e5+7;
int s[N];
int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	per(i,0,n-1)scanf("%d",&s[i]);
	while(t--)
	{
		int x;
		scanf("%d",&x);
		int idex1=lower_bound(s,s+n-1,x)-s;
		int idex2=upper_bound(s,s+n-1,x)-s;
		if(s[idex2]!=x)idex2--;
		if(s[idex1]==x&&s[idex2]==x)
		{
			printf("%d %d\n",idex1,idex2);
		}
		else printf("-1 -1\n");
	}
	return 0;
}