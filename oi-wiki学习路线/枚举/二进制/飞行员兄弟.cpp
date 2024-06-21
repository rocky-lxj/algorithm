//https://www.mfstem.org/p/1257
//每次修改会变化，问怎么动才能把所有点改成同一个状态
/*
我们每个位置的变动都会影响到周围
但是每一个位置的操作次数只能操作一次，如果操作两次相当于无效操作
所以你每个位置只能操作或者不操作，那么你就需要去枚举每一种的情况
可以将 (i,j) 化作一维矩阵的形式，每次算出第几行第几列，并且你要你去枚举每一种状态,那么就是由你总共多少个数据决定的
也就是2^n种，只有在数据量较小的时候才可以用
*/
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