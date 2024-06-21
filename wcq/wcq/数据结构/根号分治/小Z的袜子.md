#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
typedef long long ll;
const int N = 2e5 + 7;

// 莫队  n√n
// 离线 对询问按照l分块排序
// 给出N只袜子的颜色序列， m次询问lr，求在区间里选中2只相同颜色袜子的概率
int n, q, c[N], cnt[N];
ll tmp, ans[N], ans2[N];
array<int, 3> que[N];

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		que[i] = {l, r, i};
		ans2[i] = (ll)(r - l) * (r - l + 1) / 2; // 分母，所有的可能选择,不为0!!!
	    ans2[i] = max(ans2[i], 1LL); // 不然__gcd会出错
	}
	int B = 500;
	// 先按照l所在分块升序排序，再按照r升序排序
	sort(que, que + q, [&](array<int, 3> a, array<int, 3> b) {
		if (a[0] / B != b[0] / B) return a[0] / B < b[0] / B;
		return a[1] < b[1];
	});
	// 优化 l在奇数块右端点降序，l在偶数块右端点升序 总之右端点要交替升降序
	// 在l所有的询问做完后，此时右端点靠右，那么l+1的右端点应该从大到小遍历，
	// 以便减少r的移动次数     
//	sort(que, que + q, [&](array<int, 3> a, array<int, 3> b) {
//		int c = a[0] / B;
//		if (c != b[0] / B) return c < b[0] / B;
//		return c % 2 ? a[1] > b[1] : a[1] < b[1];
//	});
	// 空区间
	int l = 1, r = 0;
	// cnt++之前 原来有x个相同的袜子， 原来的总选择个数是tmp
	// 那么现在就是x+1，总的选择个数 就多了 x个 
	auto add = [&] (int x) {
		tmp += cnt[c[x]];
		cnt[c[x]]++;
	}; 
	// 原来有x个相同的袜子， 少一只袜子，总数就少了 x-1
	auto del = [&] (int x) {
		cnt[c[x]]--;
		tmp -= cnt[c[x]];
	};
	// 
	for (int i = 1; i <= q; i++) {
		// 如果区间小了，扩大区间
		while (r < que[i][1]) r++, add(r);
		while (l > que[i][0]) l--, add(l);
		// 如果区间大了，缩小区间
		while (r > que[i][1]) del(r), r--;
		while (l < que[i][0]) del(l), l++;
		ans[que[i][2]] = tmp;
	}
	for (int i = 1; i <= q; i++) {
		ll d = __gcd(ans[i], ans2[i]);
		printf("%lld/%lld\n", ans[i] / d, ans2[i] / d);
	}

	return 0;
}
