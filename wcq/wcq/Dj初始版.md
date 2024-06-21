/* Dijkstra
维护
	dist[x] 起点 S 到 点 x 的最短路（相当于一次(s,t)的ford之后的 dist[t]）
	set c[i] 把找到最短路的顶点放入集合c中
算法流程
	将 c 置空， 到 S 距离为 0， 其余顶点距离无穷大；
	在每一轮中（第一轮是把　Ｓ　加入到ｃ中），将离起点最近的（即dist最小的，且不能是无穷大）的还不在集合c
		中的顶点加入到c中，然后用这个点连出去的边（只对直接连接到这个点的边操作，间接连接的边不操作）通过松弛操作更新集合c以外
		的点（直接相邻的点）的dist；（一轮操作后，集合ｃ外的、且距离最短的那个点一定符合进入ｃ的需求，此时的）
	当 T (如果存在的话) 或者没有新的点（点的距离无穷大或者没有 Ｔ）加入集合c时， 算法结束。

	时间复杂度：n * n + m;
	无负权
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
typedef long long ll;
const int N = 2e5 + 7;
struct node {
	int y, v;
	node(int _y, int _v) {
		y = _y;
		v = _v;
	}; // 直接传参，赋值更快 构造函数
};
vector<node> edge[N]; // 每个点连接的所有点 不等价于边。因为Dj每次是以点为主导去遍历它的临边、临点，单个的edge[i]没有保存完整的图。
int n, m, dist[N]; // 点， 边， 最短路(对于一个测试数据， dist数组不用中间清空， 他一直在进行迭代赋值，最后时刻完成题目要求)
bool b[N]; // 模拟集合， 保存 点i 是否在集合中 （该集合中每个点的性质为， dist为最终的最短距离， 无法再更新）

int Dj(int s, int t) {
	memset(b, false, sizeof(b)); // 一开始空
	memset(dist, 127, sizeof(dist)); // 一开始 无穷大
	dist[s] = 0;
	while (true) {
		int p = 0; // 距离起点 S 最近的点的编号（1 -- n）（dist最小），初始为 0(-1,-2,-12...)
		rep(i, 1, n) { // 求不在集合中、不是无穷远、并且距离起点 S 最近的点编号
			if (!b[i] && dist[i] < 1 << 30) // 点不在集合中，并且不是无穷远(那么一开始只有 S 点满足)
				if (p == 0 || dist[p] < dist[i])
					p = i;
		}
		if( p == t || p == 0) // 找到 t，或者,当所有能加入集合的点都在集合中时，上面的循环不会进行，导致 p 还为初始的 0（则表示集合外面的点,从 S 无法到达）
			break;
		b[p] = true;// 加入集合
		

​		for(auto i : edge[p]) // 对p点的所有临点进行松弛操作
​			dist[i.y] = min(dist[i.y], dist[p] + dist[i.v]);

​	}
​	return dist[t];

}
void solve() {
	cin >> n;


}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

​	solve();

​	return 0;

}