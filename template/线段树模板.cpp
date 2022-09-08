//线段树第一次学的模板

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 500001;
struct TREE {
	int l, r, sum;
	int tagp,tagm;
}tree[maxn * 4];
int ans;
int a[maxn];
int p;
//建树
void build(int i, int l, int r) {
	tree[i].l = l;
	tree[i].r = r;
	tree[i].tagm = 1;
	if (l == r) {
		tree[i].sum = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, i << 1);
	build(mid + 1, r, i << 1 | 1);
	tree[i].sum = (tree[i << 1].sum + tree[i << 1 | 1].sum) % p;
}
//x位加一个k
void add(int i, int x, int k) {
	if (tree[i].l == tree[i].r) {
		tree[i].sum += k;
		return;
	}
	int mid = (tree[i].l + tree[i].r) >> 1;
	if (x <= mid) add(i * 2, x, k);
	else add(i * 2 + 1, x, k);
	tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
}
//查询l到r的区间和
int ask(int i, int l, int r) {
	if (tree[i].l >= l && tree[i].r <= r) {
		return tree[i].sum;
	}
	int s = 0;
	if (tree[i * 2].r >= l) s += ask(i * 2, l, r);
	if (tree[i * 2 + 1].l <= r) s += ask(i * 2 + 1, l, r);
	return s;
}
//区间l到r加上k
void add2(int i, int l, int r, int k) {
	if (tree[i].l >= l && tree[i].r <= r) {
		tree[i].tagp += k;
		return;
	}
	if (tree[i * 2].r >= l) add2(i * 2, l, r, k);
	if (tree[i * 2 + 1].l <= r) add2(i * 2 + 1, l, r, k);
}
//查询
void ask2(int i, int x) {
	ans += tree[i].tagp;
	if (tree[i].l == tree[i].r) return;
	if (tree[i * 2].r >= x) ask2(i * 2, x);
	if (tree[i * 2 + 1].l <= x) ask2(i * 2 + 1, x);
}
//区间加下传标记
void pushdown(int i) {
	tree[i * 2].sum += tree[i].tagp * (tree[i * 2].r - tree[i * 2].l + 1);
	tree[i * 2 + 1].sum += tree[i].tagp * (tree[i * 2 + 1].r - tree[i * 2 + 1].l + 1);
	tree[i * 2].tagp += tree[i].tagp;
	tree[i * 2 + 1].tagp += tree[i].tagp;
	tree[i].tagp = 0;
}
//区间乘和加下传标记
void pushdown2(int i) {
	int mul = tree[i].tagm, plus = tree[i].tagp;
	tree[i << 1].sum = (tree[i << 1].sum * mul + plus * (tree[i << 1].r - tree[i << 1].l + 1)) % p;
	tree[i << 1 | 1].sum = (tree[i << 1 | 1].sum * mul + plus * (tree[i << 1 | 1].r - tree[i << 1 | 1].l + 1)) % p;
	tree[i << 1].tagm = tree[i << 1].tagm * mul % p;
	tree[i << 1 | 1].tagm = tree[i << 1 | 1].tagm * mul % p;
	tree[i << 1].tagp = (tree[i << 1].tagp * mul + plus) % p;
	tree[i << 1 | 1].tagp = (tree[i << 1 | 1].tagp * mul + plus) % p;
	tree[i].tagp = 0;
	tree[i].tagm = 1;
}
//区间l到r加上k
void add3(int i, int l, int r, int k) {
	if (tree[i].l >= l && tree[i].r <= r) {
		tree[i].tagp += k;
		tree[i].sum += k * (tree[i].r - tree[i].l + 1);
		return;
	}
	pushdown(i);
	if (tree[i * 2].r >= l) add3(i * 2, l, r, k);
	if (tree[i * 2 + 1].l <= r) add3(i * 2 + 1, l, r, k);
	tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
}
//查询l到r的区间和
int ask3(int i, int l, int r) {
	if (tree[i].l >= l && tree[i].r <= r) {
		return tree[i].sum;
	}
	pushdown(i);
	int s = 0;
	if (tree[i * 2].r >= l) s += ask3(i * 2, l, r);
	if (tree[i * 2 + 1].l <= r) s += ask3(i * 2 + 1, l, r);
	return s;
}
//区间乘
void multiple(int i, int l, int r, int k) {
	if (tree[i].l >= l && tree[i].r <= r) {
		tree[i].tagm = (tree[i].tagm * k) % p;
		tree[i].tagp = (tree[i].tagp * k) % p;
		tree[i].sum = (tree[i].sum * k) % p;
		return;
	}
	pushdown2(i);
	if (tree[i << 1].r >= l) multiple(i << 1, l, r, k);
	if (tree[i << 1 | 1].l <= r) multiple(i << 1 | 1, l, r, k);
	tree[i].sum = (tree[i << 1].sum + tree[i << 1 | 1].sum) % p;
}
signed main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	
	return 0;
}