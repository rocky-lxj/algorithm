#include<bits/stdc++.h>
using namespace std;

string re(string s)
{
	for(int i=0,j=s.size()-1;i<j;i++,j--)swap(s[i],s[j]);
	return s;
}
string add(string a,string b)
{
	if(a.size()<b.size())swap(a,b);
	int f=0;
	for(int i=0;a[i];i++)
	{
		int aa,bb;
		aa=a[i]-'0';
		if(i>=b.size())bb=0;
		else bb=b[i]-'0';
		a[i]=(aa+bb+f)%10+'0';
		f=(aa+bb+f)/10;
	}
	if(f)a+='1';
	return re(a);
}
int main()
{
	string a,b;
	cin>>a>>b;
	cout<<add(re(a),re(b));
	return 0;
}