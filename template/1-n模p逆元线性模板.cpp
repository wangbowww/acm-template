//1-n逆元线性模板  (mod p)

#include<bits/stdc++.h>
using namespace std;
int inv[3000005];
int main()
{
	int n,p;
	cin >> n >> p;
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		inv[i] = (long long)(p - p / i) * inv[p % i] % p;
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",inv[i]);
	}
	return 0;
}
