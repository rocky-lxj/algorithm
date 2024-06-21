#include<bits/stdc++.h>
using namespace std;
#define y1 abbbbb
using ll = long long;
const int N = 2e5 + 7;

// mex 询问l-r区间最小未出现的数是多少
// 权值线段树
// 枚举右端点，更新元素最后一次出现的位置 ，再找小于l的最小下标是多少
int n, q, a[N], ans[N];
vector<pair<int, int>> qu[N];

struct node {
	int val; // 区间最大值
} seg[N * 4];

void update(int id) {
	seg[id].val = min(seg[id * 2].val, seg[id * 2 + 1].val);
}

void change(int id, int l, int r, int pos, int val) {
	if (l == r) {
		seg[id].val = val;
	} else {
		int mid = (l + r) >> 1;
		if (pos <= mid) // 全在左半边
			change(id * 2, l, mid, pos, val);
		else // 全在右半边
			change(id * 2 + 1, mid + 1, r, pos, val);
		// 更新当前区间最大值
		update(id);
	}
}
// 查询 满足大于等于d的第一个元素下标
int search(int id, int l, int r, int d) {
	if (l == r)
		return l;
	int mid = (l + r) >> 1;
	if (seg[id * 2].val < d)
		return search(id * 2, l, mid, d);
	else
		return search(id * 2 + 1, mid + 1, r, d);
}

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = min(a[i], n + 1);
	}
	//
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		qu[r].push_back({l, i});
	}
	// 枚举右端点
	for (int r = 1; r <= n; r++) {
		// a[r]最后一次出现在位置 r
		change(1, 0, n + 1, a[r], r);
		for (auto que : qu[r]) {
			ans[que.second] = search(1, 0, n + 1, que.first);
		}
	}

	for (int i = 1; i <= q; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}
