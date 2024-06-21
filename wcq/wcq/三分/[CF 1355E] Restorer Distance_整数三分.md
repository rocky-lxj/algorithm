#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
typedef long long ll;
const int N = 2e5 + 7;

ll n, a, r, m, c[N];
ll f(ll x) {
	ll cnt1 = 0, cnt2 = 0;
	rep(i, 1, n) {
		if (x >= c[i])
			cnt1 += x - c[i];
		else
			cnt2 += c[i] - x;
	}
	return m * min(cnt1, cnt2) + (cnt1 > cnt2 ? a : r) * abs(cnt1 - cnt2);
}
void solve() {
	cin >> n >> a >> r >> m;
	rep(i, 1, n) {
		cin >> c[i];
	}
	m = min(m, a + r); 
	//
	ll L = 0, R = 1e9;
	// 注意结束条件！！！
	while (L + 2 < R) {
		ll m1 = L + (R - L) / 3;
		ll m2 = L + (R - L) / 3 * 2;
		if (f(m1) > f(m2))
			L = m1;
		else
			R = m2;
	}
	// 答案需要枚举  
	// 注意左移！！！ 要写成 1LL !!!
	ll ans = 1LL << 62;
	rep(i, L, R) {
		ans = min(ans, f(i));
	}
	cout << ans << "\n";
}

int main() {

	solve();

	return 0;
}
