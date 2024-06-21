#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
typedef long long ll;
const int N = 5e3 + 7, M = 1e4 + 7;

// 点到点 O(nm)

struct Edge {
	int x, y, v;

} edge[M]; // 存边
int n, m, k, dist[N], pre[N], c[N];// pre 路径映射数组，  c 实际t到s的数组(所以需要倒序输出c数组)

int shortpath(int s, int t) {
	memset(dist, 127, sizeof(dist));  // 无穷远
	memset(pre, 0, sizeof(pre));
	pre[s] = -1;
	dist[s] = 0; // 某一点距离 开始点s 最短的距离
	while (true) {
		bool ok = false; // 是否有点的最短距离被更新， 有的话继续循环
		rep(i, 1, m) { // 第一次一定会找到 dist[s],所以不用在意起始的元素
			int x = edge[i].x, y = edge[i].y, v = edge[i].v;
			if (dist[x] < 1 << 30) // 这个点通路的时候
				if (dist[x] + v < dist[y]) {
					dist[y] = dist[x] +  v;
					pre[y] = x; // y点到s最短路的上一节点是x
					ok = true;
				}
		}
		if (!ok)
			break;
	}
	if (dist[t] < 1 << 30) {
		// 路径输出
		int len = 0;
		for(int i = t; i != -1; i = pre[i])
			c[++len] = i;
		cout << "路径：";
		per(i, len, 1)
			cout << c[i] << " ";
		cout << endl << "最短路长度：";	
		//
		return dist[t];
	}	
	else
		return -1;
}
void solve() {
	cin >> n >> m >> k;

​	rep(i, 1, m)
​		cin >> edge[i].x >> edge[i].y >> edge[i].v;
​	while (k--) {
​		int x, y;
​		cin >> x >> y;
​		cout << shortpath(x, y) << endl;
​	}

}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

​	solve();

​	return 0;

}