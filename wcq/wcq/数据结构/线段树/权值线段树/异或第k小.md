#include<bits/stdc++.h>
using namespace std;
#define y1 abbbbb
using ll = long long;
const int N = 2e5 + 7;
const int M = 30;
// 对于求第k小， 先假设最高位（然后次高位...）是0（为了尽可能小，再从小一点点逼近k），如果存在分支，并且分支里的总个数少于k，则说明
// 第k小的最高位是1。如果不存在分支，只能是另一个分支

// 1是根节点
struct nd {
	int son[2];
	int sz;
} seg[N  * 32];
int tot = 0, root;
int n, m, a[N];


int main() {
	cin >> n >> m;
	// 建立二进制字典树， 根是最高位
	root = ++tot;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		int p = root;
		for (int j = M - 1; j >= 0; j--) {
			seg[p].sz++;
			int w = (x >> j) & 1;
			// 如果没有节点就新建
			if (seg[p].son[w] == 0)
				seg[p].son[w] = ++tot;
			p = seg[p].son[w];
		}
		// 最后的左儿子或者右儿子
		seg[p].sz++;
	}
	// 询问
	for (int i = 1; i <= m; i++) {
		int x, k;
		scanf("%d%d", &x, &k);
		int p = root;
		int ans = 0;
		for (int j = M - 1; j >= 0; j--) {
			// 为了先考虑最高位是0，所以在异或情况下，要走和x一样数值的分支(w)，xor才会是0
			int w = (x >> j) & 1;
			if (seg[seg[p].son[w]].sz >= k) {
				p = seg[p].son[w];
			} else { // 没有这个分支或者另有一个不够||说明最高位是1，要加上去(^也可以，更快)
				k -= seg[seg[p].son[w]].sz;
				ans ^= 1 << j;
				p = seg[p].son[1 ^ w]; // 取 w 的反方向
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
