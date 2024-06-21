#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
const int M = 3e5+7;
#define ll long long
#define en '\n'
#define debug cout<<"------"
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define eb emplace_back
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int dx[]= {1,-1,0,0,1,1,-1,-1};
int dy[]= {0,0,1,-1,1,-1,1,-1};
inline ll read() {
	char c = getchar();
	ll x = 0,s = 1;
	while(c < '0' || c > '9') {
		if(c == '-') s = -1;    //是符号
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x*10 + c -'0';    //是数字
		c = getchar();
	}
	return x*s;
}
inline void write(ll x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x/10);
	putchar('0'+x%10);
}
bool isprime(ll x) {
	if(x<2||(x%2==0&&x>2))return 0;
	for(ll i=3; i<=x/i; i+=2)if(x%i==0)return 0;
	return 1;
}
ll qsm(ll x,ll y) {
	ll ans=1;
	while(y) {
		if(y&1)ans=ans*x;
		x=x*x;
		y>>=1;
	}
	return ans;
}
ll lcm(ll x,ll y)
{
	return x/__gcd(x,y)*y;
}
void solve() {

}
int main() {
	//fast
	int t;
	t=1;
	//cin>>t;
	while(t--) {
		solve();
		cout<<en;
	}
}

