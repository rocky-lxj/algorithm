#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define PII pair<int,int>
const int N = 1e5+7;
vector<int>v1,v2;
string s,s1,s2;
int n;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int ans=0;
	for(int i=0;i<s1.size()-1;i++)
	{
		if(s1[i]!=s2[i])
		{
			ans++;
			s1[i]=s2[i];
			if(s1[i+1]=='o')s1[i+1]='*';
			else s1[i+1]='o';
		}
	}
	cout<<ans;
	return 0;
}