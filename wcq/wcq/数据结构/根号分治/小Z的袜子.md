#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
typedef long long ll;
const int N = 2e5 + 7;

// Ī��  n��n
// ���� ��ѯ�ʰ���l�ֿ�����
// ����Nֻ���ӵ���ɫ���У� m��ѯ��lr������������ѡ��2ֻ��ͬ��ɫ���ӵĸ���
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
		ans2[i] = (ll)(r - l) * (r - l + 1) / 2; // ��ĸ�����еĿ���ѡ��,��Ϊ0!!!
	    ans2[i] = max(ans2[i], 1LL); // ��Ȼ__gcd�����
	}
	int B = 500;
	// �Ȱ���l���ڷֿ����������ٰ���r��������
	sort(que, que + q, [&](array<int, 3> a, array<int, 3> b) {
		if (a[0] / B != b[0] / B) return a[0] / B < b[0] / B;
		return a[1] < b[1];
	});
	// �Ż� l���������Ҷ˵㽵��l��ż�����Ҷ˵����� ��֮�Ҷ˵�Ҫ����������
	// ��l���е�ѯ������󣬴�ʱ�Ҷ˵㿿�ң���ôl+1���Ҷ˵�Ӧ�ôӴ�С������
	// �Ա����r���ƶ�����     
//	sort(que, que + q, [&](array<int, 3> a, array<int, 3> b) {
//		int c = a[0] / B;
//		if (c != b[0] / B) return c < b[0] / B;
//		return c % 2 ? a[1] > b[1] : a[1] < b[1];
//	});
	// ������
	int l = 1, r = 0;
	// cnt++֮ǰ ԭ����x����ͬ�����ӣ� ԭ������ѡ�������tmp
	// ��ô���ھ���x+1���ܵ�ѡ����� �Ͷ��� x�� 
	auto add = [&] (int x) {
		tmp += cnt[c[x]];
		cnt[c[x]]++;
	}; 
	// ԭ����x����ͬ�����ӣ� ��һֻ���ӣ����������� x-1
	auto del = [&] (int x) {
		cnt[c[x]]--;
		tmp -= cnt[c[x]];
	};
	// 
	for (int i = 1; i <= q; i++) {
		// �������С�ˣ���������
		while (r < que[i][1]) r++, add(r);
		while (l > que[i][0]) l--, add(l);
		// ���������ˣ���С����
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
