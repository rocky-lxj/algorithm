#include<bits/stdc++.h>
using namespace std;
#define y1 abbbbb
using ll = long long;
const int N = 2e5 + 7;
const int M = 30;
// �������kС�� �ȼ������λ��Ȼ��θ�λ...����0��Ϊ�˾�����С���ٴ�Сһ���ƽ�k����������ڷ�֧�����ҷ�֧����ܸ�������k����˵��
// ��kС�����λ��1����������ڷ�֧��ֻ������һ����֧

// 1�Ǹ��ڵ�
struct nd {
	int son[2];
	int sz;
} seg[N  * 32];
int tot = 0, root;
int n, m, a[N];


int main() {
	cin >> n >> m;
	// �����������ֵ����� �������λ
	root = ++tot;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		int p = root;
		for (int j = M - 1; j >= 0; j--) {
			seg[p].sz++;
			int w = (x >> j) & 1;
			// ���û�нڵ���½�
			if (seg[p].son[w] == 0)
				seg[p].son[w] = ++tot;
			p = seg[p].son[w];
		}
		// ��������ӻ����Ҷ���
		seg[p].sz++;
	}
	// ѯ��
	for (int i = 1; i <= m; i++) {
		int x, k;
		scanf("%d%d", &x, &k);
		int p = root;
		int ans = 0;
		for (int j = M - 1; j >= 0; j--) {
			// Ϊ���ȿ������λ��0���������������£�Ҫ�ߺ�xһ����ֵ�ķ�֧(w)��xor�Ż���0
			int w = (x >> j) & 1;
			if (seg[seg[p].son[w]].sz >= k) {
				p = seg[p].son[w];
			} else { // û�������֧��������һ������||˵�����λ��1��Ҫ����ȥ(^Ҳ���ԣ�����)
				k -= seg[seg[p].son[w]].sz;
				ans ^= 1 << j;
				p = seg[p].son[1 ^ w]; // ȡ w �ķ�����
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
