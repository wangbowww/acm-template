//01背包

#include<bits/stdc++.h>
#define int long long
using namespace std;
int m, v[1009], w[1009];
int n;
int f[1009];//容量为i时的最大价值
signed main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
	for (int i = 0; i < n; i++) {
		for (int j = m; j >= w[i];j--) {
			f[j] = max(f[j], f[j - w[i]]+v[i]);
		}
	}
	cout << f[m];
	return 0;
}