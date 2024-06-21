#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
typedef long long ll;
const int N = 2e5 + 7;

// exKMP 算法
int n, f[N];
void solve() {
	string s, p;
	cin >> s >> p;
	int n = s.size();
	int m = p.size();
	string add = " " + p + "#" + s;
	// 初始化区间
	int l = 1, r = 0;
	f[1] = 0;
	for (int i = 2; i <= m + 1 + n; ++i) {
		// 根据先前位 尽可能的推导
		if (i > r)
			f[i] = 0;
		else {
			int k = i - l + 1;
			f[i] = min(f[k], r - i + 1);
		}
		// 再暴力向后匹配
		while (i + f[i] <= m + 1 + n && add[i + f[i]] == add[f[i] + 1])
			++f[i];
		// 更新 l r 区间
		if (i + f[i] - 1 > r) {
			l = i;
			r = i + f[i] - 1;
		}
	}
	int ans = 0;
	for (int i = m + 2; i <= n + m + 1; ++i)
		if (f[i] == m)
			ans++;
	if(!ans)
		printf("-1\n-1\n");
	else {
		printf("%d\n", ans);
		for(int i = m + 2; i <= n + m + 1; ++i)
			if(f[i] == m)
				printf("%d ", i - m - 1);
		printf("\n");
	}
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		solve();

​	}

​	return 0;

}