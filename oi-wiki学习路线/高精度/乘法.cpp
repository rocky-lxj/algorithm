#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
int a[N];
string re(string s)
{
	for(int i=0,j=s.size()-1;i<j;i++,j--)swap(s[i],s[j]);
	return s;
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	s1=re(s1);
	s2=re(s2);
	int l=0;
	for(int i=0;i<s1.size();i++)
	{
		int f=0;
		for(int j=0;j<s2.size();j++)
		{
			int aa=s1[i]-'0';
			int bb=s2[j]-'0';
			a[i+j]+=aa*bb+f;
			f=a[i+j]/10;
			a[i+j]%=10;
			l=max(i+j,l);
		}
		if(f)
		{
			int c=0;
			while(f)
			{
				a[i+s2.size()+c]+=f%10;
				f=f/10+a[i+s2.size()+c]/10;
				l=max(l,i+(int)s2.size()+c);
				c++;
			}
		}
	}
	for(int i=l;~i;i--)cout<<a[i];
}