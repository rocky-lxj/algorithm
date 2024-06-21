#include <bits/stdc++.h>
using namespace std;
const int M = 1e6+6;
const int N = 37;
#define ll long long
#define en '\n'
#define debug cout<<"------"
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int f[N][N], d[N];
int x, y, k, b;
int calc(int a)
{
  int tot=0;
  int sum=0;
  while(a)
  {
    d[++tot]=a%b;
    a/=b;
  }
  int t=0;//当前能取得的1数量
  for(int i=tot;i;i--)
  {
    if(t==k)break;
    if(d[i]==1)
    {
      sum+=f[i-1][k-t];
      //当前位置是1，我一定能保证后面全是1的情况存在
    }
    else if(d[i]>1) 
    {
      //如果我当前位置能取到大于1，那么当前位置也是可以取到的
      sum+=f[i][k-t];
      break;//为什么是break，因为再继续往下走，你再取方案数，就重复了
    }
  }
  if(t==k)sum++;//如果退出的时候，我能取得的1数跟我需要的一样，那么他自己就是一个符合条件的数字
  return sum;
}
int main() {
  
  // 初始化组合数
  f[0][0] = 1;
  //在第i位去j个1的方案数
  for (int i = 1; i <= 31; ++i) {
    f[i][0] = 1;
    for (int j = 1; j <= i; ++j) 
      f[i][j] = f[i-1][j-1] + f[i-1][j];
  }
  scanf("%d%d%d%d", &x, &y, &k, &b);
  printf("%d", calc(y) - calc(x-1));
}
