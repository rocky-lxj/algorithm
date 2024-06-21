#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
int nx[N];
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	for(int i=1,j=0;s2[i];i++)
	{
		while(j&&s2[i]!=s2[j])j=nx[j-1];
		if(s2[i]==s2[j])j++;
		nx[i]=j;
	}
	int ans=0;
	for(int i=0,j=0;s1[i];i++)
	{
		while(s1[i]!=s2[j]&&j)j=nx[j-1];
		if(s1[i]==s2[j])j++;
//		cout<<i<<" "<<j<<endl;
		if(j==s2.size())ans++;
	}
	cout<<ans;
	return 0;
}