#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
typedef long long ll;
const int N = 2e5 + 7;

int n, dp[N];
// v[i]   i号上司的团队人数
vector<vector<int> > v(N);
void dfs(int l) {
	dp[l] = 1;		
	for(auto x : v[l]) {
		dfs(x);
		dp[l] += dp[x];
	}
}
void solve() {
	cin >> n;
	rep(i, 2, n) {
		int x;
		cin >> x;
		v[x].push_back(i);		
	}
	//
	dfs(1);
	rep(i, 1, n) {
		cout << dp[i] << " ";
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	solve();
	
	return 0;
}
