#include<bits/stdc++.h>
using namespace std;
#define y1 abbbbb
using ll = long long;
const int N = 2e5 + 7;

// mex ѯ��l-r������Сδ���ֵ����Ƕ���
// Ȩֵ�߶���
// ö���Ҷ˵㣬����Ԫ�����һ�γ��ֵ�λ�� ������С��l����С�±��Ƕ���
int n, q, a[N], ans[N];
vector<pair<int, int>> qu[N];

struct node {
	int val; // �������ֵ
} seg[N * 4];

void update(int id) {
	seg[id].val = min(seg[id * 2].val, seg[id * 2 + 1].val);
}

void change(int id, int l, int r, int pos, int val) {
	if (l == r) {
		seg[id].val = val;
	} else {
		int mid = (l + r) >> 1;
		if (pos <= mid) // ȫ������
			change(id * 2, l, mid, pos, val);
		else // ȫ���Ұ��
			change(id * 2 + 1, mid + 1, r, pos, val);
		// ���µ�ǰ�������ֵ
		update(id);
	}
}
// ��ѯ ������ڵ���d�ĵ�һ��Ԫ���±�
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
	// ö���Ҷ˵�
	for (int r = 1; r <= n; r++) {
		// a[r]���һ�γ�����λ�� r
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
