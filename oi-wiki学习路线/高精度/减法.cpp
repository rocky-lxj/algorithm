#include <bits/stdc++.h>
using namespace std;
string re(string s)
{
	for(int i=0,j=s.size()-1;i<j;i++,j--)swap(s[i],s[j]);
	return s;
}
string solve(string a,string b)
{
	string ans;
	if(a<b||a.size()<b.size())ans+='-',swap(a,b);
	a=re(a),b=re(b);
	for(int i=a.size()-1;~i;i--)
	{
		int aa,bb;
		aa=a[i]-'0';
		bb=i>=b.size()?0:b[i]-'0';
		if(bb>aa)
		{
			for(int j=i+1;j<a.size();j++)
			{
				if(a[j]>='1')
				{
					a[j]-=1;
					break;
				}
				else a[j]='9';
			}
			a[i]+=10-bb;
		}
		else 
		{
			a[i]-=bb;
		}
	}
	if(a[a.size()-1]>'0')ans+=a[a.size()-1];
	for(int i=a.size()-2;~i;i--)ans+=a[i];
	return ans;
}
int main()
{
	string a,b;
	cin>>a>>b;
	string ans=solve(a,b);
	cout<<ans;
	return 0;
}