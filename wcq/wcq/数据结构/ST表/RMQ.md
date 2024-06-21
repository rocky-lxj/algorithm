#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
typedef long long ll;
const int N = 1e6 + 7;

// ST表 查询区间最值
// O(nlogn) 建表   O(1)查询
// f[i][j] 记录左端点为i、长度为 2^j 的区间 的最值
// f[i][j] = max(f[i][j-1], f[i+2^(j-1)][j-1])
// 从小区间开始枚举（j在外层循环）
unsigned int A, B, C, a[N], f[N][22], ans;
int n, q, lg[N];
unsigned int rng61() {
	A ^= A << 16;
	A ^= A >> 5;
	A ^= A << 1;
	unsigned int t = A;
	A = B;
	B = C;
	C ^= t ^ A;
	return C;
}
void solve() {
	cin >> n >> q >> A >> B >> C;
	for (int i = 1; i <= n; i++) {
		a[i] = rng61();
		f[i][0] = a[i];
	}
	//枚举j
	for (int j = 1; j <= 20; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
	// 预处理位数
	lg[1] = 0;
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i / 2] + 1;

	for (int i = 1; i <= q; i++) {
		unsigned int l = rng61() % n + 1, r = rng61() % n + 1;
		if (l > r) swap(l, r);
		// 找到最大的 len 满足 2^len <= r - l + 1
		// 或者直接用(都是整数，2下取整) __lg(r-l+1)     (都是浮点数)log2()
		int len = lg[r - l + 1];
		ans ^= max(f[l][len], f[r - (1 << len) + 1][len]);
	}
	cout << ans;
}

int main() {

	solve();

	return 0;
}
