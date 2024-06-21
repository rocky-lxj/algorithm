//https://www.acwing.com/problem/content/118/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
char a[5][5],b[5][5];
int ans[N][2];
int len;
char change2(char c)
{
	if(c=='+')return '-';
	else return '+';
}
void change1(int x,int y)
{
	for(int i=1;i<=4;i++)
	{
		b[i][x]=change2(b[i][x]);
		b[y][i]=change2(b[y][i]);
	}
	b[y][x]=change2(b[y][x]);
}
bool check(int l)
{
	len=0;
	memcpy(b,a,sizeof a);
	int x=1,y=1;
	for(int i=1;i<=16;i++)
	{
		if(l&1)
		{
			change1(x,y);
			len++;
			ans[len][0]=y;
			ans[len][1]=x;
		}
		x++;
		if(x==5)x=1,y++;
		l>>=1;
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(b[i][j]=='+')return 0;
		}
	}
	cout<<len;
	for(int i=1;i<=len;i++)
	{
		cout<<endl<<ans[i][0]<<" "<<ans[i][1];
	}
	return 1;
}
int main()
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)cin>>a[i][j];
	}
	int l=(1<<16)-1;
	for(int i=1;i<=(1<<16)-1;i++)
	{
		if(check(i))break;
	} 
	return 0;
}