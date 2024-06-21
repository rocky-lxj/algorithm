/* Dijkstra
维护
	dist[x] 起点 S 到 点 x 的最短路（相当于一次(s,t)的ford之后的 dist[t]）
	set c[i] 把找到最短路的顶点放入集合c中
算法流程
	将 c 置空， 到 S 距离为 0， 其余顶点距离无穷大；
	在每一轮中（第一轮是把　Ｓ　加入到ｃ中），将离起点最近的（即dist最小的，且不能是无穷大）的还不在集合c
	中的顶点加入到c中，然后用这个点连出去的边（只对直接连接到这个点的边操作，间接连接的边不操作）通过松弛操作更新集合c以	   	外的点（直接相邻的点）的dist；（一轮操作后，集合ｃ外的、且距离最短的那个点一定符合进入ｃ的需求，此时的）
	当 T (如果存在的话) 或者没有新的点（点的距离无穷大或者没有 Ｔ）加入集合c时， 算法结束。

时间复杂度：n * n + m; 点比较少时，用这个 1000

堆优化：	(n+m)log n; 点多的时， 用这个 100000

*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
typedef long long ll;
const int N = 2e5 + 7;
struct node {
	int y, v; // 点编号  权值
	node(int _y, int _v) {
		y = _y;
		v = _v;
	}; // 直接传参，赋值更快 构造函数
};
//
set<pair<int, int>> q; // 该点的dist,和点编号。// 升序集合，首元素最小， 保存不在 集合b 中的点编号（b集合中每个点的性质为， dist为最终的最短距离， 无法再更新）
vector<node> edge[N]; // 每个点连接的所有点 不等价于边。因为Dj每次是以点为主导去遍历它的临边、临点，单个的edge[i]没有保存完整的图。
int n, m, dist[N]; // 点， 边， 最短路(对于一个测试数据， dist数组不用中间清空， 他一直在进行迭代赋值，最后时刻完成题目要求)

int Dj(int s, int t) {
	memset(dist, 127, sizeof(dist)); // 一开始 无穷大
	dist[s] = 0;
	q.clear();
	rep(i, 1, n) // 初始化， 把所有的点放入q中，即假设集合b为空，没有点距离最短
		q.insert(make_pair(dist[i], i)); // log n
	while(!q.empty()) {
		int p = q.begin()->second; // p 为到 S 最短的点 (set降低时间复杂度)
		q.erase(q.begin()); // log n
		if(p == t || dist[p] > 1 << 30) // 找到 t,或者,最小的那个点的dist为无穷大，说明 p和q集合内的点 再也不可能与 S 有通路，后续也就不需要松弛操作了，break
			break;
		//此时还未结束循环，说明出去的点p进入了集合b，可以进行松弛操作
		for(auto i : edge[p]) {
			if(dist[p] + dist[i.v] < dist[i.y]) { // set容器修改元素数值，要先把原来的删除，再添加修改之后的元素
				q.erase(make_pair(dist[i.y], i.y));
				dist[i.y] = dist[p] + dist[i.v];
				q.insert(make_pair(dist[i.y], i.y));
			}
		}		
	}
	return dist[t];
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