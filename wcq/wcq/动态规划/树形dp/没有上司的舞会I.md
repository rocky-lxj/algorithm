#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
typedef long long ll;
const int N = 1e4 + 7;

// dp[i][0]   �� i ���˲��μӵ������
// dp[i][1]   �� i ���˲μӵ������
// ���  dp�� �ĺ�
int n, v[N], root[N], dp[N][2];
vector<vector<int> > son(N);

void dfs(int l) {
	dp[l][1] = v[l];
	for (auto x : son[l]) {
		dfs(x);
		dp[l][0] += max(dp[x][0], dp[x][1]);
		dp[l][1] += dp[x][0];
	}
}
void solve() {
	cin >> n;
	rep(i, 1, n) {
		// root[i]   1��ʾ�Ǹ��ڵ�
		root[i] = 1;
		cin >> v[i];
	}
	rep(i, 1, n) {
		int l, k;
		cin >> l >> k;
		root[l] = 0;
		son[k].push_back(l);
	}

	// �ݹ鿼��
	int ans = 0;
	rep(i, 1, n) {
		if(root[i]) {
			dfs(i);
			ans += max(dp[i][0], dp[i][1]);
		}
	}
	
	cout << ans << endl;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	solve();

	return 0;
}
