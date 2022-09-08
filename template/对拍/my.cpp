#include<iostream>
#define end "\n"
using namespace std;
template<class T>
class SegmentTree {
private:
	T* a;  //a是原数组，下标从1开始
	T* sum;//sum维护区间和
	T* lazy;//lazy为懒标记
	int length;
public:
	SegmentTree()
		:sum(nullptr), lazy(nullptr), length(0)
	{}
	SegmentTree(const T* tar,int size) :length(size << 2 | 1) { //开四倍内存
		sum = new T[size << 2 | 1];
		lazy = new T[size << 2 | 1];
		a = new T[size+1];
		for (int i = 1; i <= size; ++i) a[i] = tar[i];
		for (int i = 0; i <= length; ++i) sum[i] = 0, lazy[i] = 0;
	}
	void build(int root, int l, int r);//在区间l到r之间建树，根节点为root
	void pushdown(int root);
	void pushup(int root, int l, int r);
	void update(int root, int l, int r, int x, int y, T k);
	//当前区间的编号是root，当前区间为l到r,需要增值的区间为x到y，增加的值是k
	T ask(int root, int l, int r, int x, int y);
	//当前区间的编号是root，当前区间为l到r，需要查询的区间是x到y
	~SegmentTree() {
		delete[]sum;
		delete[]a;
		delete[]lazy;
	}
};
template<class T>
void SegmentTree<T>::build(int root, int l, int r) {
	if (l == r) {
		sum[root] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(root << 1, l, mid);
	build(root << 1 | 1, mid + 1, r);
	sum[root] = sum[root << 1] + sum[root << 1 | 1];
}
template<class T>
inline void SegmentTree<T>::pushdown(int root) {
	if (lazy[root] != 0) {
		lazy[root << 1] += lazy[root];
		lazy[root << 1 | 1] += lazy[root];
		lazy[root] = 0;
	}
}
template<class T>
inline void SegmentTree<T>::pushup(int root,int l,int r) {
	int mid = (l + r) >> 1;
	sum[root] = sum[root << 1] + lazy[root << 1] * (mid - l + 1) + sum[root << 1 | 1] + lazy[root << 1 | 1] * (r - mid);
}
template<class T>
void SegmentTree<T>::update(int root, int l, int r, int x, int y, T k) {
	if (l == x && r == y) {
		lazy[root] += k;
		return;
	}
	pushdown(root);//标记下传
	int mid = (l + r) >> 1;
	if (y <= mid) {
		update(root << 1, l, mid, x, y, k);
	}
	else {
		if (x > mid) {
			update(root << 1 | 1, mid + 1, r, x, y, k);
		}
		else {
			update(root << 1, l, mid, x, mid, k);
			update(root << 1 | 1, mid + 1, r, mid + 1, y, k);
		}
	}
	pushup(root, l, r);//标记上传
}
template<class T>
T SegmentTree<T>::ask(int root, int l, int r, int x, int y) {
	if (l == x && r == y) {
		return sum[root] + lazy[root] * (r - l + 1);
	}
	pushdown(root);//标记下传
	T s = 0;
	int mid = (l + r) >> 1;
	if (y <= mid) {
		s = ask(root << 1, l, mid, x, y);
	}
	else {
		if (x > mid) {
			s = ask(root << 1 | 1, mid + 1, r, x, y);
		}
		else {
			s = ask(root << 1, l, mid, x, mid) + ask(root << 1 | 1, mid + 1, r, mid + 1, y);
		}
	}
	pushup(root, l, r);//标记上传
	return s;
}
int tar[101];
int main()
{
	int m=0,sign=0,l=0,r=0,k=0;
	cin >> m;
	for(int i=1;i<=100;++i) cin >> tar[i];
	SegmentTree<int>seg(tar,100);
	seg.build(1,1,100);
	for(int i=1;i<=m;++i){
		cin >> sign;
		if(sign==1){
			cin >> l >> r >> k;
			seg.update(1,1,100,l,r,k);
		}else if(sign==2){
			cin >> l >> r;
			cout << seg.ask(1,1,100,l,r) << endl;
		}
	}
	return 0;
}