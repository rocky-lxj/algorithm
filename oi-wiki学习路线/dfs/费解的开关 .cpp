//https://www.acwing.com/problem/content/submission/97/
#include<bits/stdc++.h>
using namespace std;
string s[10],s1[10];
#define per(i,a,b) for(int i=a;i<=b;i++)
int dx[10]={1,-1,0,0,0},dy[10]={0,0,1,-1,0};
void turn(int x,int y)
{
    per(i,0,4)
    {       
        if(s1[x+dx[i]][y+dy[i]]=='0')s1[x+dx[i]][y+dy[i]]='1';
        else s1[x+dx[i]][y+dy[i]]='0';
    }
}
void solve()
{
    per(i,1,5)cin>>s[i];
    int ans=10;
    per(i,0,31)
    {
        per(j,1,5)s1[j]=s[j];
        int step=0;
        per(j,0,4)
        {
            if(i>>j&1)
            {   
                step++;
                turn(1,j);
            }
        }
        per(j,1,4)
        {
            per(q,0,4)
            {
                if(s1[j][q]=='0')
                {
                    step++;
                    turn(j+1,q);
                }
            }
        }
        bool dark=0;
        per(j,0,4)
        {
            if(s1[5][j]=='0')
            {
                dark=1;
                break;
            }
        }
        if(dark==0)
        {
            ans=min(ans,step);
        }
    }
    if(ans>6)ans=-1;
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}