#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
typedef long long ll;
const int N = 1e3 + 7;

int n, a[N], sum[N], dp[N][N];
void solve() {
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	// 无穷大
	memset(dp, 127, sizeof dp);
	// 只有一堆，合并代价为 0
	rep(i, 1, n) {
		dp[i][i] = 0;
	}
	// dp n^3
	// i: 从小开始枚举区间长度(i用r-l表示, 方便书写)
	rep(i, 1, n - 1) {
		// j: 区间左端点
		// 区间右端点： j + i
		rep(j, 1, n - i) {
			// k：枚举分界线
			// j-k为一堆， k+1--j+i为一堆
			rep(k, j, j + i - 1) {
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum[j + i] - sum[j - 1]);
			}
		}
	}
	cout << dp[1][n] << "\n";
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	solve();

	return 0;
}
